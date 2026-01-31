#ifndef RUNTIMECLASS_H
#define RUNTIMECLASS_H
#include <types.h>

typedef struct EXRuntimeClass EXRuntimeClass;
struct EXRuntimeClass {
	EXRuntimeClass *m_pBaseClass;
	char *m_pClassName;
	s32 m_nObjectSize;
	void* (*m_pCreateObject)();
};

typedef EXRuntimeClass*(*GetRuntimeClass_func)(void);

// Test if runtime class `derived` inherits from `base`.
bool class_is_or_inherits_from(EXRuntimeClass* derived, EXRuntimeClass* base);

#endif /* RUNTIMECLASS_H */