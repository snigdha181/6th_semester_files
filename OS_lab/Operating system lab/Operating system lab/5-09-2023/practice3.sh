read arr[100]
sum=0
for value in ${arr[*]}

do 
   sum=$((sum+value))  
done
 echo "The sum of the array is: $sum"

