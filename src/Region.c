#include "Region.h"
#include <stdlib.h>

Region* createRegion(){
    Region *region =(Region*)malloc(sizeof(Region));
    region->allocations = NULL;
    return region;
}

void destroyRegion(Region *r){
    Allocation *allocations = r->allocations;
    while (allocations != NULL){
        Allocation *next = allocations->next;
        free(allocations->data);
        free(allocations);
        allocations = next;
    }
    free(r);
}

void *allocateFromRegion(Region *r, size_t size){
    if (r->allocations == NULL){
        r->allocations = (Allocation*)malloc((sizeof(Allocation)));
        r->allocations->data = malloc(size);
        r->allocations->next = NULL;
        return r->allocations->data;
    } else {
        Allocation *allocations = r->allocations;
        while(allocations->next != NULL){
            allocations = allocations->next;
        }
        Allocation* nextAllocation = (Allocation*)malloc((sizeof(Allocation)));
        nextAllocation->data = malloc(size);
        nextAllocation->next = NULL;

        allocations->next = nextAllocation;
        return nextAllocation->data;
    }
    return NULL;
}
