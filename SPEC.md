# Opensteno Specification
## Features
- Plover compatible dictionaries
- Json config file
- Create user notifications by user defined command (e.g. espeak to speak status information to the user)
    - Currently active mode
## Modes
### Classic 
A classic steno machine with a big dictionary based on stened or plover.
### Other
- spelling — A very simple dictionary containing the alphabet, common trigrams, common words and common characters
- awesome — A mode specifically for controlling awesome wm
- emacs — A mode to controll emacs
- programming — A mode for programming
## Multiple Modes
Modes should be combinable. Dictionaries will merge in a way either by not conflicting or by a pre-defined conflict resolution (prefer one dictionary over the other for example).

