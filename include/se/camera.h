#ifndef CAMERA_H
#define CAMERA_H

typedef enum CamTypes {
    Base=0,
    Follow=1,
    Scan=2,
    FirstPerson=3,
    PoleGrab=4,
    Fixed=5,
    PathFollow=6,
    PathDrag=7,
    Cutscene=8,
    Fall=9,
    cannonCam=10,
    BallGadgetFollow=11,
    NPCDialog=12,
    Boss=13,
    PreviousCam=14,
    Tunnel=15,
    Rocket=16,
    BallGadgetPadCam=17
} CamTypes;

typedef enum CamCreateMode {
    SetPos=0,
    ForcePos=1,
    ClonePos=2
} CamCreateMode;

#endif /* CAMERA_H */