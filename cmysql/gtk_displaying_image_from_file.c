#include <gtk/gtk.h>
#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv) {

	GtkWidget *window;
	GtkWidget *hbox;
	GtkWidget *image;
	GtkStyle *style;
	GtkWidget *event_box;

	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	if (!window)
		printf("No window. Bad!\n");
	style = gtk_widget_get_style(window);

	gtk_signal_connect (GTK_OBJECT (window), "destroy",
			GTK_SIGNAL_FUNC(gtk_main_quit),
			NULL);

	gtk_window_set_title(GTK_WINDOW (window),
			"This window displays an image from a mysql database");



	image = gtk_image_new_from_file("image.png");

	gtk_container_add(GTK_CONTAINER ( window ), image);

	gtk_widget_show(image);

	gtk_widget_show(window);

	gtk_main();
}
