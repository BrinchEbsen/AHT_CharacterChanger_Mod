#ifndef EXQUATERNION_H
#define EXQUATERNION_H
#include <types.h>
#include <exvector.h>

typedef struct EXQuaternion {
    vec_xyzw vec128; /* Inherited from vec_xyzw */
} EXQuaternion;

#endif /* EXQUATERNION_H */