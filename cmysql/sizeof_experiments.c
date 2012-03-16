/*
 * sizeof_experiments.c
 *
 *  Created on: Mar 15, 2012
 *      Author: bryan
 */

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

	printf("char %d \n",sizeof(char));
	printf("gchar %d \n",sizeof(gchar));
	printf("guint8 %d \n",sizeof(guint8));


}
