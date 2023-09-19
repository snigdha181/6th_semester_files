for arr in a
do 
read a[5]
sum=0
for var in ${a[*]}
do 
sum=$((sum+var))
avg=$((sum/5))
done
done
echo $sum
echo $avg




