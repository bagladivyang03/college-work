#!/bin/bash

add()
{
	echo "Enter a:"
	read a
	echo "Enter b:"
	read b
	c=`expr $a + $b `
	echo $c
} 

sub()
{
	echo "Enter a:"
	read a
	echo "Enter b:"
	read b
	c=`expr $a - $b `
	echo $c
} 

mul()
{
	echo "Enter a:"
	read a
	echo "Enter b:"
	read b
	c=`expr $a \* $b `
	echo $c
} 

div()
{
	echo "Enter a:"
	read a
	echo "Enter b:"
	read b
	c=`echo "scale=2;$a/$b" |bc -l`
	echo $c
} 


ch=10

while [ $ch -ne 0 ]
do
	echo "Enter a choice to perform an operation:-"
	echo "1.Addition."
	echo "2.Subtraction."
	echo "3.Multiplication."
	echo "4.Division."
	echo "0.Exit"
	read ch
	case $ch in
		1) add;;
		2) sub;;
		3) mul;;
		4) div;;
		*) echo "default"
	esac	
done 
#OUTPUT
#rajat@rajat-HP-ProBook-440-G5:~/Downloads$ bash menu_sh
#Enter a choice to perform an operation:-
#1.Addition.
#2.Subtraction.
#3.Multiplication.
#4.Division.
#0.Exit
#1
#Enter a:
#12
#Enter b:
#13
#25
#Enter a choice to perform an operation:-
#1.Addition.
#2.Subtraction.
#3.Multiplication.
#4.Division.
#0.Exit
#2
#Enter a:
#12
#Enter b:
#10
#2
#Enter a choice to perform an operation:-
#1.Addition.
#2.Subtraction.
#3.Multiplication.
#4.Division.
#0.Exit
#3
#Enter a:
#12
#Enter b:
#13
#156
#Enter a choice to perform an operation:-
#1.Addition.
#2.Subtraction.
#3.Multiplication.
#4.Division.
#0.Exit
#4
#Enter a:
#12
#Enter b:
#6
#2.00
#Enter a choice to perform an operation:-
#1.Addition.
#2.Subtraction.
#3.Multiplication.
#4.Division.
#0.Exit
#0
#default
