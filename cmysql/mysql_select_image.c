#include <my_global.h>
#include <mysql.h>
#include <string.h>

int populate_data(char * data) {
	MYSQL *conn;
	MYSQL_RES *result;
	MYSQL_ROW row;

	unsigned long *lengths;

	conn = mysql_init(NULL);
	mysql_real_connect(conn, "localhost", "zetcode", "passwd", "testdb", 0,
			NULL, 0);

	mysql_query(conn, "SELECT data FROM images WHERE id=1");
	result = mysql_store_result(conn);

	row = mysql_fetch_row(result);
	lengths = mysql_fetch_lengths(result);

	int length = lengths[0];

	char * res =  realloc(data, length);

	memcpy(data, row[0], length);

	mysql_close(conn);

	mysql_free_result(result);

	return length;
}

int main(int argc, char **argv) {

  char * data = malloc(4);
  int size = populate_data(data);

	/* FILE *fp; */
	/* fp = fopen("image.png", "wb"); */
	/* fwrite(data, size, 1, fp); */

	/* fclose(fp); */

	

}
