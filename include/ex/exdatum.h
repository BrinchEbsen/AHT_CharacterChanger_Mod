#ifndef EXDATUM_H
#define EXDATUM_H
#include <types.h>
#include <exvector.h>
#include <exquaternion.h>

typedef struct EXDatumTemp {
    EXVector vctPos;
    EXQuaternion vctDir;
    /* EXFixedArray<float,3>*/ float Extents[3];
    u16 Flags;
    u8 FrameFlags;
    u8 Type;
} EXDatumTemp;

typedef struct EXGeoTriggerDatum {
    EXHashCode HashRef; /* Inherited from EXGeoBaseDatum */
    u16 Flags; /* Inherited from EXGeoBaseDatum */
    u8 Type; /* Inherited from EXGeoBaseDatum */
    u8 HashIndex; /* Inherited from EXGeoBaseDatum */
    /* EXFixedArray<float,3> */ float Extents[3]; /* Inherited from EXGeoBaseDatum */
    EXVector3 vctPos; /* Inherited from EXGeoBaseDatum */
    /* EXFixedArray<float,4> */ float q[4]; /* Inherited from EXGeoBaseDatum */
} EXGeoTriggerDatum;

#endif /* EXDATUM_H */