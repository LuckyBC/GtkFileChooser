/*
 Copyright (C) 2017  Lucky B.C
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

int main (int argc, char **argv)
{
	GtkBuilder *builder;
	GtkFileFilter *file_filter;
	GtkFileFilter *image_filter;
	GtkFileFilter *sound_filter;
	GtkFileChooser *window;
	GSList *filters;

	gtk_init (&argc, &argv);

	builder = gtk_builder_new_from_file ("file-chooser.ui");
	if (builder == NULL)
		return 1;

	gtk_builder_connect_signals (builder, NULL);

	window = (GtkFileChooser*) gtk_builder_get_object (builder, "window");
	file_filter = (GtkFileFilter*) gtk_builder_get_object (builder, "file_filter");
	image_filter = (GtkFileFilter *) gtk_builder_get_object (builder, "image_filter");
	sound_filter = (GtkFileFilter *) gtk_builder_get_object (builder, "sound_filter");

	/* We check filters which we added to the file chooser */
	filters = gtk_file_chooser_list_filters (window);
	if (filters == NULL)
		printf ("Beginning we have no filters!!! Why?\n");

	gtk_file_chooser_add_filter (window, file_filter);
	gtk_file_chooser_add_filter (window, image_filter);
	gtk_file_chooser_add_filter (window, sound_filter);
	filters = gtk_file_chooser_list_filters (window);
	if (filters != NULL)
		printf ("Then we have 3 filters!!! Why?\n");

	gtk_file_chooser_remove_filter (window, file_filter);
	gtk_file_chooser_remove_filter (window, image_filter);
	gtk_file_chooser_remove_filter (window, sound_filter);
	filters = gtk_file_chooser_list_filters (window);
	if (filters == NULL)
		printf ("Finally again we have no filters!!! Why?\n");

	gtk_widget_show (GTK_WIDGET (window));
	gtk_main ();

	return 0;
}
