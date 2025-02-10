# Complete Orange Upgrade

## What is this?
This will be a ROM base for Pokemon Orange Islands (GBA) by Kalarie made from the ground up using the CFRU template (with preproc and gbagfx support).

**Before doing anything it will be HIGHLY recommended the documentation be read thoroughly.**

# Planned Features
## Unordered
* 120 TMs (50 new, 20 extra)
* 64 move tutor moves (49 new)
* Ability Capsule
* Ability updates (only that exist in Gen 3)
* Battle Points system
* Battle Tower (includes Gen 4-9 related lines of Gen 1/2 mons, including regional formes)
* Berry Trees
* Bottle Caps
* Competitive move tutor (badge-scaling)
* Confusion-healing Berry update
* Damage-reducing Berries
* Day/Night system (and wild encounters)
* Daycare
* Deletable HMs
* Distribution of TMs in TM mart (badge-scaling)
* Distribution of new TMs in maps
* EV/IV display in summary screen (L/R)
* Edited trainer parties (Gen 1/2 mons)
* Edited wild Pokemon (Gen 1/2 mons)
* Egg move tutor
* Evos per mon expanded to 8
* Expanded (and rescripted) maps
* Expanded Poke Balls (including apricorn Balls)
* Fairy type
* Fly obtained at start of game and can be used without any badges
* Gen 1 Exp All
* Gen 4-9 prevos/evos of Gen 1/2 mons (keep original Abilities)
* Gen 4-9 related lines of Gen 1/2 mons (including regional formes) available to buy with Battle Points (need National Dex)
* HMs usable without learning (still need to own)
* Headbutt Trees
* Learnset compatibility updates
* Megas (keep original Ability)
* More balanced level-up learnsets
* More move tutors
* Move base power updates (not effects)
* National Dex obtained near end of game (includes Gen 4-9 related lines of Gen 1/2 mons, including regional formes, and does not include unrelated Gen 3 mons)
* Nature Mints
* New music
* New trainer classes
* New trainers
* Overworld sight encounters
* Pokemon overworlds (that walk around and approach you)
* Quest menu
* Rebattleable trainers (step count-based)
* Regional Formes (keep original Abilities)
* Regional Pokedex now goes includes second Generation
* Safari Zone
* Select Gen 4-9 items
* Select Gen 4-9 moves
* Stat updates
* SwSh egg move transferral update
* Swarms (done differently)
* TM case icons (denote learnable)
* Terrains (in-battle, permanent)
* Time-based events
* Trade evolutions now evolve based on level
* Trade move tutor
* Trainer Pokemon can have EVs
* Updated evolution methods
* Z-Moves

## First Tier (Pressing)

### Doable
* Distribution of TMs in TM mart (badge-scaling)
* Distribution of new TMs in maps
* Edited trainer parties (Gen 1/2 mons)
* Edited wild Pokemon (Gen 1/2 mons)
* Expanded (and rescripted) maps
* More move tutors
* Pokemon overworlds (that walk around and approach you)
* Safari Zone
* Time-based events
* Trade evolutions now evolve based on level

### Existing Implementation Available
* Day/Night system (and wild encounters)
* Expanded Poke Balls (including apricorn Balls)
* Fairy type
* Fly obtained at start of game and can be used without any badges
* Gen 1 Exp All
* HMs usable without learning (still need to own)
* Headbutt Trees
* Megas (keep original Ability)
* New music
* New trainer classes
* New trainers
* Regional Pokedex now goes includes second Generation
* Trainer Pokemon can have EVs

### Custom
* Swarms (done differently)

## Second Tier (Moderately Pressing)

### Doable
* Ability updates (only that exist in Gen 3)
* Daycare
* Move base power updates (not effects)
* National Dex obtained near end of game (includes Gen 4-9 related lines of Gen 1/* mons, including regional formes, and does not include unrelated Gen 3 mons)
* Stat updates

### Existing Implementation Available
* Bottle Caps
* Confusion-healing Berry update
* Deletable HMs
* EV/IV display in summary screen (L/R)
* Egg move tutor
* Evos per mon expanded to 8
* Nature Mints
* Rebattleable trainers (step count-based)
* TM case icons (denote learnable)

### Custom
* Competitive move tutor (badge-scaling)

## Third Tier (Non-Essential)

### Doable
* Gen 4-9 prevos/evos of Gen 1/2 mons (keep original Abilities)
* Learnset compatibility updates
* More balanced level-up learnsets
* Regional Formes (keep original Abilities)
* SwSh egg move transferral update
* Trade move tutor

### Existing Implementation Available
* Ability Capsule
* Damage-reducing Berries
* Select Gen 4-9 items
* Select Gen 4-9 moves
* Terrains (in-battle, permanent)
* Updated evolution methods

## Fourth Tier (Hopeful/Difficult)
* Battle Points system
* Battle Tower (includes Gen 4-9 related lines of Gen 1/2 mons, including regional formes)
* Berry Trees
* Gen 4-9 related lines of Gen 1/2 mons (including regional formes) available to buy with Battle Points (need National Dex)
* Quest menu
* Z-Moves

## Fifth Tier (Done)
* 120 TMs (50 new, 20 extra)
* 64 move tutor moves (49 new)
* Overworld sight encounters

# Features
* Expanded TMs to 120
* Can tutor any move (port of pokeemerald-expansion's learnable moves system)
* Overworld sight encounters

**NOTE** Personalized options are available in *src/config.h*. The options can be customized by commenting and uncommenting lines.

# Installation Instructions
## Windows
See [the wiki](https://github.com/Skeli789/Complete-Fire-Red-Upgrade/wiki/Windows-Installation-Instructions).

## UNIX-like OS (Linux, MacOS, ...)
1. Install devkitPro with instructions [here](https://devkitpro.org/wiki/Getting_Started).

2. Export `${DEVKITARM}/bin/` to your `PATH` variable.

3. Make sure you've installed python 3.6+ and it can be called directly via either `python` or `python3`.

4. Clone the repo and go inside:   
```bash
git clone https://github.com/Soul-8691/Complete-Orange-Upgrade
cd Complete-Orange-Upgrade
```

5. Get your ROM into the current directory and rename it to **OI.gba**.

6. Configure the offset you want to insert the code:
In *scripts/make.py* change `OFFSET_TO_PUT=YYY` to the location you want to insert the data.

7. Run `python scripts/make.py` (or `python3 scripts/make.py` if you’ve installed multiple python versions).

A new gba file will appear named as **test.gba** and an **offsets.ini** file.
Those are your resultant files.

# Notes

Anytime you make changes, the compiler will only compile the files you have changed.

## Specific to Windows
Any changes made to header files will require you to type ``python scripts//clean.py build``
in cmd and then rerun the build scripts. For more command line options, see "Engine
Scripts" in the documentation.

## Specific to UNIX-like OS (linux, macOS, ...):
Any changes made to header files will require you to clean everything in *build/* and then rerun the build scripts.
