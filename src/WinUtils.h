#ifndef WINUTILS_H
#define WINUTILS_H

#include <Print.h>

extern UINT8 len;
extern UINT8 nlines;

void clear_text();
void clear_lines(UINT8 lines);
void print_text(char* text);

#endif