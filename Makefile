
.PHONY: all clean flash

all: songles.ihx

clean:
	rm -f *.asm *.cdb *.lk *.map *.rst *.ihx *.lst *.rel *.sym *~

init:
	git submodule init;
	git submodule update;
	cd stm8flash; make; cd ..;

flash: songles.ihx
	./stm8flash/stm8flash -c stlinkv2 -p stm8s003f3 -w songles.ihx

songles.ihx: songles.c
	sdcc -lstm8 -mstm8 --out-fmt-ihx $(CFLAGS) $(LDFLAGS) $^
