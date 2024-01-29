function FunctionName()
{
  #echo "Total Parameter: $#"
  par1=$1
  par2=$2
  sum=$((par1+par2))
  #sum=$par1+$par2
  echo $sum
  
}

#callig a function
ret=`FunctionName 4 7`
echo $ret
res=$((ret+3))
echo $res
 #now calling the function using the function name and sending parameter
