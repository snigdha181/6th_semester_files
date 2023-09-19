function hello()
{
   echo "Hello world"
}
hello

function func_name()
{
  #echo "Total Parameter: $#"
  par1=$1
  par2=$2
  
  sum=$((par1+par2))
  echo "Sum= $sum"
}
ret=`func_name 4 3`
echo $ret
res=$((ret + 3))
echo "Total result: $res"


function para()
{
  echo "Parameter: $#"
  echo "$@"
  sum=0
  for i in $@
  do
  sum=$((sum+i))
  #i=$((i+1))
  done
  echo "$sum"
}
para 2 3 4 5 6 7 9 3
