section .data
msg1 db "File operations!",10
msg1len equ $-msg1
msg db "Error!"
msglen equ $-msg

section .bss
fname1 resb 20
fhd1 resq 1
fname2 resb 20
fhd2 resq 1
buff resb 512

%macro rw 4
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro

section .txt
global _start
_start:
rw 1,1,msg1,msg1len
pop r8
cmp r8,3
jne down1
pop r8
pop r8
mov rsi,fname1
    up1: mov bl,[r8]
cmp bl,00
je next
mov [rsi],bl
inc rsi
inc r8
jmp up1
   down1:rw 1,1,msg,msglen
   next:
pop r8
mov rsi,fname2
   up2:  mov bl,[r8]
cmp bl,00
je next1
mov[rsi],bl
inc rsi
inc r8
jmp up2
   next1:
    rw 2,fname1,0q,0777q ;open file abc  in read mode
mov [fhd1],rax       ;once file is opened file handle is returned in rax
rw 85,fname2,0777q,0
rw 2,fname2,2q,0777q ;open file xyz in write mode
mov[fhd2],rax

;READ FILE
  rw 0,qword[fhd1],buff,512

;WRITE FILE
rw 1,qword[fhd2],buff,512

mov rax,60
mov rdi,0
syscall
