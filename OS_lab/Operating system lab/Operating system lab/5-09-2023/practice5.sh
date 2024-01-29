#taking inputs inside an array the way sir did

declare -a arr
#arr=(1 2 3 4 5)
#by default array decleare 

sum=0

for value in 1 2 3 4 5 6
do
   read arr[$value]
   sum=$((sum+value))
   ave=$((sum/6))
   
   
done
echo "The sum of the array is:$sum "
echo "The average of the array is:$ave "


