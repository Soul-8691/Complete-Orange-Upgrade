#ifndef GUARD_TRADE_SCENE_H
#define GUARD_TRADE_SCENE_H

void __attribute__((long_call)) CB2_LinkTrade(void);
void __attribute__((long_call)) CreateInGameTradePokemon(void);
void __attribute__((long_call)) DoInGameTradeScene(void);
void __attribute__((long_call)) DrawTextOnTradeWindow(u8 windowId, const u8 *str, s8 speed);
u16 __attribute__((long_call)) GetInGameTradeSpeciesInfo(void);
u16 __attribute__((long_call)) GetTradeSpecies(void);
void __attribute__((long_call)) InitTradeSequenceBgGpuRegs(void);
void __attribute__((long_call)) LinkTradeDrawWindow(void);
void __attribute__((long_call)) LoadTradeAnimGfx(void);

extern const u16 gTradeOrHatchMonShadowTilemap[];
extern const struct WindowTemplate gTradeEvolutionSceneYesNoWindowTemplate;

#endif //GUARD_TRADE_SCENE_H
