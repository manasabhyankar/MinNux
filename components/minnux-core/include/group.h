#include <stdint.h>

typedef struct _GROUP{
    /* Bit field of "group_bits" variable

    |-UN-|  |-GL-|  |-GR-|  |-US-|
    x    x  1    0  1    0  1    0

    UN: unused bits
    GL: global permissions bits
    GR: group permissions bits
    US: user permissions bits

    */
    uint8_t group_bits;
} GROUP_t;