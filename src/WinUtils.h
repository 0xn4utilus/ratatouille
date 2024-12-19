#ifndef WINUTILS_H
#define WINUTILS_H

#include <Print.h>

extern UINT8 len;
extern UINT8 nlines;

extern char dialogues_0[];
extern char dialogues_1[];
extern char dialogues_2[];
extern char dialogues_3[];

void clear_text();
void clear_lines(UINT8 lines);
void print_text(char* text);
void load_dialogues();

#endif