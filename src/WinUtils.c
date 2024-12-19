#include "WinUtils.h"
#include <string.h>

UINT8 len = 0;
UINT8 nlines = 1;

void slice(const char* str, char* result, UINT8 start, UINT8 end) {
    strncpy(result, str + start, end - start);
}

void print_text(char* text) {
    len = strlen(text);
    nlines = (len/20) + 1;

    SHOW_WIN;
    PRINT_POS(0, 0); 
    WX_REG = 7; 
    WY_REG = 144 - (nlines << 3); 

    for(UINT8 i = 0; i<nlines; i++){
        PRINT_POS(0,i);
        char textline[20] = "";
        slice(text, textline, i*20, len < (i+1)*20 ? len: (i+1)*20 );
        Printf(textline);
    }
}


void clear_text(){
    for(UINT8 i = 0; i<nlines; i++){
        PRINT_POS(0,i);
        Printf("                    ");
    }
    HIDE_WIN;
    WX_REG = 20;
    WY_REG= 144;
}

void clear_lines(UINT8 lines){
    for(UINT8 i = 0; i<lines; i++){
        PRINT_POS(0,i);
        Printf("                    ");
    }
    HIDE_WIN;
    WX_REG = 20;
    WY_REG= 144;
}

