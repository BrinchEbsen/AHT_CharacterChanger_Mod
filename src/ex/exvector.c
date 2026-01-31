#include <exvector.h>
#include <igmath.h>

void EXVector_Add(EXVector* dest, EXVector* addVec)
{
    dest->x += addVec->x;
    dest->y += addVec->y;
    dest->z += addVec->z;
    dest->w += addVec->w;
}

void EXVector_Copy(EXVector* dest, EXVector* src)
{
    dest->x = src->x;
    dest->y = src->y;
    dest->z = src->z;
    dest->w = src->w;
}

float EXVector_Dist(EXVector* v1, EXVector* v2)
{
    float dx = v2->x - v1->x;
    float dy = v2->y - v1->y;
    float dz = v2->z - v1->z;

    return sqrtf((dx*dx) + (dy*dy) + (dz*dz));
}

float EXVector_Len(EXVector* v) {
    return sqrtf(
        (v->x*v->x) +
        (v->y*v->y) +
        (v->z*v->z)
    );
}
