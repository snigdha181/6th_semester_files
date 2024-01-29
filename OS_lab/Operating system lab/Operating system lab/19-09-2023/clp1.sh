declare -a arr

arr=(1 6 5 8 2 6 9)
max=1

for i in ${arr[*]}
do 
if [ $i -gt $max ]
then 
   max=$i
 fi
done
echo "The maximum value is: $max"


