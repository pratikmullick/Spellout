# Spellout
---
A simple program to spell out a numeric value, written in Python.
Copyright 2023, Pratik Mullick. Some rights reserved.

## Installation
Copy the file to your PATH and make it executable.

## Usage

### Execution
Upon executing the script, it will prompt for a positive integer. Acceptable
values range from 0 to 999,999,999,999.

### Extension
You can use this program as a library:
```
import spellout
spellout.spellout(<number>,<magnitude>)
```
**NOTE**: Higher magnitude values will need their corresponding phrase / word
in the `magnitude` array. Make modifications accordingly.

## License
This program is licensed under the GNU General Public License v3. Read LICENSE
for more details.
