#ifndef EXVECTOR_H
#define EXVECTOR_H

typedef struct EXVector {
    float x;
    float y;
    float z;
    float w;
} EXVector;

typedef EXVector vec_xyzw;

typedef struct EXVector3 {
    float x;
    float y;
    float z;
} EXVector3;

typedef EXVector3   vec_xyz, MXVector;

typedef struct EXVector2 {
    float x;
    float y;
} EXVector2;

void EXVector_Add(EXVector* dest, EXVector* addVec);
void EXVector_Copy(EXVector* dest, EXVector* src);
float EXVector_Dist(EXVector* v1, EXVector* v2);

#endif /* EXVECTOR_H */