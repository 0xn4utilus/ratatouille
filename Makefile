.PHONY: all clean start

all:
	$(MAKE) -C src

clean:
	$(MAKE) -C src clean

start:
	$(MAKE) all && $(ZGB_PATH)/../env/bgb/bgb.exe Release/rom.gb