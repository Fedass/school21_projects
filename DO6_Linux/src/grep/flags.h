#ifndef FLAGS_H
#define FLAGS_H
#define BUFFER 10000

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int o;

  char str[BUFFER];
  char str_reg[BUFFER];
  char flag_c;
} flags;

#endif