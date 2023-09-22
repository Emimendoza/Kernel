#include "print.h"

void kernel_main(){
    print_clear();
    print_set_color(VGA_COLOR_LIGHT_GREEN, VGA_COLOR_BLACK);
    print_str("Hi, I'm the kernel!!!");
}