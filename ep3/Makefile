_SRC = Metadata.c Sentence.c print.c utils.c Item.c Item2.c llrb.c llrb2.c main.c
_OBJ = Metadata.o Sentence.o print.o utils.o Item.o Item2.o llrb.o llrb2.o main.o
IDIR = include
ODIR = obj
CFLAGS = -ansi -pedantic -Wall -lm -I$(IDIR)

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: src/%.c
	gcc -c -o $@ $^ $(CFLAGS)

ep3: $(OBJ)
	gcc -o ep3 $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -r $(ODIR)/*.o
