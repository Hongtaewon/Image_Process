AR = ar
CC = gcc
CFLAGS = -g -Wall -I../include
OUTPUT = libfuncs.a
SRCS = resize.c gray.c blur.c sepia.c gamma.c save.c rotatecw.c rotateccw.c negate.c sharped.c sketch.c poster.c flop.c flip.c polaroid.c swirl.c wave.c
OBJFILES = resize.o gray.o blur.o sepia.o gamma.o save.o rotatecw.o rotateccw.o negate.o sharped.o sketch.o poster.o flop.o flip.o polaroid.o swirl.o wave.o
.PHONY : clean

$(OUTPUT) : $(OBJFILES)
	$(AR) rv $(OUTPUT) $(OBJFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ `pkg-config --cflags --libs gtk+-2.0` `pkg-config --cflags --libs MagickWand`

clean:
	rm -f $(OBJFILES) $(OUTPUT)


