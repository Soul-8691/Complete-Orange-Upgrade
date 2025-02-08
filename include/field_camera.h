#ifndef GUARD_FIELD_CAMERA_H
#define GUARD_FIELD_CAMERA_H

#include "global.h"

// Exported type declarations

struct CameraObject
{
    void (*callback)(struct CameraObject *);
    u32 spriteId;
    s32 movementSpeedX;
    s32 movementSpeedY;
    s32 x;
    s32 y;
};

// Exported RAM declarations

extern struct CameraObject gFieldCamera;
extern u16 gTotalCameraPixelOffsetX;
extern u16 gTotalCameraPixelOffsetY;
extern bool8 gBikeCameraAheadPanback;

// Exported ROM declarations

void __attribute__((long_call)) DrawWholeMapView(void);
void __attribute__((long_call)) CurrentMapDrawMetatileAt(int x, int y);
void __attribute__((long_call)) FieldCameraGetPixelOffsetAtGround(s16 *x, s16 *y);
void __attribute__((long_call)) SetCameraPanningCallback(void (*cb)(void));
void __attribute__((long_call)) SetCameraPanning(s16 x, s16 y);
void __attribute__((long_call)) UpdateCameraPanning(void);
void __attribute__((long_call)) InstallCameraPanAheadCallback(void);
void __attribute__((long_call)) DrawDoorMetatileAt(int x, int y, const u16 *data);
void __attribute__((long_call)) move_tilemap_camera_to_upper_left_corner(void);
void __attribute__((long_call)) CameraUpdate(void);
void __attribute__((long_call)) FieldUpdateBgTilemapScroll(void);
void __attribute__((long_call)) ResetCameraUpdateInfo(void);
u32 __attribute__((long_call)) InitCameraUpdateCallback(u8 trackedSpriteId);
void __attribute__((long_call)) CameraUpdateNoObjectRefresh(void);

#endif //GUARD_FIELD_CAMERA_H
