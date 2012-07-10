Hop!

Winavr burdan: 
	http://sourceforge.net/projects/winavr/files/WinAVR/20100110/ 

Konsol'a once 'make clean' sonra 'make' yazinca, yeni guncel .hex dosyani compile eder.

Program atmak icin de: ( Benim cihazi kullandigini varsayiyorum)

	avrdude -c usbtiny -p t45 -U flash:w:main.hex -U lfuse:w:0xe2:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m

Bu sekilde islemci hizin 8 Mhz oluyor.
	
Fuse ayarlarina bakmak icin:
	http://www.engbedded.com/cgi-bin/fcx.cgi?P_PREV=&P=ATtiny45