# Complete Orange Upgrade

## What is this?
This will be a ROM base for Pokemon Orange Islands (GBA) by Kalarie made from the ground up using the CFRU template (with preproc and gbagfx support).

**Before doing anything it will be HIGHLY recommended the documentation be read thoroughly.**

## Planned Features
* WIP

## Features
* Nothing yet

**NOTE** Personalized options are available in *src/config.h*. The options can be customized by commenting and uncommenting lines.

## Installation Instructions
### Windows
See [the wiki](https://github.com/Skeli789/Complete-Fire-Red-Upgrade/wiki/Windows-Installation-Instructions).

### UNIX-like OS (Linux, MacOS, ...)
1. Install devkitPro with instructions [here](https://devkitpro.org/wiki/Getting_Started).

2. Export `${DEVKITARM}/bin/` to your `PATH` variable.

3. Make sure you've installed python 3.6+ and it can be called directly via either `python` or `python3`.

4. Clone the repo and go inside:   
```bash
git clone https://github.com/Skeli789/Complete-Fire-Red-Upgrade
cd Complete-Fire-Red-Upgrade
```

5. Get your ROM into the current directory and rename it to **OI.gba**.

6. Configure the offset you want to insert the code:
In *scripts/make.py* change `OFFSET_TO_PUT=YYY` to the location you want to insert the data.

7. Run `python scripts/make.py` (or `python3 scripts/make.py` if you’ve installed multiple python versions).

A new gba file will appear named as **test.gba** and an **offsets.ini** file.
Those are your resultant files.

## Notes

Anytime you make changes, the compiler will only compile the files you have changed.

### Specific to Windows
Any changes made to header files will require you to type ``python scripts//clean.py build``
in cmd and then rerun the build scripts. For more command line options, see "Engine
Scripts" in the documentation.

### Specific to UNIX-like OS (linux, macOS, ...):
Any changes made to header files will require you to clean everything in *build/* and then rerun the build scripts.
