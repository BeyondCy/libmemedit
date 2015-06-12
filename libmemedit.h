#ifndef LIBMEMEDIT_H
#define LIBMEMEDIT_H

#include <stdint.h>

/* memedit_scan will hold state based on platform implementation */
struct _memedit_scan;
typedef struct _memedit_scan *memedit_scan;

struct _memedit_block
{
    uint8_t *search_mask;
    uint_max_t *base_address;
    unsigned int match_count;
    unsigned int size;
};

typedef struct _memedit_block *memedit_block;

enum MEMEDIT_SCAN_TYPE
{
    MEMEDIT_BYTE,
    MEMEDIT_WORD,
    MEMEDIT_DWORD,
    MEMEDIT_QWORD,
    MEMEDIT_FLOAT,
    MEMEDIT_DOUBLE,
    MEMEDIT_BYTE_ARRAY,
    MEMEDIT_STRING
};

enum MEMEDIT_SCAN_CONDITION
{
    MEMEDIT_EXACT_VALUE,
    MEMEDIT_BIGGER_THAN,
    MEMEDIT_SMALLER_THAN,
    MEMEDIT_VALUE_BETWEEN,
    MEMEDIT_UNKNOWN_INITIAL,

    MEMEDIT_INCREASED_VALUE,
    MEMEDIT_INCREASED_BY,
    MEMEDIT_DECREASED_VALUE,
    MEMEDIT_DECREASED_BY,
    MEMEDIT_CHANGED_VALUE,
    MEMEDIT_UNCHANGED_VALUE,
    MEMEDIT_SAME_INITIAL
};

struct memedit_scan_options
{
    MEMEDIT_SCAN_TYPE scan_type;
    MEMEDIT_SCAN_CONDITION
};

memedit_scan memedit_scan_new(void);
void memedit_scan_free(memedit_scan scan);

void memedit_block_update(memedit_block block, MEMEDIT_SCAN_CONDITION condition, void *value);


#endif // LIBMEMEDIT_H
