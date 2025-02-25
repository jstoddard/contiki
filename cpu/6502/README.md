6502
====

The cpu/6502/ directory is used for targeting 6502-based machines using the
cc65 compiler [https://cc65.github.io/](https://cc65.github.io/).

The Contiki network configuration for 6502-based targets is loaded from a
binary configuration file (by default named contiki.cfg). It has the following
format for Ethernet:

- Bytes  1 -  4: IP Address     (HiByte first)
- Bytes  5 -  8: Subnet Mask    (HiByte first)
- Bytes  9 - 12: Default Router (HiByte first)
- Bytes 13 - 16: DNS Server     (HiByte first)
- Bytes 17 - 18: Ethernet device driver param (LoByte first !)
- Bytes 19 - xx: Ethernet device driver name (ASCII / PETSCII)

It has the following format for SLIP (based on RS232 driver coming with cc65):

- Bytes  1 -  4: IP Address     (HiByte first)
- Bytes  5 -  8: Subnet Mask    (HiByte first)
- Bytes  9 - 12: Default Router (HiByte first)
- Bytes 13 - 16: DNS Server     (HiByte first)
- Bytes 17 - 21: struct ser_params (see cc65 serial.h)

The build for 6502-based machines includes the 'disk' make goal which creates a
bootable floppy disk image containing the project binary, a sample
configuration file and the Ethernet card drivers.

The build for 6502-based machines supports so-called high-level configuration
macros which allow to customize Contiki on a per-project basis. They are set in
form of a comma-separated list as value of the make variable DEFINES on the
make command line. The value of DEFINES can be saved with the 'savedefines'
make goal. The values of the high-level configuration macros are not tracked by
the build so a manual rebuild is necessary on any change. The following
high-level configuration macros may be set:

- WITH_SLIP
    - Default: 0
    - Purpose: Use SLIP (based on RS232 driver coming with cc65) instead of
      Ethernet.

- MTU_SIZE
    - Default: 1500
    - Purpose: Set the Maximum Transfer Unit size.

- CONNECTIONS
    - Default: 2
    - Purpose: Set the maximum number of concurrent TCP connections.

- STATIC_DRIVER
    - Default: N/A
    - Purpose: Link device driver statically instead of loading it dynamically
      using the network configuration file.

- WITH_LOGGING
    - Default: 0
    - Purpose: Have log_message() and UIP_LOG() write messages to the screen.

- WITH_BOOST
    - Default: 0
    - Purpose: Significantly improve troughput on sending full sized packets by
      splitting them thus workarounding the "delayed acknowledge".

- WITH_FORWARDING
    - Default: 0
    - Purpose: Enable support for the 'IP forwarding' packet driver.

- WITH_CLIENT
    - Default: 0
    - Purpose: Enable support for outgoing TCP connections.

- WITH_DNS
    - Default: 0
    - Purpose: Enable UDP support and initialize resolver process on startup.

- WITH_80COL
    - Default: 0
    - Purpose: Enable 80 column screen.

- WITH_GUI
    - Default: 0
    - Purpose: Initialize the CTK process on startup.

- WITH_MOUSE
    - Default: 0
    - Purpose: Enable CTK mouse support and load a mouse driver.

- STATIC_MOUSE
    - Default: N/A
    - Purpose: Link mouse driver statically instead of loading it dynamically.

- WITH_ARGS
    - Default: 0
    - Purpose: Enable support for contiki_argc / contiki_argv.

- WITH_PFS
    - Default: 0
    - Purpose: Implement the CFS interface with a Platform-specific File System
      instead of the POSIX file system.
