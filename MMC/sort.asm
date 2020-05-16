section .data
msg db "the sorted array is",10                          
msglen equ $-msg
arr db 05h,10h,12h,18h,13h              ;array values
newline db 10
%macro rw 4                     ;macro 
mov rax,%1 
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .bss
temp resb 1
res resb 40                    ;resultant string for displaying the array

section .text
global _start
_start:
	rw 1,1,msg,msglen                       
	mov ch,05                           ;outer counter for sorting
up:	mov rsi,arr	
	mov cl,04                           ;inner counter
up1:	mov bl,[rsi]                       
	cmp bl,[rsi+1]                         ;comparing if bl is smaller/ larger than [rsi+1] value 
	jb down1                               ;if smaller   directly goes ahead
	xchg [rsi+1],bl                        ;exchanges value if larger
	mov [rsi],bl
down1:	inc rsi                  
	dec cl
	jnz up1
	dec ch
	jnz up
mov ch,05
mov rsi,res                    
mov rdi,arr
up2:	mov cl,02
	mov al,[rdi]
u1:	rol al,4
	mov bl,al
	and al,0Fh
	cmp al,09h
	jbe d1
	add al,07h
d1:	add al,30h
	mov [rsi],al
	inc rsi
	mov al,bl
	dec cl
	jnz u1
	mov byte[rsi],20h
	inc rsi
	inc rdi
	dec ch
	jnz up2
	rw 1,1,res,20



exit:	mov rax,60
	mov rdi,0
	syscall
