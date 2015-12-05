AR = ar
CC = gcc
CFLAGS = -g -Wall -I../include
OUTPUT = libfuncs.a
<<<<<<< HEAD
SRCS = resize.c gray.c blur.c sepia.c gamma.c save.c rotatecw.c rotateccw.c negate.c sharped.c
OBJFILES = resize.o gray.o blur.o sepia.o gamma.o save.o rotatecw.o rotateccw.o negate.o sharped.o
=======
SRCS = resize.c gray.c blur.c sepia.c gamma.c save.c rotatecw.c rotateccw.c
OBJFILES = resize.o gray.o blur.o sepia.o gamma.o save.o rotatecw.o rotateccw.o
>>>>>>> 2dea73d1feaf20feb5b678a660a180acf2c8fad0
.PHONY : clean

$(OUTPUT) : $(OBJFILES)
	$(AR) rv $(OUTPUT) $(OBJFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ `pkg-config --cflags --libs gtk+-2.0` `pkg-config --cflags --libs MagickWand`

clean:
	rm -f $(OBJFILES) $(OUTPUT)


