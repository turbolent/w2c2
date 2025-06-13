#ifndef W2C2FUTEX_MAP_H
#define W2C2FUTEX_MAP_H

#include "list.h"
#include "../w2c2/w2c2_base.h"

typedef struct MapNode {
    ListLink link;
    U32 key;
    void* value;
} MapNode;

typedef struct Map {
    MapNode** buckets;
    size_t bucketCount;
} Map;

void
mapInitialize(
    Map* map,
    size_t bucketCount
);

void
mapFree(
    Map* map,
    void (freeValue)(void* value)
);

void**
WARN_UNUSED_RESULT
mapGet(
    Map* map,
    U32 key
);

void**
WARN_UNUSED_RESULT
mapInsert(
    Map* map,
    U32 key
);

void*
WARN_UNUSED_RESULT
mapRemove(
    Map* map,
    U32 key
);

#endif /* W2C2FUTEX_MAP_H */
