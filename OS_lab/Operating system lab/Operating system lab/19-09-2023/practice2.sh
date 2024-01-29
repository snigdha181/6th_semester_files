#parameter addition
function FunctionName()
{
  echo "Total Parameter: $#"
  echo "$*"
  for i in $*
  do 
   sum=$((sum+i))
   
  done
  echo $sum
  
  
}

#callig a function
FunctionName 4 7 56 7 89 4 5
