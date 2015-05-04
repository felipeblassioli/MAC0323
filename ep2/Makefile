_OBJ = plist.o dsets.o connected.o emst.o graph.o main.o
IDIR = include
ODIR = obj
CFLAGS = -pedantic -Wall -lm -I$(IDIR)

OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

obj/Point.C.o: src/Point.C.c
	gcc -c -o $@ $^ $(CFLAGS)

obj/Point.S.o: src/Point.S.c
	gcc -c -o $@ $^ $(CFLAGS)

$(ODIR)/%.o: src/%.c
	gcc -c -o $@ $^ $(CFLAGS)

ep01: $(OBJ)
	gcc -o ep02 $^ $(CFLAGS)

prof: $(OBJ)
	gcc -o ep02 $^ -pg $(CFLAGS)

.PHONY: cubo
cubo: $(OBJ) obj/Point.C.o
	gcc -o ep02 $^ $(CFLAGS)

.PHONY: esfera
esfera: $(OBJ) obj/Point.S.o
	gcc -o ep02 $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -r $(ODIR)/*.o
