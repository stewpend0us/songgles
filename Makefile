
.PHONY: all clean flash shh

all: songles beep hush

clean:
	rm -f *.asm *.cdb *.lk *.map *.rst *.ihx *.lst *.rel *.sym *~

init:
	git submodule init;
	git submodule update;
	cd stm8flash; make; cd ..;

flash: $(OBJECT)
	./stm8flash/stm8flash -c stlinkv2 -p stm8s003f3 -w $(OBJECT).ihx

shh: hush
	make flash OBJECT=hush

%: %.c
	sdcc -lstm8 -mstm8 --out-fmt-ihx $(CFLAGS) $(LDFLAGS) $^
