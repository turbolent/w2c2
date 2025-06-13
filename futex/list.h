#ifndef W2C2FUTEX_LIST_H
#define W2C2FUTEX_LIST_H

typedef struct ListLink {
    struct ListLink *prev;
    struct ListLink *next;
} ListLink;

void
listInitialize(
    ListLink* list
);

void
listFree(
    ListLink* list,
    void (freeLink)(ListLink* link)
);

ListLink*
listPrepend(
    ListLink* head,
    ListLink* element
);

ListLink*
listRemove(
    ListLink* head,
    ListLink* element
);

#endif /* W2C2FUTEX_LIST_H */
