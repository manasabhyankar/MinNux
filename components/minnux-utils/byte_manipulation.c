#include "byte_manipulation.h"
#include "esp_heap_caps.h"

char* convert_to_byte_string(uint8_t byte){
    char* byte_string = (char*) heap_caps_malloc(9, MALLOC_CAP_8BIT);
    for(int i = 0; i < 8; i++){
        if(byte & (1 << i)){
          byte_string[7 - i] = '1';
        }
        else{
          byte_string[7 - i] = '0';
        }
    }
    byte_string[8] = '\0';
    return byte_string;
}
