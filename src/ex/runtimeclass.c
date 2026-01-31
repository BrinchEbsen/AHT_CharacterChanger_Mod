#include <runtimeclass.h>

bool class_is_or_inherits_from(EXRuntimeClass* derived, EXRuntimeClass* base) {
    if ((derived == NULL) || ( base == NULL)) {
        return false;
    }

    //Is it this class?
    if (derived == base) {
        return true;
    }

    //Does it derive from this class?
    for (
        EXRuntimeClass* c = derived->m_pBaseClass;
        c != NULL;
        c = c->m_pBaseClass
    ) {
        if (base == c) {
            return true;
        }
    }

    return false;
}