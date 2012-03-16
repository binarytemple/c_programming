#include <uuid/uuid.h>
#include <expat.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char **argv) {

  uuid_t out;
  char letters[20] ;

  uuid_generate_random(out);
  uuid_unparse(out,letters);

  fprintf(stdout, "uuid follows\n");
  fprintf(stdout,"%s", letters);


  return 0;
}  

