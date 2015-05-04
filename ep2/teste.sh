#!/bin/bash

function tst()
{
  PARAM_D=$1
  PARAM_N=$2
  COUNT=$((COUNT+1))
  echo "Teste $COUNT"
  echo "============"
  echo "./ep02 -D$PARAM_D -N$PARAM_N -M1 -v "
  D=$(./ep02 -D$PARAM_D -N$PARAM_N -M1 -v | grep 'd*(p_1)' | grep -oEi '\.[0-9]+' | sed 's/\.//')
  echo "d*(p_1) = 0.$D"
  echo "--------------"
  #echo "./ep02 -D$PARAM_D -N$PARAM_N -d0.$D"
  #./ep02 -D$PARAM_D -N$PARAM_N -d0.$D
  D=$((D+1))
  echo "./ep02 -D$PARAM_D -N$PARAM_N -d0.$D"
  ./ep02 -D$PARAM_D -N$PARAM_N -d0.$D
  D=$((D-2))
  echo "./ep02 -D$PARAM_D -N$PARAM_N -d0.$D"
  ./ep02 -D$PARAM_D -N$PARAM_N -d0.$D
  echo 
}

make cubo
echo +++++++
echo CUBO
echo +++++++
COUNT=0
tst 2 10 1
tst 3 10 1
tst 5 10 1
tst 7 10 1
tst 11 10 1
tst 100 100 1
tst 1000 1000 1

make esfera
echo ++++++++
echo ESFERA
echo ++++++++
COUNT=0
tst 2 10 1
tst 3 10 1
tst 5 10 1
tst 7 10 1
tst 11 10 1
tst 100 100 1
tst 1000 1000 1
