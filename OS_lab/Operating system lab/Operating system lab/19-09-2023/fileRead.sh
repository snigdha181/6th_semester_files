read_file='Function.sh'
while read line;
do 
echo "$line"
done < $read_file

#cat Function.sh #to print line of the text file

read_file='test.txt'
while read line;
do 
echo "$line"
done < $read_file

cat test.txt #default function to show line in the file
chmod +x Function.sh
bash Function.sh
