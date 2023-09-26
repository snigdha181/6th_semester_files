n=(5 6 9 1 2)
l=${#n[*]}

for ((i=0; i < l - 1; i++));
do
  for ((j=0; j < l - i - 1; j++));
  do 
    if [[ ${n[j]} -gt ${n[j+1]} ]];
    then
      temp=${n[j]}
      n[j]=${n[j+1]}
      n[j+1]=$temp
    fi
  done
done

echo "Sorted array"
for (( i=0; i<l; i++ ));
do
  echo ${n[i]}
done
