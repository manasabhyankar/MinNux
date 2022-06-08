#include <stdint.h>
#include <stdbool.h>
#include "group.h"

typedef struct _FILE_TIME_ATTRIBUTE{
    uint16_t year;
    uint8_t  month;
    uint8_t  day;

    uint8_t  hour;
    uint8_t  minute;
    uint8_t  second;
} FILE_TIME_ATTRIBUTE_t;

typedef struct _FILE_TYPE_ATTRIBUTE{
    bool file;
    bool folder;
} FILE_TYPE_ATTRIBUTE_t;

typedef struct _FILE_ATTRIBUTES{
    FILE_TIME_ATTRIBUTE_t        time;
    FILE_TYPE_ATTRIBUTE_t        type;
} FILE_ATTRIBUTES_t;

typedef struct _FILE{
    char*    filename;
    uint32_t byte_size;
    char*    owner;

    /*
    3 types of groups, just like Linux. A user contains all 3 scopes and have their
    default permissions set to read and write enabled.
          1. global (the global pool of users, including root. 
                     Meaning any file in this group inherits global permissions
                     as set by either the previous user, or by default by the OS.) 
          2. group  (the group pool dictates that all files and
                     users that exist in common pools inherit the
                     permissions of that file.)
          3. user   (permissions that a specific user has. This is the
                     check that determines if a file is capable of being
                     read or written to by a specific user.)
    Caveats:
        1. There can be only 1 root user at once. Root has automatic
        read and write permissions to all files and belongs to all
        groups.
        2. "sudo" is a reserved keyword giving a user root level access
        to the following operation, provided the "sudo" password
        was entered.
        3. Permissions can be changed at any scope (global, group, or user)
        by using the command "chgperm", provided the following:
            a. The user is root.
            b. The user does not control the target file because its scope
            is does not include the necessary scopes (i.e. the target file
            belongs to the "A" group but the user is not part of group "A",
            or if the user does not have "sudo" permissions or is not the
            root user) but has obtained "sudo" permissions.
    */

    GROUP_t           file_group;
    FILE_ATTRIBUTES_t attributes;
} FILE_t;

void print_file_attributes(FILE_t* file);

bool is_file(FILE_t* file);

FILE_t* make_new_file(bool file_flag);

void set_file_attribute_time(FILE_t* file,
                             uint16_t year, uint8_t month, uint8_t day,
                             uint8_t hour, uint8_t minute, uint8_t second);

/*
TODO: Can be more properly done when users, root, and groups
are implemented. Dumb implementation for now
*/
void set_file_attribute_permissions(FILE_t* file, bool read, bool write);
