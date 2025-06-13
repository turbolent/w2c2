#include <stdio.h>
#include <stdlib.h>

#include "list_test.h"
#include "list.h"

typedef struct TestElement {
    ListLink link;
    int value;
} TestElement;

void
testListOperations(void) {
    ListLink* list = NULL;

    TestElement element1;
    TestElement element2;
    TestElement element3;

    element1.value = 1;
    element2.value = 2;
    element3.value = 3;

    listInitialize(&element1.link);
    listInitialize(&element2.link);
    listInitialize(&element3.link);

    /* Initialize with element3 as the head. */

    list = &element3.link;

    /* Prepend element2 to the list. */

    list = listPrepend(list, &element2.link);

    if (list != &element2.link) {
        fprintf(stderr, "FAIL testList: list != &element2.link\n");
        exit(1);
    }
    if (list->next != &element3.link) {
        fprintf(stderr, "FAIL testList: list->next != &element3.link\n");
        exit(1);
    }
    if (list->prev != NULL) {
        fprintf(stderr, "FAIL testList: list->prev != NULL\n");
        exit(1);
    }
    if (element3.link.next != NULL) {
        fprintf(stderr, "FAIL testList: element3.link.next != NULL\n");
        exit(1);
    }
    if (element3.link.prev != &element2.link) {
        fprintf(stderr, "FAIL testList: element3.link.prev != &element2.link\n");
        exit(1);
    }

    /*Prepend element1 to the list. */

    list = listPrepend(list, &element1.link);

    if (list != &element1.link) {
        fprintf(stderr, "FAIL testList: list != &element1.link\n");
        exit(1);
    }
    if (list->next != &element2.link) {
        fprintf(stderr, "FAIL testList: list->next != &element2.link\n");
        exit(1);
    }
    if (list->prev != NULL) {
        fprintf(stderr, "FAIL testList: list->prev != NULL\n");
        exit(1);
    }
    if (element2.link.next != &element3.link) {
        fprintf(stderr, "FAIL testList: element2.link.next != &element3.link\n");
        exit(1);
    }
    if (element2.link.prev != &element1.link) {
        fprintf(stderr, "FAIL testList: element2.link.prev != &element1.link\n");
        exit(1);
    }
    if (element3.link.next != NULL) {
        fprintf(stderr, "FAIL testList: element3.link.next != NULL\n");
        exit(1);
    }
    if (element3.link.prev != &element2.link) {
        fprintf(stderr, "FAIL testList: element3.link.prev != &element2.link\n");
        exit(1);
    }

    /* Remove element2 from the list. */

    list = listRemove(list, &element2.link);

    if (list != &element1.link) {
        fprintf(stderr, "FAIL testList: list != &element1.link\n");
        exit(1);
    }
    if (list->next != &element3.link) {
        fprintf(stderr, "FAIL testList: list->next != &element3.link\n");
        exit(1);
    }
    if (list->prev != NULL) {
        fprintf(stderr, "FAIL testList: list->prev != NULL\n");
        exit(1);
    }
    if (element2.link.next != NULL) {
        fprintf(stderr, "FAIL testList: element2.link.next != NULL\n");
        exit(1);
    }
    if (element2.link.prev != NULL) {
        fprintf(stderr, "FAIL testList: element2.link.prev != NULL\n");
        exit(1);
    }
    if (element3.link.next != NULL) {
        fprintf(stderr, "FAIL testList: element3.link.next != NULL\n");
        exit(1);
    }
    if (element3.link.prev != &element1.link) {
        fprintf(stderr, "FAIL testList: element3.link.prev != &element1.link\n");
        exit(1);
    }

    /* Remove element1 from the list. */

    list = listRemove(list, &element1.link);

    if (list != &element3.link) {
        fprintf(stderr, "FAIL testList: list != &element3.link\n");
        exit(1);
    }
    if (list->next != NULL) {
        fprintf(stderr, "FAIL testList: list->next != NULL\n");
        exit(1);
    }
    if (list->prev != NULL) {
        fprintf(stderr, "FAIL testList: list->prev != NULL\n");
        exit(1);
    }
    if (element1.link.next != NULL) {
        fprintf(stderr, "FAIL testList: element1.link.next != NULL\n");
        exit(1);
    }
    if (element1.link.prev != NULL) {
        fprintf(stderr, "FAIL testList: element1.link.prev != NULL\n");
        exit(1);
    }

    fprintf(stderr, "PASS testList\n");
}

static int freeCount = 0;

static
void
testFreeLink(ListLink* link) {
    TestElement* element = (TestElement*)link;

    switch (freeCount) {
        case 0:
            if (element->value != 1) {
                fprintf(stderr, "FAIL testListFree: element->value != 1\n");
                exit(1);
            }
            break;
        case 1:
            if (element->value != 2) {
                fprintf(stderr, "FAIL testListFree: element->value != 2\n");
                exit(1);
            }
            break;
        case 2:
            if (element->value != 3) {
                fprintf(stderr, "FAIL testListFree: element->value != 3\n");
                exit(1);
            }
            break;
        default:
            fprintf(stderr, "FAIL testListFree: freeCount > 2\n");
            exit(1);
    }

    freeCount++;
}

void
testListFree(void) {
    ListLink* list = NULL;

    TestElement element1;
    TestElement element2;
    TestElement element3;

    element1.value = 1;
    element2.value = 2;
    element3.value = 3;

    listInitialize(&element1.link);
    listInitialize(&element2.link);
    listInitialize(&element3.link);

    /* Initialize with element3 as the head. */

    list = &element3.link;

    /* Prepend element2 to the list. */

    list = listPrepend(list, &element2.link);

    /* Prepend element1 to the list. */

    list = listPrepend(list, &element1.link);

    /* Free the list. */

    freeCount = 0;

    listFree(list, testFreeLink);

    if (freeCount != 3) {
        fprintf(stderr, "FAIL testListFree: freeCount != 3\n");
        exit(1);
    }

    fprintf(stderr, "PASS testListFree\n");
}
