declare -A arr
#arr=(1 2 3 4 5)
arr[asad]=401
arr[emran]=402
arr[siam]=403

for key in ${!arr[@]}
do 
  
  echo "$key ==> ${arr[$key]}"
done
for value in ${arr[@]}
do
echo "$value"
done
