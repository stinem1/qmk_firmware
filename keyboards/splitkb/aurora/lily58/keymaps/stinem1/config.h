#pragma once

// `SPLIT_HAND_PIN` can currently be defined in `info.json`,
// but can't yet be given a value
#define SPLIT_HAND_PIN F5
#define USB_VBUS_PIN 19U
#define NO_USB_STARTUP_CHECK

// Not yet available in `info.json`
#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define SPLIT_OLED_ENABLE
#endif

// Not yet available in `info.json`
// hsv(200, 200, 200) <3
#ifdef RGB_MATRIX_ENABLE
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS RGBLIGHT_LIMIT_VAL
#    define RGB_MATRIX_LED_COUNT RGBLED_NUM
#    define RGB_MATRIX_SPLIT RGBLED_SPLIT
#    define SPLIT_TRANSPORT_MIRROR
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
// Effects
#    define ENABLE_RGB_MATRIX_SOLID_COLOR
#    define ENABLE_RGB_MATRIX_BREATHING
#    define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT_MODE
#    define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#    define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#    define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#    define ENABLE_RGB_MATRIX_DUAL_BEACON
#    define ENABLE_RGB_MATRIX_RAINBOW_BEACON    
#    define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#    define ENABLE_RGB_MATRIX_RAINDROPS       
#    define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS  
#    define ENABLE_RGB_MATRIX_HUE_BREATHING       
#    define ENABLE_RGB_MATRIX_HUE_PENDULUM         
#    define ENABLE_RGB_MATRIX_HUE_WAVE            
#    define ENABLE_RGB_MATRIX_PIXEL_FRACTAL       
#    define ENABLE_RGB_MATRIX_PIXEL_FLOW          
#    define ENABLE_RGB_MATRIX_PIXEL_RAIN
#    define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#    define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#    define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#endif

// Not yet available in `info.json`
#ifdef BOOTMAGIC_ENABLE
     // Top left key on left half
#    define BOOTMAGIC_LITE_ROW 0
#    define BOOTMAGIC_LITE_COLUMN 0
     // Top right key on right half
#    define BOOTMAGIC_LITE_ROW_RIGHT    5
#    define BOOTMAGIC_LITE_COLUMN_RIGHT 0
#endif
