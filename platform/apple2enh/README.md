Apple II
========

The platform/apple2enh/ directory is used for targeting an Enhanced Apple //e
(or compatible) computer. Most things are shared between the 6502-based targets
so please consult cpu/6502/README.md for further details.

The following Apple II Ethernet cards are supported:

- Uthernet:    cs8900a.eth
- Uthernet II: w5100.eth
- LANceGS:     lan91c96.eth

The 'disk' make goal requires AppleCommander 1.3.5 or later. It is available at
http://applecommander.sourceforge.net/.

The apple2enh target supports a PFS that requires much less RAM than the POSIX
file system. However this benefit comes with the following restrictions:

- Only one file may be open at the same time.
- Only read operations are supported but no write operations.
- The files must be located in the same directory the application is located in
  (the ProDOS prefix may very well point to another directory).
- The network MTU size must be set at least to 1265 (the default is 1500).
- No network function may be called while a file is open.
