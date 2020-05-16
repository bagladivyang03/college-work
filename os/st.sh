#!bin/bash
while :
do
	echo "Operations:"
	echo -e "\n-------------\n1: Lowercase to uppercase\n2: Uppercase to Lowercase\n3:exit\n"
	echo "Enter your choice:"
	read ch
	case $ch in
		1) echo "Enter a string"
	   	read str1
	   	result=`echo $str1 | tr '[a-z]' '[A-Z]'`
	   	echo $result
		;;

		2) echo "Enter a string"
	  	read str1
	  	result=`echo $str1 | tr '[A-Z]' '[a-z]'`
	  	echo $result
		;;
		3) exit
		;;
		*) echo -e "Unknown choice\n"
	esac
done
#OUTPUT
#rajat@rajat-HP-ProBook-440-G5:~$ bash asn2.sh
#Operations:

#-------------
#1: Lowercase to uppercase
#2: Uppercase to Lowercase
#3:exit

#Enter your choice:
#1
#Enter a string
#divyang
#DIVYANG
#Operations:

#-------------
#1: Lowercase to uppercase
#2: Uppercase to Lowercase
#3:exit

#Enter your choice:
#2
#Enter a string
#HELLO
#hello
#Operations:

#-------------
#1: Lowercase to uppercase
#2: Uppercase to Lowercase
#3:exit

#Enter your choice:
#3 
