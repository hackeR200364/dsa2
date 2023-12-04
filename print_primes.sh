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

# Prompt the user to enter the range
echo -n "Enter the starting number of the range: "
read start

echo -n "Enter the ending number of the range: "
read end

# Print prime numbers within the range
echo "Prime numbers between $start and $end are:"
for (( num=$start; num<=$end; num++ )); do
    if is_prime "$num"; then
        echo "$num"
    fi
done

#Commands
chmod +x print_primes.sh
./print_primes.sh
