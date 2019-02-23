install:
	libusb-devel // required by stm8flash
	sdcc // required to build for stm8

run:
	make init // get stm8flash and build it
	make // build the songles program
	make flash // flash the songles program
