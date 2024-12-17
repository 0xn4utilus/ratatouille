#ifndef WINUTILS_H
#define WINUTILS_H

#include <Print.h>

extern char *text_org;
extern UINT8 x_org;
extern UINT8 y_org;

#define INIT(FONT) INIT_FONT(FONT, PRINT_WIN); PRINT_POS(0, 0); WX_REG = 7; WY_REG = 136; SHOW_WIN
#define PPRINT PRINT_POS(x_org, y_org); Printf(text_org)
#define CLEAR PRINT_POS(x_org, y_org); Printf("                                    "); HIDE_WIN

void print_text_time(const char* text, UINT8 x, UINT8 y, UINT8 time);
void print_text_pos(const char* text, UINT8 x, UINT8 y);
void print_text(const char* text);

#endif