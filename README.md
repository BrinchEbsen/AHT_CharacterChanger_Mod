# Spyro: A Hero's Tail - Character Changer Mod
This mod provides a custom menu to the game which lets you change character at any time, as well as giving you access to a few basic cheats.

Use with caution. While some crashes that are caused by using unintended characters have been fixed, crashes or softlocks may still occur.

Created using Composer's [code injection utility](https://github.com/C0mposer/C-Game-Modding-Utility).

## Compatibility
Currently only compatible with the GameCube US version (G5SE7D).

## Usage
Double-press Z to open the menu. Double-press Z again or press B to close the menu.

While in the menu, you can flip between the Characters page and Cheats page by pressing left/right. Press up/down to select different options, and press A to select them.

In the Characters page you can select a character to switch to. The game may have to spend a bit of time loading assets before the change happens.

In the Cheats page, you can enable several cheats which might help with experimenting with the different characters.

While in the menu, press the X button to enable/disable the Scanmode feature. This will let you toggle a sort of "noclip" mode that lets you fly freely through the map. When Scanmode is enabled, hold any direction on the d-pad and press Z to toggle it.

## Installation
Three methods are provided for installing the mod. See the assets in the latest [release](https://github.com/BrinchEbsen/AHT_CharacterChanger_Mod/releases).

### Action Replay Code
The entire mod can be run from an Action Replay Code in Dolphin. Note that this will only work on emulator due to hardware constraints.

The code can be found in `AR_Code.txt`. Right-click on the game in Dolphin's game list and go to Properties. Go to the AR Codes tab and add a new code with the contents of the .txt file.

### ISO XDelta Patch
Use [xdelta](https://www.romhacking.net/utilities/598/) and the patch file `ISO_patch.xdelta` to patch your game's iso. This is not guaranteed to work since it'll need to match the ISO used to create the mod. The ISO I used has the SHA-1 checksum `718bd74c1345f23ebfeeff2f527d7dfb007fc531`.

### Start.dol XDelta Patch
Use [xdelta](https://www.romhacking.net/utilities/598/) and the patch file `Start_DOL_patch.xdelta` to patch your game's `Start.dol` executable.

The executable can be exported and then overwritten with [GCRebuilder](https://www.romhacking.net/utilities/619/). Load the ISO in the tool, export `Start.dol` from the `&&SystemData` folder of the ISO, apply the xdelta patch to it, then in the tool import the patched `Start.dol` overtop of the original.