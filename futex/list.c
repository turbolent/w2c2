#include "list.h"
#include "../w2c2/w2c2_base.h"

void
listInitialize(
    ListLink* list
) {
    if (list) {
        list->prev = NULL;
        list->next = NULL;
    }
}

void
listFree(
    ListLink* head,
    void (freeLink)(ListLink* link)
) {
    while (head) {
        ListLink* next = head->next;
        freeLink(head);
        head = next;
    }
}

ListLink*
listPrepend(
    ListLink* head,
    ListLink* element
) {
    if (element) {
        element->next = head;
    }
    if (head) {
        head->prev = element;
    }
    return element;
}

ListLink*
WARN_UNUSED_RESULT
listRemove(
    ListLink* head,
    ListLink* element
) {
    if (element) {
        ListLink *prev = element->prev;
        ListLink *next = element->next;
        element->prev = NULL;
        element->next = NULL;
        if (next) {
            next->prev = prev;
        }
        if (prev) {
            prev->next = next;
        } else {
            return next;
        }
    }
    return head;
}
