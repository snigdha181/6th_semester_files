
arr[0]=Apple
arr[1]=Banana
arr[2]=Orange

for i in ${!arr[*]}
do
echo " $i ====> ${arr[i]}"
echo "First value is: ${arr[0]}"
echo "Quoted value is: ${arr[*]}"
echo "Quoted value is: ${arr[@]}"
done
