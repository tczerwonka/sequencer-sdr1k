/******************************************************************************/
/* translation - ic2 to actions */
/******************************************************************************/

#ifndef TRANSLATION_H
#define TRANSLATION_H
#include <stdint.h>

struct xlate_tbl {
    char band[9];
    uint8_t i2c;
};

static const uint8_t xlate_tbl_entries = 3;
static const xlate_tbl i2ccmd[] = {
  {"2m", 0x01},
  {"222", 0x02}
};

#endif
