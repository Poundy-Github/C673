# Flashing BootModeHeaDers of TC3xx devices

This folder contains _demo_ scripts which allow to flash BootModeHeaDers (BMHDs) of TC3xx devices.

## TOC - table of contents
- [Flashing BootModeHeaDers of TC3xx devices]
    - [TOC - table of contents]
    - [Disclaimer and observations]
    - [What BMHD does this script flash?]
    - [Why should I flash a BMHD?]
    - [Using the script]
    - [Porting to a new derivative]

[Flashing BootModeHeaDers of TC3xx devices]: #flashing-bootmodeheaders-of-tc3xx-devices
[TOC - table of contents]: #toc---table-of-contents
[Disclaimer and observations]: #disclaimer-and-observations
[What BMHD does this script flash?]: #what-bmhd-does-this-script-flash
[Why should I flash a BMHD?]: #why-should-i-flash-a-bmhd
[Using the script]: #using-the-script
[Porting to a new derivative]: #porting-to-a-new-derivative
[END_OF_TOC]: here.


## Disclaimer and observations

*WARNING* Flashing invalid BMHDs could lock your device.
You use this example code at your own risk.
Elektrobit Automotive GmbH doesn't accept any responsibility for the effects of these scripts.
This is just example code.

To be pedantic, flashing BMHDs is derivative specific, if you care about lock-step monitoring
(required at least for ASIL-C and ASIL-D),
because the boot-mode header contains the 