declare -a arr

sum=0

for value in 1 2 3 4 5
do
   read arr[$value]
   sum=$((sum+arr[value]))
   echo "The value is: ${arr[$value]}"
   
   
done
echo "The sum of the array is:$sum "

