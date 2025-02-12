#include "parser.h"

#include "flags.h"

void parse_flags(int argc, char **argv, flags *flag) {
  int curr;

  while ((curr = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (curr) {
      case 'e':
        flag->e = 1;
        strcat(flag->str_reg, optarg);
        strcat(flag->str_reg, "|");
        break;

      case 'i':
        flag->i = 1;
        break;

      case 'v':
        flag->v = 1;
        break;

      case 'c':
        flag->c = 1;
        break;

      case 'l':
        flag->l = 1;
        break;

      case 'n':
        flag->n = 1;
        break;

      case 'o':
        flag->o = 1;
        break;

      case 'h':
        flag->h = 1;
        break;

      case 's':
        flag->s = 1;
        break;

      default:
        printf("Unrecognized option\n");
        exit(1);
        break;
    }

    if (flag->v && flag->o) flag->o = 0;
  }
  if (!flag->e) {
    if (argc > optind) strcat(flag->str_reg, argv[optind]);

    optind++;
  }

  if (flag->e) flag->str_reg[strlen(flag->str_reg) - 1] = '\0';

  if (argc - optind > 1) flag->flag_c = 1;
}
