#taking input inside the for loop



for value in arr

do 
   read arr[5]
   sum=0
for val in ${arr[*]}
  do 
   sum=$((sum+val)) 
   average=$((sum/5)) 
done
done
 echo "The sum of the array is: $sum"
 echo "The average of the array is: $average"

