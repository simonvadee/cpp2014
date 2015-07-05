#!/bin/bash
## toto.sh for abstract tests in /home/girard_r/rendu/cpp_abstractvm
## 
## Made by Aurélien GIRARDEAU
## Login   <girard_r@epitech.net>
## 
## Started on  Tue Feb 24 16:00:20 2015 Aurélien GIRARDEAU
## Last update Sat Feb 28 16:54:11 2015 Aurélien GIRARDEAU
##

make re

test_dir="./sources/tests"
test_files=("fileTest1.avm" "fileTestOverFlow_1.avm" "fileTestOverFlow_2.avm" "OverflowFloat.avm" "fileTestOverFlowInsert.avm" "TestAssert.avm" "fileTestDivisonPerZero.avm" "fileTestPopEmptyStack.avm" "fileTestAssertEmptyStack" "fileTestWrongAssert" "fileTestNotEnoughValues.avm" "fileTestMissingArgument.avm" "fileTestUnknownType.avm" "fileTestRealTestV1.avm")

cmp=0;
 
while [ $cmp -lt ${#test_files[*]} ]
do
    read -p "Launch Test number $cmp : ${test_files[$cmp]} ? (y/n)" -n 1 -r
    echo
    if [[ $REPLY =~ ^[Yy]$ ]]
    then
    filepath=$(echo "$test_dir/${test_files[$cmp]}")
    echo -e "\033[31mTEST $cmp : ${test_files[$cmp]}\033[0m"
    cat $filepath
    echo -e "\033[35mAprès execution : \033[0m"
    ./avm $filepath
    fi
    echo ""
    ((cmp++))
done
