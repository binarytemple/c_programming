#include <gtk/gtk.h>
#include <gio/gio.h>
#include <my_global.h>
#include <mysql.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

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
	unsigned long *lengths;
	FILE *fp;
	struct stat sb;

	fp = fopen("/home/bryan/cmysql/image.png", "rb");

	int fd = fileno(fp);

	fstat(fd, &sb);

	size_t size = sb.st_size;
	printf(" Size - %ld : ", (long unsigned int) size);

	char * data;
	data = malloc(size * sizeof(char));

	size_t read = fread(data, size, 1, fp);

	fclose(fp);







	

	GInputStream * ginput = g_memory_input_stream_new_from_data(data, size,
			NULL);

	GdkPixbuf * pixbuf = gdk_pixbuf_new_from_stream(ginput, NULL, NULL);

	image = gtk_image_new_from_pixbuf(pixbuf);

	gtk_container_add(GTK_CONTAINER ( window ), image);
	gtk_widget_show(image);
gtk_widget_show(window);


	gtk_main();
}
