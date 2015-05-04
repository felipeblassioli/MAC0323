#!/bin/bash

make clean
make prof
let COUNT=0
for f in `ls in/paca`
do
	let COUNT=COUNT+1
	D_OUT="testes/teste$COUNT"
	F_OUT="$D_OUT/ep01".out
	mkdir $D_OUT
	echo ========= INICIO TESTE $COUNT =========
	echo input: $f
	echo output: $F_OUT
	echo -------------------------------
	echo "./ep01 -D < in/paca/$f &> $F_OUT"
	./ep01 -D < in/paca/$f &> $F_OUT
	tail $F_OUT
	mv gmon.out $D_OUT
	cp ep01 $D_OUT
	echo --------------------------------
	head -n2 ~/ep01/$f
	echo ========== FIM TESTE ===========
	echo
done
