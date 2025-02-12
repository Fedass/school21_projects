#ifndef READER_H
#define READER_H

#include "config.h"

void read_file(char *filename, config *conf, int *line_cnt, int *last_line);
void conf_v(int *curr);

#endif
