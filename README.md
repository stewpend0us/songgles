
songles or sonar goggles
is a project to hopefully help my recently gone blind dog (Navi) stop running into things. It's basically a backup sensor that I plan to install on her face somewhere.

hardware:
	sonar
	beeper
	programmer

install:
	libusb-devel // required by stm8flash
	sdcc // required to build for stm8

run:
	make init // get stm8flash and build it
	make // build the songles program
	make flash // flash the songles program
