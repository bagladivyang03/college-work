section .data
    arr dd 12.3,14.2,23.4,16.3,11.5
    point db "."
    plen equ $-point
    divisor dd 5.0
    tent dd 10000.0
    newl db 10
   
%macro operate 4
    mov rax, %1
    mov rdi , %2
    mov rsi ,%3
    mov rdx ,%4
    syscall
%endmacro

section .bss
    mean resd 1
    mean1 rest 1
    count resb 1
    count1 resb 1
    temp resb 1

section .text
    global _start

_start:
    mov rsi ,arr
    mov cx ,05
    fldz
up: fadd dword[rsi]
    add rsi,4
    dec cx
    jnz up
    fdiv dword[divisor]
    fst dword[mean]
    fmul dword[tent]
    fbstp tword[mean1]
    mov rbp ,mean1
    call display
    operate 1,1,newl,1
    operate 60,0,0,0
    display:
    add rbp,9
    mov byte[count],10
    above:
    cmp byte[rbp],00
    je skip
    cmp byte[count],02
    jne print
    operate 1,1,point,plen
    print:
    mov bl,byte[rbp]
    mov byte[count1],2
    againx:
    rol bl,4
    ;rotate by 4
    mov byte[rbp],bl
    and bl,0FH
    cmp bl,09H
    jbe downx
    add bl,07H
downx:add bl,30H
    mov byte[temp],bl
    operate 1,1,temp,1
    ;display result
    mov bl,byte[rbp]
    dec byte[count1]
    jnz againx
    skip:
    dec rbp
    dec byte[count]
    jnz above
    ret

;OUTPUT
   
    mov rax, 60
    mov rdi, 0
    syscall
