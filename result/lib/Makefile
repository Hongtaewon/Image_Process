AR = ar
CC = gcc
CFLAGS = -g -Wall -I../include
OUTPUT = libfuncs.a
SRCS = resize.c
OBJFILES = resize.o
.PHONY : clean

$(OUTPUT) : $(OBJFILES)
	$(AR) rv $(OUTPUT) $(OBJFILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ `pkg-config --cflags --libs MagickWand`

clean:
	rm -f $(OBJFILES) $(OUTPUT)


