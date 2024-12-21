#include "WinUtils.h"
#include <string.h>
#include <stdint.h>

UINT8 len = 0;
UINT8 nlines = 1;

// BRING PEACH THEN MAYBE I CAN TEACH!!! press select to see your inventory
char  dialogues_0[] ={97, 113, 106, 109, 100, 3, 115, 102, 98, 96, 107, 3, 119, 107, 102, 109, 3, 110, 98, 122, 97, 102, 3, 106, 3, 96, 98, 109, 3, 119, 102, 98, 96, 107, 2, 2, 2, 3, 83, 81, 70, 80, 80, 3, 80, 70, 79, 70, 64, 87, 3, 87, 76, 3, 80, 70, 70, 3, 90, 76, 86, 81, 3, 74, 77, 85, 70, 77, 87, 76, 81, 90,35};
// ONLY PEACH?? EVERYONE KNOWS to bring APPLES with PEACHes!!!
char  dialogues_1[] ={107, 106, 104, 125, 4, 116, 97, 101, 103, 108, 27, 27, 4, 97, 114, 97, 118, 125, 107, 106, 97, 4, 111, 106, 107, 115, 119, 4, 80, 75, 4, 70, 86, 77, 74, 67, 4, 101, 116, 116, 104, 97, 119, 4, 83, 77, 80, 76, 4, 116, 97, 101, 103, 108, 65, 87, 5, 5, 5,36};
// YUMMY APPLE! YUMMY PEACH! ALL I CAN TELL IS TO EXPLORE AREA NEAR CHEESE! if you bring me a mushroom maybe I can teach you something more
char  dialogues_2[] ={124, 112, 104, 104, 124, 5, 100, 117, 117, 105, 96, 4, 5, 124, 112, 104, 104, 124, 5, 117, 96, 100, 102, 109, 4, 5, 100, 105, 105, 5, 108, 5, 102, 100, 107, 5, 113, 96, 105, 105, 5, 108, 118, 5, 113, 106, 5, 96, 125, 117, 105, 106, 119, 96, 5, 100, 119, 96, 100, 5, 107, 96, 100, 119, 5, 102, 109, 96, 96, 118, 96, 4, 5, 76, 67, 5, 92, 74, 80, 5, 71, 87, 76, 75, 66, 5, 72, 64, 5, 68, 5, 72, 80, 86, 77, 87, 74, 74, 72, 5, 72, 68, 92, 71, 64, 5, 108, 5, 70, 68, 75, 5, 81, 64, 68, 70, 77, 5, 92, 74, 80, 5, 86, 74, 72, 64, 81, 77, 76, 75, 66, 5, 72, 74, 87, 64,37};
//YUMMY MUSHROOM!  A good cook knows to bring ingredients in right amount to craft a delicious dish
char  dialogues_3[] = {127, 115, 107, 107, 127, 6, 107, 115, 117, 110, 116, 105, 105, 107, 7, 6, 6, 103, 6, 65, 73, 73, 66, 6, 69, 73, 73, 77, 6, 77, 72, 73, 81, 85, 6, 82, 73, 6, 68, 84, 79, 72, 65, 6, 79, 72, 65, 84, 67, 66, 79, 67, 72, 82, 85, 6, 79, 72, 6, 84, 79, 65, 78, 82, 6, 71, 75, 73, 83, 72, 82, 6, 82, 73, 6, 69, 84, 71, 64, 82, 6, 71, 6, 66, 67, 74, 79, 69, 79, 73, 83, 85, 6, 66, 79, 85, 78,38};

void slice(const char* str, char* result, UINT8 start, UINT8 end) {
    strncpy(result, str + start, end - start);
}

void load_dialogues(){
    if(dialogues_0[sizeof(dialogues_0)-1] != 0){
        for(UINT8 i = 0 ; i < sizeof(dialogues_0); i++){
            dialogues_0[i] = dialogues_0[i] ^ 35;
        }
    }
    if (dialogues_1[sizeof(dialogues_1)-1] != 0){
        for(UINT8 i = 0 ; i < sizeof(dialogues_1); i++){
            dialogues_1[i] = dialogues_1[i] ^ 36;
        }
    }
    if (dialogues_2[sizeof(dialogues_2)-1] != 0){
        for(UINT8 i = 0 ; i < sizeof(dialogues_2); i++){
            dialogues_2[i] = dialogues_2[i] ^ 37;
        }
    }
    if (dialogues_3[sizeof(dialogues_3)-1] != 0){
        for(UINT8 i = 0 ; i < sizeof(dialogues_3); i++){
            dialogues_3[i] = dialogues_3[i] ^ 38;
        }
    }

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
    clear_lines(nlines+1);
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

