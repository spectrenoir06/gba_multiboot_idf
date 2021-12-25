#include "multiboot.h"
// #include "hc05.h"
#define __BTSTACK_FILE__ "main.c"
#include <driver/gpio.h>

#define OE_GPIO 12

void app_main() {
    gpio_config_t io_conf;
    io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = (1ULL << OE_GPIO);
    io_conf.pull_down_en = 0;
    io_conf.pull_up_en = 0;
    gpio_config(&io_conf);

    gpio_set_level(OE_GPIO, 1);
    multiboot();
    // initHC05();
}