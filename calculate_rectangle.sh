#!/bin/bash

# Prompt the user to enter the length of the rectangle
echo -n "Enter the length of the rectangle: "
read length

# Prompt the user to enter the breadth of the rectangle
echo -n "Enter the breadth of the rectangle: "
read breadth

# Calculate the area and perimeter
area=$(echo "$length * $breadth" | bc)
perimeter=$(echo "2 * ($length + $breadth)" | bc)

# Display the results
echo "The area of the rectangle is: $area"
echo "The perimeter of the rectangle is: $perimeter"
