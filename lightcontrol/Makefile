CFLAGS=-I ../commonlib

all: lightcontrol

clean:
	rm serial.o lightcontrol.o lightcontrol

lightcontrol: serial.o lightcontrol.o
	gcc -lreadline -o $@ $^

