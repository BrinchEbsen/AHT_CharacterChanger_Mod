#ifndef EDLIST_H
#define EDLIST_H

typedef struct EXDListItem EXDListItem;
struct EXDListItem {
    EXDListItem* m_pPrev;
    EXDListItem* m_pNext;
};

typedef struct EXDList EXDList;
struct EXDList {
    EXDListItem* m_pHead;
    EXDListItem* m_pTail;
};

#endif /* EDLIST_H */