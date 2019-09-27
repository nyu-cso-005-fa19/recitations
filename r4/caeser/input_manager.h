#pragma once

#include <stdio.h>

void initialize(int*, char**, char*);

void open_file(FILE**, char**, char*);
void close_file(FILE**);

int read_char_from_file(FILE**);
int write_char_to_file(FILE**, int);