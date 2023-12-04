#!/bin/bash

# Prompt the user to enter a number
echo -n "Enter a positive number: "
read number

# Check if the entered number is positive
if [ $(echo "$number > 0" | bc -l) -eq 1 ]; then
    # Calculate natural logarithm (base e)
    log_e=$(echo "l($number)" | bc -l)
    echo "Natural logarithm (base e) of $number is: $log_e"

    # Calculate base-10 logarithm
    log_10=$(echo "l($number)/l(10)" | bc -l)
    echo "Base-10 logarithm of $number is: $log_10"
else
    echo "Please enter a positive number."
fi

#Commands
chmod +x calculate_log.sh
./calculate_log.sh
