#include "reader.h"

#include "flags.h"

void read(char **argv, flags *flag) {
  FILE *f;
  regex_t reg;
  regmatch_t first_index;
  int cnt = 0;
  int str_num = 0;
  int flag_i = flag->i ? (REG_EXTENDED | REG_ICASE) : REG_EXTENDED;

  if (regcomp(&reg, flag->str_reg, flag_i) != 0) {
    if (!flag->s)
      fprintf(stderr, "Invalid regular expression: %s\n", flag->str_reg);
    return;
  }

  f = fopen(argv[optind], "rb");
  if (f != NULL) {
    while (fgets(flag->str, BUFFER, f) != NULL) {
      str_num++;
      int pattern = regexec(&reg, flag->str, 1, &first_index, 0);

      if (flag->v) {
        pattern = !pattern;
      }

      if (pattern == 0) {
        if (flag->c) {
          cnt++;
        } else if (flag->l) {
          printf("%s\n", argv[optind]);
          break;
        } else if (flag->n) {
          if (flag->flag_c) {
            printf("%s:%d:%s", argv[optind], str_num, flag->str);
          } else {
            printf("%d:%s", str_num, flag->str);
          }
          if (flag->str[strlen(flag->str) - 1] != '\n') {
            printf("\n");
          }
        } else if (flag->o) {
          char *p = flag->str;
          while (regexec(&reg, p, 1, &first_index, 0) == 0) {
            if (flag->flag_c) printf("%s:", argv[optind]);
            printf("%.*s\n", (int)(first_index.rm_eo - first_index.rm_so),
                   p + first_index.rm_so);
            p += first_index.rm_eo;
          }
        } else {
          if (flag->flag_c) printf("%s:", argv[optind]);
          printf("%s", flag->str);
          if (flag->str[strlen(flag->str) - 1] != '\n') {
            printf("\n");
          }
        }
      }
    }

    if (flag->c) {
      if (flag->flag_c && !flag->h) printf("%s:", argv[optind]);
      printf("%d\n", flag->v ? (str_num - cnt) : cnt);
    }

    fclose(f);
    regfree(&reg);
  } else {
    regfree(&reg);
    if (!flag->s)
      fprintf(stderr, "grep: %s: No such file or directory\n", argv[optind]);
    return;
  }
}