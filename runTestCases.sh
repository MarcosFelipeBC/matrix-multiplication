#!/bin/bash

g++ conventionalAlgorithm.cpp || exit 1
./a.out < input1 > outputConventional1
./a.out < input2 > outputConventional2
./a.out < input3 > outputConventional3
./a.out < input4 > outputConventional4
./a.out < input5 > outputConventional5
./a.out < input6 > outputConventional6
./a.out < input7 > outputConventional7
./a.out < input8 > outputConventional8
./a.out < input9 > outputConventional9
./a.out < input10 > outputConventional10

g++ strassenAlgorithm.cpp || exit 1
./a.out < input1 > outputStrassen1
./a.out < input2 > outputStrassen2
./a.out < input3 > outputStrassen3
./a.out < input4 > outputStrassen4
./a.out < input5 > outputStrassen5
./a.out < input6 > outputStrassen6
./a.out < input7 > outputStrassen7
./a.out < input8 > outputStrassen8
./a.out < input9 > outputStrassen9
./a.out < input10 > outputStrassen10

echo "Success! :)"
echo "Conventional Algorithm:"
head -n1 outputConventional1
head -n1 outputConventional2
head -n1 outputConventional3
head -n1 outputConventional4
head -n1 outputConventional5
head -n1 outputConventional6
head -n1 outputConventional7
head -n1 outputConventional8
head -n1 outputConventional9
head -n1 outputConventional10
echo ""
echo "Strassen Algorithm:"
head -n1 outputStrassen1
head -n1 outputStrassen2
head -n1 outputStrassen3
head -n1 outputStrassen4
head -n1 outputStrassen5
head -n1 outputStrassen6
head -n1 outputStrassen7
head -n1 outputStrassen8
head -n1 outputStrassen9
head -n1 outputStrassen10
