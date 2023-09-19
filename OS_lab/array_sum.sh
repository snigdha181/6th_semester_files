arr[0]=1
arr[1]=2
arr[2]=6
arr[3]=4
arr[4]=9

for var in ${arr[*]}
do
sum=$(($sum+$var))
done
echo "Sum = $sum"

read a[6]
add=0
for i in ${a[*]}
do
add=$((add+i))
done
echo "Sum= $add"
