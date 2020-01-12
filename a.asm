%macro st 4 
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data                         
msg db "Enter a string " , 10
msglen equ $-msg
msg1 db "Length of the string is " 
msg1len equ $-msg1
newline db 10
msg2 db "Choose an option" , 10 , "1.Length of the string" , 10 , "2.Print the inputted string" , 10 , "3.Check for palindrome" , 10 , "4.Reverse the string " , 10 , "5.Exit" , 10 
msg2len equ $-msg2 
msg3 db "Inputted string is: "
msg3len equ $-msg3
msg4 db "String is NOT a Palindrome" , 10
msg4len equ $-msg4
msg5 db "String is a Palindrome" , 10
msg5len equ $-msg5
msg6 db "Reverse of the string is: "
msg6len equ $-msg6
msg7 db "Invalid option, Please choose a valid option! " , 10
msg7len equ $-msg7

section .bss
str1 resb 16
len resb 2
opt resb 2
len2 resb 2
str2 resb 16

section .text
global _start
_start:

loop:	st 1,1,msg2,msg2len          ;menu  driven program 
	st 0,0,opt,2                 ;taking the choice 
	jmp l1
l1:	mov dl,byte[opt]             
	cmp dl,31h                   ;comparing the given input choice with nos.
	je leng                      ;jump if the no. is equal to given choice entered
	cmp dl,32h
	je print
	cmp dl,33h
	je palin
	cmp dl,34h
	je rev
	cmp dl,35h
	je exit
	jmp e1                      ;if user enters any no. other than in menu given then to print ivalid option!!

leng:	st 1,1,msg,msglen
	st 0,0,str1,16
	dec al                      ;decrement al to get actual length 
	cmp al,09h                  ;comparing if length is between 1 to 9
	jbe down      
	add al,07h                    
down:	add al,30h
	mov byte[len],al
	st 1,1,msg1,msg1len
	st 1,1,len,2
	st 1,1,newline,1
	jmp loop
print:	st 1,1,msg,msglen
	st 0,0,str1,16
	st 1,1,msg3,msg3len
	st 1,1,str1,16
	jmp loop
palin:	st 1,1,msg,msglen
	st 0,0,str1,16
	dec al
	mov byte[len2],al
	mov rsi,str1                 ;rsi pointing at 1st position
	mov rdi,str1                 ;rdi also pointing same at beginning
	mov rcx,00h
	mov byte[len],al
	mov cl,byte[len]
	add rdi,rcx
	dec rdi                     ;now rdi pointing at last postion
	mov ch,byte[len2]
	shr ch,01h                  ;dividing cl by 2 for that no. of comparisons
up2:	mov bl,[rsi]
	cmp bl,[rdi]                ;comparing charchters are they same
	jne notap
	inc rsi                     
	dec rdi
	dec ch
	jnz up2
	st 1,1,msg5,msg5len
	st 1,1,newline,1
	jmp loop
notap:	st 1,1,msg4,msg4len
	st 1,1,newline,1
	jmp loop 

rev :	st 1,1,msg,msglen
	st 0,0,str1,16
	dec al
	mov byte[len2],al
	mov cl,byte[len2]
	mov rsi,str1
	mov rbp,str2              ; a pointer pointeing to a new string which will be reversed 
up3:	inc rsi
	dec cl
	jnz up3
	dec rsi
	mov ch,byte[len2]
down3:	mov bl,[rsi]
	mov [rbp],bl
	dec rsi
	inc rbp
	dec ch
	jnz down3
	st 1,1,msg6,msg6len
	st 1,1,str2,16
	st 1,1,newline,1
	jmp loop

e1:	st 1,1,msg7,msg7len               ;for invalid option
	jmp loop

exit:	mov rax,60
	mov rdi,0
	syscall



;OUTPUT:
;Choose an option
;1.Length of the string
;2.Print the inputted string
;3.Check for palindrome
;4.Reverse the string 
;5.Exit
;1
;Enter a string 
;mitwpu
;Length of the string is 6
;Choose an option
;1.Length of the string
;2.Print the inputted string
;3.Check for palindrome
;4.Reverse the string 
;5.Exit
;2
;Enter a string 
;mitwpu
;Inputted string is: mitwpu
;Choose an option
;1.Length of the string
;2.Print the inputted string
;3.Check for palindrome
;4.Reverse the string 
;5.Exit
;3
;Enter a string 
;madam
;String is a Palindrome

;Choose an option
;1.Length of the string
;2.Print the inputted string
;3.Check for palindrome
;4.Reverse the string 
;5.Exit
;4
;Enter a string 
;mitwpu
;Reverse of the string is: upwtim
;Choose an option
;1.Length of the string
;2.Print the inputted string
;3.Check for palindrome
;4.Reverse the string 
;5.Exit
;7
;Invalid option, Please choose a valid option! 
;Choose an option
;1.Length of the string
;2.Print the inputted string
;3.Check for palindrome
;4.Reverse the string 
;5.Exit
;3
;Enter a string 
;assa
;String is a Palindrome

;Choose an option
;1.Length of the string
;2.Print the inputted string
;3.Check for palindrome
;4.Reverse the string 
;5.Exit

