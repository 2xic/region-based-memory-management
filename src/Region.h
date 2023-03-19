#include <stddef.h>

#ifndef _REGION_
#define _REGION_

struct Allocation {
    void *data;
    struct Allocation *next;
};
typedef struct Allocation Allocation;

struct Region {
    Allocation *allocations;
};
typedef struct Region Region;

Region* createRegion();
void * allocateFromRegion(Region *r, size_t size);
void destroyRegion(Region *r);

#endif
