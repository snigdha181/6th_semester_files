#Math Operation using Expression

a=5
b=4

sum=`expr $a + $b`
echo "The sum is: $sum"

sub=`expr $a - $b`
echo "The subraction is: $sub"

div=`expr $a / $b`
echo "The division is: $div"

mul=`expr $a \* $b`         # \* uses for multiplication
echo "The multiplication is: $mul"
