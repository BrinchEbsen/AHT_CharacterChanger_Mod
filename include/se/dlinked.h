#ifndef DLINKED_H
#define DLINKED_H
#include <types.h>

typedef struct List List;
typedef struct DLinkedTYPE DLinkedTYPE;

struct List {
	DLinkedTYPE *m_pHead;
	DLinkedTYPE *m_pTail;
	s32 m_Count;
	void **m_pTYPE;
};

struct DLinkedTYPE {
	DLinkedTYPE *m_pNext;
	DLinkedTYPE *m_pPrev;
	List *m_pList;
	void *m_TYPE;
};

#endif /* DLINKED_H */
