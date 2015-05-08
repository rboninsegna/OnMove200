# OMH tool
## To build:
	`gcc -o om200-omh main.c OM200HeaderFile.c`
## Usage:
	`./om200-omh {path to ACT_????.OMH file}`

# Ephemeris updater
## Preparations:
	Install `wget` and make sure it's in your PATH
## Usage:
	While online, run `./om200-ephemeris`
	Copy/move new "epo.7" file to root folder of watch
	Unmount, unplug, wait a minute (see display)
	Repeat procedure at least weekly to always have A-GPS working

