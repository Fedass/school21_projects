#include "reader.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "config.h"

void read_file(char *filename, config *conf, int *line_cnt, int *last_line) {
  FILE *f = fopen(filename, "r");
  if (f) {
    int curr;
    int prev = '\n';
    int blank_lines = 0;

    if (!(*last_line) && *line_cnt > 1) {
      putchar('\n');
    }

    while ((curr = fgetc(f)) != EOF) {
      if (conf->s && curr == '\n' && prev == '\n') {
        blank_lines++;
      } else {
        blank_lines = 0;
      }
      if (blank_lines > 1) {
        continue;
      }

      if ((conf->n && prev == '\n' && !conf->b) ||
          (conf->b && prev == '\n' && curr != '\n')) {
        printf("%6d\t", (*line_cnt)++);
      }

      if (curr == '\n' && conf->e) {
        putchar('$');
      }

      if (conf->t && curr == '\t') {
        printf("^I");
      } else {
        if (conf->v &&
            ((curr < 32 && curr != '\n' && curr != '\t') || curr == 127)) {
          conf_v(&curr);
        } else {
          putchar(curr);
        }
      }

      prev = curr;
    }

    if (prev != '\n') {
      if (conf->e) {
        putchar('$');
      }
    }

    *last_line = (prev == '\n');
    fclose(f);
  } else {
    printf("Error: cannot open file %s\n", filename);
    exit(1);
  }
}

void conf_v(int *curr) {
  if ((*curr >= 0 && *curr <= 31 && *curr != 9 && *curr != 10)) {
    printf("^%c", *curr + 64);
  } else if (*curr == 127) {
    printf("^?");
  } else if (*curr > 126 && *curr < 160) {
    printf("M-^%c", *curr - 128 + 64);
  }
}
