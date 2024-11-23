#include <stdio.h>

#include "parser.h"
#include "reader.h"

int main(int argc, char **argv) {
  flags flag = {0};
  parse_flags(argc, argv, &flag);
  while (optind < argc) {
    read(argv, &flag);
    optind++;
  }

  return 0;
}
