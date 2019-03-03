# songgles (sonar goggles)
A project to hopefully help my recently gone blind dog (Navi) stop running into things. It's basically a backup sensor that I plan to install on her face somewhere.

## hardware:
- [sonar](https://www.velleman.eu/products/view/?id=435526)
- [beeper](https://www.velleman.eu/products/view/?id=435552)
- [programmer](https://www.amazon.com/ST-Link-Emulator-Downloader-Programming-Random/dp/B00RYVLN4U)

I removed the beeper from its breakout board and removed the IO pins from the sonar board. The beeper pins were perfectly spaced to fit between the ground and echo pins on the sonar board so I just soldered it directly in. The beeper pin indcated with a + is connected to echo. I also added some bits of wire to the "G", "S", "R", "V" pads on the sonar board. These are connected to the "GND", "SWIM", "RST", and "5.0V" pins on the programmer.

## I'm assuming these things are installed:
- [libusb-dev](https://libusb.info) required by stm8flash
- [sdcc](http://sdcc.sourceforge.net/) required to build for stm8

## do stuff:
```bash
make init #get stm8flash and build it
make #build the songles program
make flash OBJECT=songgles #flash the songles program
```

## helpful links:
- [programming manual](https://www.st.com/content/ccc/resource/technical/document/programming_manual/43/24/13/9a/89/df/45/ed/CD00161709.pdf/files/CD00161709.pdf/jcr:content/translations/en.CD00161709.pdf) instruction set
- [datasheet](https://www.st.com/resource/en/datasheet/stm8s003k3.pdf) register map and interrupt vectors
- [reference manual](https://www.st.com/content/ccc/resource/technical/document/reference_manual/9a/1b/85/07/ca/eb/4f/dd/CD00190271.pdf/files/CD00190271.pdf/jcr:content/translations/en.CD00190271.pdf) register configuration
- [sonar](https://www.velleman.eu/products/view/?id=435526)
- [sonar schematic](https://www.velleman.eu/downloads/29/infosheets/vma306_scheme.pdf)
- [stm8flash](https://github.com/vdudouyt/stm8flash)
- [sdcc stm8 examples](https://github.com/vdudouyt/sdcc-examples-stm8)
- [sdcc mixing c and assembly](https://lujji.github.io/blog/mixing-c-and-assembly-on-stm8/)

## notes:
The advertized range is 2-450cm. That's (roughly) 120-27150microseconds for a round trip. The [sparkfun version](https://cdn.sparkfun.com/assets/b/3/0/b/a/DGCH-RED_datasheet.pdf) claims an "8 cycle sonic burst". That leaves us 15 microseconds per burst if we want to get them all off before we start listening for the echo. I have no idea if that's a resonable amount of time. They have their prescaler (TIM1_PSCR) set to 3 and their ? (TIM1_ARR) set to 48. 1/(16MHz/(3))\*48 = 9microseconds

Timeline:
```
     start                           2cm echo
     |                               |
      _   _   _   _   _   _   _   _
     | |_| |_| |_| |_| |_| |_| |_| |_______________________________________________
     |15-|15-|15-|15-|15-|15-|15-|15-|
     |-------------120m--------------|
```
