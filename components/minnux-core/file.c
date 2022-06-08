#include <stdio.h>
#include "file.h"
#include "byte_manipulation.h"
#include "esp_heap_caps.h"

void print_file_attributes(FILE_t* file){
    printf("Filename:  %s\n"
            "File time: %i:%i:%i\n"
            "File permissions: %s\n"
            "File type: %i\n",
            file->filename, file->attributes.time.hour,
            file->attributes.time.minute, file->attributes.time.second,
            convert_to_byte_string(file->file_group.group_bits),
            is_file(file));
}

bool is_file(FILE_t* file){
    return (file->attributes.type.file == true);
}

/*
Make a new file instance and initializes it to null or 0 values.
*/

FILE_t* make_new_file(bool file_flag){
    FILE_t* return_file = (FILE_t*) heap_caps_malloc(sizeof(FILE_t), MALLOC_CAP_8BIT);
    return_file->filename  = NULL;
    return_file->byte_size = 0;
    return_file->owner     = NULL;
    if(file_flag){
        return_file->attributes.type.file   = true;
        return_file->attributes.type.folder = false;
    }
    else{
        return_file->attributes.type.folder = true;
        return_file->attributes.type.file   = false;
    }
    set_file_attribute_time(return_file, 0, 0, 0, 0, 0, 0);
    set_file_attribute_permissions(return_file, 0, 0);
    return return_file;
}

/*
Sets all time attributes for a file to 0
*/
void set_file_attribute_time(FILE_t* file,
                             uint16_t year, uint8_t month, uint8_t day,
                             uint8_t hour, uint8_t minute, uint8_t second){
    // First YY:MM:DD
    file->attributes.time.year   = year;
    file->attributes.time.month  = month;
    file->attributes.time.day    = day;
    // Then HH:MM:SS
    file->attributes.time.hour   = hour;
    file->attributes.time.minute = minute;
    file->attributes.time.second = second;
}

/*
Sets permissions attribute to r/w for all groups (for now)
*/
void set_file_attribute_permissions(FILE_t* file, bool read, bool write){
    // TODO:
    file->file_group.group_bits = 0b00111111;
}