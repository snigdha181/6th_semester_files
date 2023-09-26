numbers="1 6 5 8 2 6 9 5 8"

# Initialize a variable to store the maximum number
max=0
for num in $numbers; do
    # Compare the current number with the maximum
    if [ $num -gt $max ]; then
        max=$num
    fi
done

# Print the maximum number
echo "The maximum number is: $max"
