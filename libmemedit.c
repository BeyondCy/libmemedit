#include <malloc.h>
#include "libmemedit.h"
#include "platform/linux/memedit_scan.h"

memedit_scan memedit_scan_new(void)
{
    memedit_scan scan = (memedit_scan)malloc(sizeof memedit_scan);
    scan->pid = -1;

    return scan;
}

void memedit_scan_free(memedit_scan scan)
{
    free((void*)scan);
}
