#!/bin/bash

# Function to check if a number is prime
is_prime() {
    local num=$1
    if [ $num -lt 2 ]; then
        return 1  # Not prime
    fi

    for (( i=2; i*i<=$num; i++ )); do
        if [ $((num % i)) -eq 0 ]; then
            return 1  # Not prime
        fi
    done

    return 0  # Prime
}

# Prompt the user to enter a number
echo -n "Enter an integer: "
read number

# Check if the number is prime
if is_prime "$number"; then
    echo "$number is a prime number."
else
    echo "$number is not a prime number."
fi

#Commands
chmod +x check_prime.sh
./check_prime.sh
