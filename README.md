Contiki OS for 6502 based computers is available for four target systems. **Select one of the following links for more information on download and usage** (or learn more on the [history](https://github.com/oliverschmidt/contiki/wiki/History) of Contiki OS):
- The [C64](https://github.com/oliverschmidt/contiki/wiki/C64)
- The [C128 VDC](https://github.com/oliverschmidt/contiki/wiki/C128)
- The [enhanced Apple //e](https://github.com/oliverschmidt/contiki/wiki/Apple-II)
- The [ATARI XL](https://github.com/oliverschmidt/contiki/wiki/ATARI)

Contiki requires Ethernet hardware. There's no support for TCP/IP over serial connections whatsoever in the standard build. There's experimental support for SLIP instead of Ethernet when building with the environment variable `SLIP` defined.

On the C64 and the C128 there are two supported Ethernet devices:
- The [RR-Net](http://wiki.icomp.de/wiki/RR-Net) - emulated by [VICE](http://vice-emu.sourceforge.net/)
- The [ETH64](https://www.ide64.org/eth64.html)

On the Apple //e there are three supported Ethernet cards:
- The [Uthernet](https://web.archive.org/web/20150323031638/http://a2retrosystems.com/products.htm) - emulated by [AppleWin](https://github.com/AppleWin/AppleWin) and [GSport](https://david-schmidt.github.io/gsport/)
- The [LANceGS](https://web.archive.org/web/20010331001718/http://lancegs.a2central.com:80/)
- The [Uthernet II](http://a2retrosystems.com/products.htm)

On the ATARI XL there are two supported Ethernet devices:
- The [Dragon Cart](https://www.atari8ethernet.com/) - emulated by [Altirra](http://www.virtualdub.org/altirra.html)
- The [Dracarys](https://atariage.com/forums/topic/287376-preannouncement-dragon-cart-ii/)
