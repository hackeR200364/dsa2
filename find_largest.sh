#!/bin/bash

# Prompt the user to enter three integers
echo -n "Enter the first integer: "
read num1

echo -n "Enter the second integer: "
read num2

echo -n "Enter the third integer: "
read num3

# Find the largest number
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]; then
    largest=$num1
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]; then
    largest=$num2
else
    largest=$num3
fi

# Display the result
echo "The largest number among $num1, $num2, and $num3 is: $largest"

#Commands
chmod +x find_largest.sh
./find_largest.sh
