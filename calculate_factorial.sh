#!/bin/bash

# Function to calculate the factorial of a number
factorial() {
    local num=$1
    if [ $num -eq 0 ] || [ $num -eq 1 ]; then
        echo 1
    else
        echo $((num * $(factorial $((num - 1)))))
    fi
}

# Prompt the user to enter a number
echo -n "Enter a non-negative integer: "
read number

# Check if the entered number is a non-negative integer
if [[ $number =~ ^[0-9]+$ ]]; then
    result=$(factorial "$number")
    echo "The factorial of $number is: $result"
else
    echo "Please enter a valid non-negative integer."
fi

#Commands
chmod +x calculate_factorial.sh
./calculate_factorial.sh
