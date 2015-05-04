#!/bin/bash

echo "-ev you -F" > in1
echo "-eV you -F" > in2
echo "-a be -F" > in3
echo "-d -F" > in4
echo "-l -F" > in5
echo "-L -F" > in6
echo "-s -F" > in7

for c in `seq 7`
do
  echo "in$c:" `cat in$c`
  echo "./ep3 -fmanifesto.txt.out < in$c > out$c"
  ./ep3 -fmanifesto.txt.out < in$c > out$c
  rm in$c
done
