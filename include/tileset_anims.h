#ifndef GUARD_TILESET_ANIMS_H
#define GUARD_TILESET_ANIMS_H

void __attribute__((long_call)) InitTilesetAnimations(void);
void __attribute__((long_call)) InitSecondaryTilesetAnimation(void);
void __attribute__((long_call)) UpdateTilesetAnimations(void);
void __attribute__((long_call)) TransferTilesetAnimsBuffer(void);

void __attribute__((long_call)) InitTilesetAnim_General(void);
void __attribute__((long_call)) InitTilesetAnim_CeladonCity(void);
void __attribute__((long_call)) InitTilesetAnim_VermilionGym(void);
void __attribute__((long_call)) InitTilesetAnim_CeladonGym(void);
void __attribute__((long_call)) InitTilesetAnim_SilphCo(void);
void __attribute__((long_call)) InitTilesetAnim_MtEmber(void);

#endif // GUARD_TILESET_ANIMS_H
