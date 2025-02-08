#pragma once
/*
defines.h
	general header files for most, if not all, files
*/

#include "config.h"

#include "../include/global.h"
#include "../include/pokedex.h"

#include "../include/decompress.h"
#include "../include/item.h"
#include "../include/palette.h"
#include "../include/sprite.h"
#include "../include/task.h"

#include "../include/event_data.h"

#define IS_EVEN(val) (umodsi(val, 2) == 0)
#define IS_ODD(val) (umodsi(val, 2) != 0)

#define uBYTE0_16(value)(( (u8) (((u16)(value) & (0x000000FF)) >> 0x00)))
#define uBYTE1_16(value)(( (u8) (((u16)(value) & (0x0000FF00)) >> 0x08)))

#define EOS 0xFF

#define ITEM_NONE 0
