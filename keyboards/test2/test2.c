// Copyright 2021 Maroš Kramár (@Maroš Kramár)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "test2.h"

#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
        // {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        // {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        // {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        // {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        // {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},

        // {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        // {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        // {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        // {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
        // {NO_LED, NO_LED, NO_LED, NO_LED, NO_LED},
}, {
  // LED Index to Physical Position
    {154, 15}, {154, 30}, {154, 45}, {154, 60},
  {224, 50}, {224, 35}, {224, 20}, 

  
  {70, 15}, {70, 30}, {70, 45}, {70, 60}, 
  {0, 50}, {0, 35}, {0, 20},  
  

  
  
   
}, {
  // LED Index to Flag
  LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW,
  LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW, LED_FLAG_UNDERGLOW
} };
#endif 
