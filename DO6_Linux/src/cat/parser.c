#include "parser.h"

#include <stdio.h>
#include <string.h>

int parse_conf(int argc, char **argv, config *conf) {
  int err = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && argv[i][1] != '-') {
      int j = 1;
      while (argv[i][j] != '\0') {
        switch (argv[i][j]) {
          case 'b':
            conf->b = 1;
            break;

          case 'e':
            conf->e = 1;
            conf->v = 1;
            break;

          case 'n':
            conf->n = 1;
            break;

          case 's':
            conf->s = 1;
            break;

          case 't':
            conf->t = 1;
            conf->v = 1;
            break;

          case 'T':
            conf->t = 1;
            break;

          case 'E':
            conf->e = 1;
            break;

          case 'v':
            conf->v = 1;
            break;

          default:
            err = 1;
            break;
        }
        j++;
      }
    } else if (argv[i][0] == '-' && argv[i][1] == '-') {
      if (strcmp(argv[i], "--number-nonblank") == 0) {
        conf->b = 1;
      } else if (strcmp(argv[i], "--number") == 0) {
        conf->n = 1;
      } else if (strcmp(argv[i], "--squeeze-blank") == 0) {
        conf->s = 1;
      } else
        err = 1;
    }
  }
  return err;
}
