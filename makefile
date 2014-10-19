CXX=avr-gcc
BOARD=Mega
INCLUDE=-I ../include/$(BOARD)/
LIBS=-L ../lib -lm -l$(BOARD)
MCU=-mmcu=atmega1280
CPU_SPEED=-DF_CPU=16000000UL
CFLAGS=$(MCU) $(CPU_SPEED) -Os -Wall -Wl,--gc-sections -ffunction-sections -fdata-sections
PORT=/dev/tty.usbserial-A603QIKJ
BUILD=build/
SOURCE=./

HEX=$(BUILD)out.hex
ELF=$(BUILD)out.elf

OBJECTS += $(patsubst $(SOURCE)%.cpp,$(BUILD)%.o,$(wildcard $(SOURCE)*.cpp))

default: build

build: $(HEX)

$(HEX): $(ELF)
	avr-objcopy -O ihex $< $@

$(ELF): $(OBJECTS)
	$(CXX) $(CFLAGS) $(INCLUDE) $^ -o $@ $(LIBS)

upload:
	avrdude -F -p m2560 -c stk500v2 -b 115200 -Uflash:w:$(HEX) -P$(PORT)

clean:
	@echo -n Cleaning ...
	$(shell rm $(ELF) 2> /dev/null)
	$(shell rm $(HEX) 2> /dev/null)
	$(shell rm $(BUILD)*.o 2> /dev/null)
	@echo " done"

$(BUILD)main.o: main.cpp 
	$(CXX) $< $(CFLAGS) $(INCLUDE) -c -o $@

$(BUILD)%.o: %.cpp %.h
	$(CXX) $< $(CFLAGS) $(INCLUDE) -c -o $@
