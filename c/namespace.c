/*****************************************************************
 * namespace.c
 * 
 * Copyright 1999, Clark Cooper
 * All rights reserved.
 *
 * This program is free software; you can distribute it and/or modify
 * it under the same terms as Perl.
 *
 *================================================================
 *
 * Read an XML document from standard input and print an element outline
 * (but only to depth MAX_INDENT) annotated with namespace scope.
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <expat.h>

#define CHUNK_SIZE 8192
#define MAX_INDENT 30

typedef struct app_data {
  int depth;
  char indent[MAX_INDENT * 2];
} AppData;

void
start(void *data, const char *el, const char **attr) {
  AppData	*ad = (AppData *) data;
  int		i;

  if (ad->depth < MAX_INDENT) {
    char *indent_tail = &ad->indent[ad->depth * 2];

    *indent_tail++ = ' ';
    *indent_tail++ = ' ';
    *indent_tail = '\0';

    printf("%s%s:\n", ad->indent, el);
    for (i = 0; attr[i]; i += 2) {
      printf("%s-Attr: %s = %s\n", ad->indent, attr[i], attr[i + 1]);
    }
  }
  else if (ad->depth == MAX_INDENT) {
    printf ("%s  ****\n", ad->indent);
  }

  ad->depth++;
}  /* End start */

void
end(void *data, const char *el) {
  AppData *ad = (AppData *) data;

  ad->depth--;
  ad->indent[ad->depth * 2] = '\0';
}  /* End end */

void
ns_start(void *data, const char *prefix, const char *uri) {
  AppData *ad = (AppData *) data;

  printf("%s  ++NS %s => %s\n", ad->indent,
	 prefix ? prefix : "(null)",
	 uri ? uri : "(null)");
}  /* End ns_start */

void
ns_end(void *data, const char *prefix) {
  AppData *ad = (AppData *) data;

  printf("%s  --NS %s\n", ad->indent, prefix ? prefix : "(null)");
}  /* End ns_end */

AppData *
newAppData() {
  AppData *ret;
  ret = (AppData *) malloc(sizeof(AppData));
  if (ret == NULL) {
    fprintf(stderr, "Couldn't allocate memory for application data\n");
    exit(-1);
  }

  /* Initialize */
  ret->depth = 0;
  ret->indent[0] = '\0';
}  /* End */

void
main(int argc, char **argv) {
  AppData *ad;
  XML_Parser p = XML_ParserCreateNS(NULL, '|');
  if (! p) {
    fprintf(stderr, "Couldn't allocate memory for parser\n");
    exit(-1);
  }

  ad = newAppData();

  XML_SetUserData(p, (void *) ad);
  XML_SetElementHandler(p, start, end);
  XML_SetNamespaceDeclHandler(p, ns_start, ns_end);

  for (;;) {
    char *buff;
    int len;

    buff = XML_GetBuffer(p, CHUNK_SIZE);
    if (! buff) {
      fprintf(stderr, "Ran out of memory for parse buffer\n");
      exit(-1);
    }

    len = read(0, buff, CHUNK_SIZE);
    if (len < 0) {
      perror("namespace - read error");
      exit(-1);
    }
    
    if (! XML_ParseBuffer(p, len, len == 0)) {
      fprintf(stderr, "Parse error at line %lu :\n%s\n",
	      XML_GetCurrentLineNumber(p),
	      XML_ErrorString(XML_GetErrorCode(p)));
      exit(-1);
    }

    if (len == 0)
      break;
  }
}  /* End main */
