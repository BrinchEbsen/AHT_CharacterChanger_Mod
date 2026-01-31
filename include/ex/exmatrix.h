#ifndef EXMATRIX_H
#define EXMATRIX_H
#include <exvector.h>

typedef struct EXMatrix {
    EXVector row0;
    EXVector row1;
    EXVector row2;
    EXVector row3;
} EXMatrix;

typedef EXMatrix mat_44;

extern mat_44* Mat44T_Mult_Vec4(mat_44* mat, EXVector* vct, EXVector* dest);
extern void EXMaths__mat_44__set_rotate(mat_44* self, vec_xyzw* vec, uchar ro);
extern void EXMaths__mat_44__set_rotate_axis(mat_44* this, vec_xyzw* vec);

#endif /* EXMATRIX_H */