#include "print.h"
#include <stdint.h>

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char{
    uint8_t character;
    uint8_t color;
};

struct Char* buffer = (struct Char*) 0xB8000;
size_t col = 0;
size_t row = 0;
uint8_t color = VGA_COLOR_WHITE | VGA_COLOR_BLACK << 4;

void clear_row(size_t row){
    struct Char empty = (struct Char){
        .character =  ' ',
        .color =  color,
    };

    for(size_t col = 0; col < NUM_COLS; col++){
        buffer[col + NUM_COLS * row] = empty;
    }
}

void print_clear(){
    for(size_t y = 0; y < NUM_ROWS; y++){

    }
}

void print_newline(){
    col = 0;
    if(row < NUM_ROWS - 1){
        row++;
        return;
    }

    for(size_t row = 1; row < NUM_ROWS; row++){
        for(size_t col = 0; col < NUM_COLS; col++){
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_ROWS - 1);
}

void print_char(char character){
    if(character == '\n'){
        print_newline();
        return;
    }

    if(col > NUM_COLS){
        print_newline();
    }
    buffer[col + NUM_COLS * row] = (struct Char){
        .character =   (uint8_t) character,
        .color =  color,
    };
    col++;
}

void print_str(char* str){
    for(size_t i = 0; 1; i++){
        if(str[i] == '\0') return;
        print_char( (uint8_t) str[i]);
    }
}

void print_set_color(uint8_t foreground, uint8_t background){
    color = foreground + (background << 4);
}