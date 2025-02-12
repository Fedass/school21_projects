#include <stdio.h>

#include "parser.h"
#include "reader.h"

int main(int argc, char **argv) {
  config conf = {0};
  int line_cnt = 1;
  int last_line = 1;

  if (parse_conf(argc, argv, &conf) == 0) {
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        read_file(argv[i], &conf, &line_cnt, &last_line);
      }
    }
  } else {
    printf("Error: invalid arguments\n");
  }

  return 0;
}
