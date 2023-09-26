declare -A arr
arr[cse]=124
arr[eng]=254
arr[ban]=102
arr[eco]=365
m=0
for i in ${arr[@]}
do 
  if [ $m -gt $i ]
  then
   m=$i
   fi
done
for i in ${!arr[@]}
do
if [ $m -eq ${arr[$i]} ]
then
 max=$i
 fi
done
echo "The max value is : $max"
