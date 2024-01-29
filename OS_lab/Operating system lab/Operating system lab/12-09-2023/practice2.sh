#C type for
declare -a arr 
echo "Declare array length"
read n
sum=0
for ((i=0; i<n; i++))
do 
  read arr[$i]
  

done
for ((i=0; i<n; i++))
do 
  echo "The value you have given:${arr[$i]}"
  sum=$((sum+arr[i]))

done
echo $sum
