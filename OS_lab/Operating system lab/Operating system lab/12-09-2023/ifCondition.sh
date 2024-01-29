i=1
while :
do
     echo $i
     i=$((i+1))
     if [ $i -eq 10 ]
     then 
     break
     fi
done
