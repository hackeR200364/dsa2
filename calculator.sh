#!/bin/bash

# Function to perform addition
addition() {
    echo -n "Enter the first number: "
    read num1
    echo -n "Enter the second number: "
    read num2
    result=$((num1 + num2))
    echo "Result: $result"
}

# Function to perform subtraction
subtraction() {
    echo -n "Enter the first number: "
    read num1
    echo -n "Enter the second number: "
    read num2
    result=$((num1 - num2))
    echo "Result: $result"
}

# Function to perform multiplication
multiplication() {
    echo -n "Enter the first number: "
    read num1
    echo -n "Enter the second number: "
    read num2
    result=$((num1 * num2))
    echo "Result: $result"
}

# Function to perform division
division() {
    echo -n "Enter the dividend: "
    read num1
    echo -n "Enter the divisor: "
    read num2

    if [ $num2 -eq 0 ]; then
        echo "Error: Division by zero is undefined."
    else
        result=$(awk "BEGIN {printf \"%.2f\", $num1 / $num2}")
        echo "Result: $result"
    fi
}

# Menu
while true; do
    echo "Menu:"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Exit"
    echo -n "Enter your choice (1-5): "
    read choice

    case $choice in
        1) addition ;;
        2) subtraction ;;
        3) multiplication ;;
        4) division ;;
        5) echo "Exiting calculator. Goodbye!"; exit ;;
        *) echo "Invalid choice. Please enter a number between 1 and 5."
    esac
done

#Commands
chmod +x calculator.sh
./calculator.sh
