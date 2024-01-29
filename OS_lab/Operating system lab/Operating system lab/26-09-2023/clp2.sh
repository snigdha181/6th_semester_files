declare -A arr

#arr[$key]=$value
echo "Enter the array inputs: "
for i in cse eng ban eco
do 
  read arr[i]
done
 max=$arr[cse]
for j in ${!arr[*]}
do 
  if [ ${arr[j]} > $max ]
  then 
    max=${arr[j]}
  fi
done
echo "The maximum value: $j"
  

