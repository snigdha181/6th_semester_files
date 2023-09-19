declare -A arr
sum=0
for var in 0 1 2
do
read arr[$var]
echo $var
sum=$((sum+${arr[$var]}))
done
echo "Sum= $sum"
