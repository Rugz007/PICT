#!bin/bash 

echo "Enter First Number: "
read a

echo "Enter Second Number: "
read b

if test $a -gt $b
    then
        echo "$a is greater than $b"
elif test $a -lt $b
    then 
        echo "$a is smaller than $b"
else
        echo "$a is equal to $b"
fi