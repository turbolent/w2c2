#include <stdio.h>

#include "map_test.h"
#include "map.h"

void
testMapOperations(void) {
    Map map;

    U32 key1 = 1;
    char* string1 = "1";

    U32 key2 = 2;
    char* string2 = "2";

    U32 key3 = 3;
    char* string3 = "3";

    void **value1 = NULL;
    void **value2 = NULL;
    void **value3 = NULL;

    mapInitialize(&map, 2);

    value1 = mapGet(&map, key1);
    if (value1 != NULL) {
        fprintf(stderr, "FAIL testMap: value1 != NULL\n");
        exit(1);
    }

    value2 = mapGet(&map, key2);
    if (value2 != NULL) {
        fprintf(stderr, "FAIL testMap: value2 != NULL\n");
        exit(1);
    }

    value3 = mapGet(&map, key3);
    if (value3 != NULL) {
        fprintf(stderr, "FAIL testMap: value3 != NULL\n");
        exit(1);
    }

    /* Insert key1. */

    value1 = mapInsert(&map, key1);
    if (value1 == NULL) {
        fprintf(stderr, "FAIL testMap: value1 == NULL\n");
        exit(1);
    }

    *value1 = string1;

    value1 = mapGet(&map, key1);
    if (value1 == NULL) {
        fprintf(stderr, "FAIL testMap: value1 == NULL\n");
        exit(1);
    }

    if (*value1 != string1) {
        fprintf(stderr, "FAIL testMap: *value1 != string1\n");
        exit(1);
    }

    value2 = mapGet(&map, key2);
    if (value2 != NULL) {
        fprintf(stderr, "FAIL testMap: value2 != NULL\n");
        exit(1);
    }

    value3 = mapGet(&map, key3);
    if (value3 != NULL) {
        fprintf(stderr, "FAIL testMap: value3 != NULL\n");
        exit(1);
    }

    /* Insert key2. */

    value2 = mapInsert(&map, key2);

    if (value2 == NULL) {
        fprintf(stderr, "FAIL testMap: value2 == NULL\n");
        exit(1);
    }

    *value2 = string2;

    value2 = mapGet(&map, key2);
    if (value2 == NULL) {
        fprintf(stderr, "FAIL testMap: value2 == NULL\n");
        exit(1);
    }

    if (*value2 != string2) {
        fprintf(stderr, "FAIL testMap: *value2 != string2\n");
        exit(1);
    }

    value1 = mapGet(&map, key1);
    if (value1 == NULL) {
        fprintf(stderr, "FAIL testMap: value1 == NULL\n");
        exit(1);
    }

    if (*value1 != string1) {
        fprintf(stderr, "FAIL testMap: *value1 != string1\n");
        exit(1);
    }

    value3 = mapGet(&map, key3);
    if (value3 != NULL) {
        fprintf(stderr, "FAIL testMap: value3 != NULL\n");
        exit(1);
    }

    /* Insert key3. */

    value3 = mapInsert(&map, key3);

    if (value3 == NULL) {
        fprintf(stderr, "FAIL testMap: value3 == NULL\n");
        exit(1);
    }

    *value3 = string3;

    value3 = mapGet(&map, key3);
    if (value3 == NULL) {
        fprintf(stderr, "FAIL testMap: value3 == NULL\n");
        exit(1);
    }

    if (*value3 != string3) {
        fprintf(stderr, "FAIL testMap: *value3 != string3\n");
        exit(1);
    }

    value1 = mapGet(&map, key1);
    if (value1 == NULL) {
        fprintf(stderr, "FAIL testMap: value1 == NULL\n");
        exit(1);
    }

    if (*value1 != string1) {
        fprintf(stderr, "FAIL testMap: *value1 != string1\n");
        exit(1);
    }

    value2 = mapGet(&map, key2);

    if (value2 == NULL) {
        fprintf(stderr, "FAIL testMap: value2 == NULL\n");
        exit(1);
    }

    if (*value2 != string2) {
        fprintf(stderr, "FAIL testMap: *value2 != string2\n");
        exit(1);
    }

    /* Remove key3. */

    if (mapRemove(&map, key3) != string3) {
        fprintf(stderr, "FAIL testMap: mapRemove(&map, key3) != string3\n");
        exit(1);
    }

    value3 = mapGet(&map, key3);
    if (value3 != NULL) {
        fprintf(stderr, "FAIL testMap: value3 != NULL\n");
        exit(1);
    }

    value1 = mapGet(&map, key1);
    if (value1 == NULL) {
        fprintf(stderr, "FAIL testMap: value1 == NULL\n");
        exit(1);
    }

    if (*value1 != string1) {
        fprintf(stderr, "FAIL testMap: *value1 != string1\n");
        exit(1);
    }

    value2 = mapGet(&map, key2);

    if (value2 == NULL) {
        fprintf(stderr, "FAIL testMap: value2 == NULL\n");
        exit(1);
    }

    if (*value2 != string2) {
        fprintf(stderr, "FAIL testMap: *value2 != string2\n");
        exit(1);
    }

    /* Remove key1. */

    if (mapRemove(&map, key1) != string1) {
        fprintf(stderr, "FAIL testMap: mapRemove(&map, key1) != string1\n");
        exit(1);
    }

    value1 = mapGet(&map, key1);
    if (value1 != NULL) {
        fprintf(stderr, "FAIL testMap: value1 != NULL\n");
        exit(1);
    }

    value2 = mapGet(&map, key2);
    if (value2 == NULL) {
        fprintf(stderr, "FAIL testMap: value2 == NULL\n");
        exit(1);
    }

    if (*value2 != string2) {
        fprintf(stderr, "FAIL testMap: *value2 != string2\n");
        exit(1);
    }

    value3 = mapGet(&map, key3);
    if (value3 != NULL) {
        fprintf(stderr, "FAIL testMap: value3 != NULL\n");
        exit(1);
    }

    /* Remove key2. */

    if (mapRemove(&map, key2) != string2) {
        fprintf(stderr, "FAIL testMap: mapRemove(&map, key2) != string2\n");
        exit(1);
    }

    value2 = mapGet(&map, key2);
    if (value2 != NULL) {
        fprintf(stderr, "FAIL testMap: value2 != NULL\n");
        exit(1);
    }

    value1 = mapGet(&map, key1);
    if (value1 != NULL) {
        fprintf(stderr, "FAIL testMap: value1 != NULL\n");
        exit(1);
    }

    value3 = mapGet(&map, key3);
    if (value3 != NULL) {
        fprintf(stderr, "FAIL testMap: value3 != NULL\n");
        exit(1);
    }

    /* Check that the map is empty. */

    {
        size_t bucketIndex = 0;
        for (; bucketIndex < map.bucketCount; bucketIndex++) {
            if (map.buckets[bucketIndex] != NULL) {
                fprintf(stderr, "FAIL testMap: map is not empty\n");
                exit(1);
            }
        }
    }

    fprintf(stderr, "PASS testMap\n");
}

static int freeCount = 0;

static
void
testFreeValue(void* value) {
    if (value == NULL) {
        fprintf(stderr, "FAIL testMapFree: value == NULL\n");
        exit(1);
    }

    switch (freeCount) {
        case 0:
            if (strcmp(value, "B") != 0) {
                fprintf(stderr, "FAIL testMapFree: value != \"B\"\n");
                exit(1);
            }
            break;
        case 1:
            if (strcmp(value, "C") != 0) {
                fprintf(stderr, "FAIL testMapFree: value != \"C\"\n");
                exit(1);
            }
            break;
        case 2:
            if (strcmp(value, "A") != 0) {
                fprintf(stderr, "FAIL testMapFree: value != \"A\"\n");
                exit(1);
            }
            break;
        default:
            fprintf(stderr, "FAIL testMapFree: freeCount > 2\n");
            exit(1);
    }

    freeCount++;
}

void
testMapFree(void) {
    Map map;
    mapInitialize(&map, 2);
    *mapInsert(&map, 1) = "A";
    *mapInsert(&map, 2) = "B";
    *mapInsert(&map, 3) = "C";

    freeCount = 0;

    mapFree(&map, testFreeValue);

    if (freeCount != 3) {
        fprintf(stderr, "FAIL testMapFree: freeCount != 3\n");
        exit(1);
    }

    fprintf(stderr, "PASS testMapFree\n");
}
