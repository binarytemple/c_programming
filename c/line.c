/*****************************************************************
 * line.c
 *
 * Copyright 1999, Clark Cooper
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the same terms as Perl.
 *
 * Read a document, a line at a time, from the standard input and report
 * the following parse events:
 *
 *	Start tags
 *	End tags
 *      Text
 *	Processing instructions
 */

#include <expat.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

int Eventcnt = 0;
char Buff[512];

void default_hndl(void *data, const char *s, int len) {
	fwrite(s, len, sizeof(char), stdout);
} /* End default_hndl */

/****************************************************************
 ** Call from within a handler to print the currently recognized
 ** document fragment. Temporarily set the default handler and then
 ** invoke it via the the XML_DefaultCurrent call.
 */
void printcurrent(XML_Parser p) {
	XML_SetDefaultHandler(p, default_hndl);
	XML_DefaultCurrent(p);
	XML_SetDefaultHandler(p, (XML_DefaultHandler) 0);
} /* End printcurrent */

void start_hndl(void *data, const char *el, const char **attr) {
	printf("\n%4d: Start tag %s - ", Eventcnt++, el);

	printcurrent((XML_Parser) data);
} /* End of start_hndl */

void end_hndl(void *data, const char *el) {
	printf("\n%4d: End tag %s -\n", Eventcnt++, el);
} /* End of end_hndl */

void char_hndl(void *data, const char *txt, int txtlen) {
	printf("\n%4d: Text - ", Eventcnt++);
	fwrite(txt, txtlen, sizeof(char), stdout);
} /* End char_hndl */

void proc_hndl(void *data, const char *target, const char *pidata) {
	printf("\n%4d: Processing Instruction - ", Eventcnt++);
	printcurrent((XML_Parser) data);
} /* End proc_hndl */

int main(int argc, char **argv) {

//	int res = isatty(fileno( stdin));
//
//	if(!res){
//		fprintf(stderr, "Must provide input document on stdin\n");
//		exit(1);
//	}

	XML_Parser p = XML_ParserCreate(NULL);
	if (!p) {
		fprintf(stderr, "Couldn't allocate memory for parser\n");
		exit(-1);
	}




	XML_UseParserAsHandlerArg(p);
	XML_SetElementHandler(p, start_hndl, end_hndl);
	XML_SetCharacterDataHandler(p, char_hndl);
	XML_SetProcessingInstructionHandler(p, proc_hndl);

	/* Notice that the default handler is not set at this point */

	for (;;) {
		int done;
		int len;
		fgets(Buff, sizeof(Buff), stdin);





		len = strlen(Buff);
		if (ferror(stdin)) {
			fprintf(stderr, "Read error\n");
			exit(-1);
		}
		done = feof(stdin);
		if (XML_Parse(p, Buff, len, done) != XML_STATUS_OK) {
			fprintf(stderr, "Parse error at line %lu :\n %s \n",
					XML_GetCurrentLineNumber(p), XML_ErrorString(
							XML_GetErrorCode(p)));
			exit(-1);
		}

		if (done)
			break;
	}
	printf("\n");
	return 0;
} /* End main */
