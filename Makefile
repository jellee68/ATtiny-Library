#To use with source with name other than button change TARGET=button
#To use with C instead od C++ in all: change $(TARGET).cpp to $(TARGET).c
  
MCU=attiny84
AVRDUDEMCU=t84
CC=/usr/bin/avr-gcc
CFLAGS=-g -Os -Wall -mcall-prologues -mmcu=$(MCU)
OBJ2HEX=/usr/bin/avr-objcopy
AVRDUDE=/usr/bin/avrdude
TARGET=button


all : 
	$(CC) $(CFLAGS) $(TARGET).cpp -o $(TARGET)
	$(OBJ2HEX) -R .eeprom -O ihex $(TARGET) $(TARGET).hex
	rm -f $(TARGET)

install : all
	sudo gpio -g mode 22 out
	sudo gpio -g write 22 0
	sudo $(AVRDUDE) -p $(AVRDUDEMCU) -P /dev/spidev0.0 -c linuxspi -b 10000 -U flash:w:$(TARGET).hex
	sudo gpio -g write 22 1

noreset : all
	sudo $(AVRDUDE) -p $(AVRDUDEMCU) -P /dev/spidev0.0 -c linuxspi -b 10000 -U flash:w:$(TARGET).hex

fuse :
	sudo gpio -g mode 22 out
	sudo gpio -g write 22 0
	sudo $(AVRDUDE) -p $(AVRDUDEMCU) -P /dev/spidev0.0 -c linuxspi -b 10000 -U lfuse:w:0x62:m -U hfuse:w:0xdf:m -U efuse:w:0xff:m 
	sudo gpio -g write 22 1

erase :
	sudo gpio -g mode 22 out
	sudo gpio -g write 22 0
	sudo avrdude -p $(AVRDUDEMCU) -P /dev/spidev0.0 -c linuxspi -e
	sudo gpio -g write 22 1

clean :
	rm -f *.hex *.obj *.o

