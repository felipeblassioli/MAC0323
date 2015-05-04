#!/bin/bash

make clean
make prof

# Parte 1
echo "./ep01 -N100 -d0.1 > tstN100d01"
./ep01 -N100 -d0.1 > tstN100d01
mv gmon.out tstN100d01.prof
echo "./ep01 -N1000 -d0.01 -s323 > tstN1000d001s323"
./ep01 -N1000 -d0.01 -s323 > tstN1000d001s323
mv gmon.out tstN1000d001s323.prof
echo "./ep01 -N10000 -d0.001 -s323 -v > tstN10000d001s323v"
./ep01 -N10000 -d0.001 -s323 -v > tstN10000d001s323v
mv gmon.out tstN10000d001s323v.prof

# Parte 2
echo "./ep01 -N100 -M1 > tstN100M1"
./ep01 -N100 -M1 > tstN100M1
mv gmon.out tstN100M1.prof
echo "./ep01 -N1000 -M100 -s323 > tstN1000M100s323"
./ep01 -N1000 -M100 -s323 > tstN1000M100s323
mv gmon.out tstN1000M100s323.prof
echo "./ep01 -N1000 -M100 -s323 -v > tst1000s323v"
./ep01 -N1000 -M100 -s323 -v > tst1000s323v
mv gmon.out tst1000s323v.prof
echo "./ep01 -N20 -M5 -s323 -V > tstN20M5s323V"
./ep01 -N20 -M5 -s323 -V > tstN20M5s323V
mv gmon.out tstN20M5s323V.prof

mv tst* testes
cp ep01 testes
