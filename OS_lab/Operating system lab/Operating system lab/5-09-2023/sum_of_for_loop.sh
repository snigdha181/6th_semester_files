var[0]=1
var[1]=2
var[2]=3
var[3]=4
var[4]=5
sum=0
for value in ${var[@]}

do 
   sum=$((sum+value))
   
   
done
echo "The sum of array is: $sum"
