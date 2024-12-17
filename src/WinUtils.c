#include "WinUtils.h"
#include <string.h>

char *text_org = " ";
UINT8 x_org = 0;
UINT8 y_org = 0;

void print_text_time(const char* text, UINT8 x, UINT8 y, UINT8 time) {
    PRINT_POS(x, y);
    Printf(text);
    for (UINT8 tick = 0; tick < time; tick++) {
        for (UINT8 ticks = 0; ticks < (UINT8)100u; ticks++); 
    }
    CLEAR;
    PPRINT;
}

void print_text_pos(const char* text, UINT8 x, UINT8 y) {
    x_org = x;
    y_org = y;
    text_org = text;
    PPRINT;
}

void print_text(const char* text) {
    SHOW_WIN;
    text_org = text;
    PPRINT;
}