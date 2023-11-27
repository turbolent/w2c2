#include "map.h"

void
mapInitialize(
    Map* map,
    size_t bucketCount
) {
    if (map) {
        map->buckets = (MapNode**)calloc(bucketCount, sizeof(MapNode*));
        map->bucketCount = bucketCount;
    }
}

void
mapFree(
    Map* map,
    void (freeValue)(void* value)
) {
    if (map) {
        size_t bucketIndex = 0;
        for (; bucketIndex < map->bucketCount; bucketIndex++) {
            MapNode* node = map->buckets[bucketIndex];
            while (node) {
                MapNode* next = (MapNode*)node->link.next;
                freeValue(node->value);
                free(node);
                node = next;
            }
        }
        free(map->buckets);
    }
}

void**
mapGet(
    Map* map,
    U32 key
) {
    if (map) {
        size_t bucketIndex = (size_t)key % map->bucketCount;
        MapNode* node = map->buckets[bucketIndex];

        while (node) {
            if (node->key == key) {
                return &node->value;
            }
            node = (MapNode*)node->link.next;
        }
    }
    return NULL;
}

void**
mapInsert(
    Map* map,
    U32 key
) {
    if (map) {
        MapNode* node = (MapNode*)calloc(1, sizeof(MapNode));
        if (node) {
            MapNode** buckets = map->buckets;
            size_t bucketIndex = (size_t)key % map->bucketCount;
            buckets[bucketIndex] = (MapNode*)listPrepend(
                (ListLink*)buckets[bucketIndex],
                &node->link
            );
            node->key = key;
            return &node->value;
        }
    }

    return NULL;
}

void*
mapRemove(
    Map* map,
    U32 key
) {
    if (map) {
        MapNode** buckets = map->buckets;
        size_t bucketIndex = (size_t)key % map->bucketCount;
        MapNode* head = buckets[bucketIndex];

        MapNode* node = head;
        while (node) {
            if (node->key == key) {
                void* value = node->value;
                buckets[bucketIndex] = (MapNode*)listRemove(
                    &head->link,
                    &node->link
                );
                free(node);
                return value;
            }
            node = (MapNode*)node->link.next;
        }
    }
    return NULL;
}
