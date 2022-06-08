/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "time.h"
#include "file.h"
#include "esp_heap_caps.h"

void app_main()
{
    FILE_t* test = make_new_file(true);
    test->filename = "file";

    FILE_t* test1 = make_new_file(false);
    test1->filename = "folder";

    print_file_attributes(test);
    print_file_attributes(test1);

    heap_caps_free(test);
    heap_caps_free(test1);
    while(1);
    fflush(stdout);
    esp_restart();
}
