# Makefile
#

SH = bash
all: 
	# Save a lot of Energy
	gcc `pkg-config --cflags gtk+-3.0` clock_main.c `pkg-config --libs gtk+-3.0` -lm



#CFLAGS = `pkg-config --cflags gtk+-3.0`

#LDFLAGS = `pkg-config --libs gtk+-3.0`
#DP= -lm
#all:  clock_main
#clock_main:clock_main.o \ clock.o
#	gcc -c $(CFLAGS) $^ -o $@ $(LDFLAGS) $(DP)
#
#clock_main.o: clock_main.c \ clock.h
#	gcc -c $(CFLAGS) $< -o $@ $(LDFLAGS) $(DP)


#clock.o: clock.c \ clock.h
#	gcc -c $(CFLAGS) $< -o $@ $(LDFLAGS) $(DP)

#.PHONY: clean lint test

#clean:
#	rm -rf *.o
#	rm -rf clock_main.c
#	rm -rf tests/*_

#lint:
#	for f in *.c; do echo $$f; splint -standard $$f; done;



