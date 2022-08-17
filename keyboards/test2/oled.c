#pragma once

#include "progmem.h"
// #include "superloop.c"
#include "bongocat.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

// void render_animation(uint8_t frame) {
//     oled_write_raw_P(animation[frame], sizeof(animation[frame]));
// }

// void run_superloop(void) {
//     render_animation((timer_read() / 60) % 8);
// }

void run_bongocat(void) {
    draw_bongocat();
}

bool oled_task_user(void) {

    if (is_keyboard_master()) {
        run_bongocat();
    } else {
    }
    
    return false;
}