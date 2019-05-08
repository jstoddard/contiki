Commodore 64
============

The platform/c64/ directory is used for targeting a Commodore 64 computer.
Most things are shared between the 6502-based targets so please consult
cpu/6502/README.md for further details.

The following C64 Ethernet cards are supported:

- RR+RR-Net: cs8900a.eth
- ETH64:     lan91c96.eth

The 'disk' make goal requires the c1541 tool from VICE. It is available at
http://vice-emu.sourceforge.net/.

The c64 target supports a PFS that requires less RAM than the POSIX file system
and converts UNIX path names to CMD syntax for CMD drives and IDEDOS 0.90+. Its
primary feature however is support for IDE64 fast read/write.
