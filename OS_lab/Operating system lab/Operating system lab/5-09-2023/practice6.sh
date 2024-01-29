declare -A arr

arr[asad]=401
arr[bristy]=402
arr[emran]=403

for i in ${!arr[*]}
do
   echo "$i ==> ${arr[$i]} "
done

for val in ${arr[*]}
do
   echo "$val"
done
