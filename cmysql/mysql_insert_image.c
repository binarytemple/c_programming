#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{
  MYSQL *conn;

  int len, size;
  char data[1000*1024];
  char chunk[2*1000*1024+1];
  char query[1024*5000];

  FILE *fp;

  conn = mysql_init(NULL);
  mysql_real_connect(conn, "localhost", "zetcode", "passwd", "testdb", 0, NULL, 0);

  fp = fopen("./image.png", "rb");
  size = fread(data, 1, 1024*1000, fp);

  mysql_real_escape_string(conn, chunk, data, size);

  char *stat = "INSERT INTO images(id, data) VALUES('1', '%s')";
  len = snprintf(query, sizeof(stat)+sizeof(chunk) , stat, chunk);

  mysql_real_query(conn, query, len);

  fclose(fp);
  mysql_close(conn);
}

