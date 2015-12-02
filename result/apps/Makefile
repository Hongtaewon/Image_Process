CC = gcc
CFLAGS = -g -Wall -I../include
OUTPUT = main

$(OUTPUT): image.o
	$(CC) -o $(OUTPUT) $(CFLAGS) -L../lib image.o -lfuncs `pkg-config --cflags --libs gtk+-2.0` `pkg-config --cflags --libs MagickWand`

image.o : image.c
	$(CC) -o image.o $(CFLAGS) -c image.c `pkg-config --cflags --libs gtk+-2.0` `pkg-config --cflags --libs MagickWand`

clean :
	rm *.o $(OUTPUT)
