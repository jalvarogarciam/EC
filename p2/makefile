ASM = $(wildcard *.s)
ATT = $(EXE:=.att)
SRC = main.c sum.c
EXE = $(basename $(ASM)) $(basename $(SRC))
PIE != $(grep 'ID=ubuntu' /etc/os-release > /dev/null && echo '-no-pie')

ASFLAGS = -g -nostartfiles $(PIE)
CFLAGS = -g -Og $(PIE) -Wall # probar -flto -O3

all: att

att: $(ATT)

clean:
	-rm -fv $(ATT) $(EXE) core.* *~

exe: $(EXE)

$(SRC): CFLAGS+=-Og

main: mstore.c
sum: msum.c

%.att: %
	objdump -Cd $< > $@

.PHONY: all att clean exe
