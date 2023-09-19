declare -a arr
read n
sum=0
for ((i=0; i<n; i++))
do
read arr[$i]
done
for ((i=0; i<n; i++))
do
echo ${arr[$i]}
sum=$((sum+${arr[$i]}))
done
echo "Sum = $sum"
: '
multiple 
line
comment
'
echo "Sum"
