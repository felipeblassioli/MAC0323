_SRC = point.c grid.c graph.c dsets.c plist.c connected.c emst.c main.c
_OBJ = point.o grid.o graph.o dsets.o plist.o connected.o emst.o main.o
IDIR = include
ODIR = obj
CFLAGS = -pedantic -Wall -lm -I$(IDIR)

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: src/%.c
	gcc -c -o $@ $^ $(CFLAGS)

ep01: $(OBJ)
	gcc -o ep01 $^ $(CFLAGS)

prof: $(OBJ)
	gcc -o ep01 $^ -pg $(CFLAGS)

.PHONY: clean

clean:
	rm -r $(ODIR)/*.o
