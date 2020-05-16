section .data
    gmsg db 10,10,"The contents of GDTR are: "
    gmsg_len equ $-gmsg
    lmsg db 10,10,"The contents of LDTR are: "
    lmsg_len equ $-lmsg
    imsg db 10,10,"The contents of IDTR are: "
    imsg_len equ $-imsg
    tmsg db 10,10,"The contents of TR are: "
    tmsg_len equ $-tmsg
    mmsg db 10,10,"The contents of MSW/CR0 are: "
    mmsg_len equ $-mmsg
    pro db 10,10,"The processor is in protected mode "
    pro_len equ $-pro
    real db 10,10,"The processor is in real mode "
    real_len equ $-real
    col db " : "
    col_len equ $-col
    nline db 10,10
    nlen equ $-nline

section .bss
    buff resb 4
    gdt1 resb 6
    idt1 resb 6
    ldt1 resw 1
    t1 resb 2
    msw1 resb 4
%macro display 4
    mov rax,%1
    mov rdi,%2
    mov rsi,%3
    mov rdx,%4
    syscall
%endmacro

section .text
    global _start
    _start:
    smsw eax             ;store machine status word in eax
    mov[msw1],eax       ;mov eax to msw1 location i.e msw1 variable
    bt eax, 0           ;copies bit 0 from eax to carry flag 
    jc protected           ;if that bit 1 then it is protected mode 
    display 1,1,real,real_len
    jmp end
protected:
    display 1,1,pro,pro_len
    sgdt [gdt1]               ; store gdt
    sldt [ldt1]               ; store ldt 
    sidt [idt1]               ; store idt    
    str [t1]                  ; store tr 
    display 1,1,gmsg,gmsg_len
    mov bx,[gdt1+4]              ;accessing the 5th and 6th byte 
    call original_ascii
    mov bx,[gdt1+2]              ;accessing the 3th and 4th byte
    call original_ascii
    display 1,1,col,col_len
    mov bx,[gdt1]                ;accessing the 1st and 2nd byte
    call original_ascii
    
    display 1,1,lmsg,lmsg_len
    mov bx,[ldt1]
    call original_ascii
    
    display 1,1,imsg,imsg_len
    mov bx,[idt1+4]
    call original_ascii
    mov bx,[idt1+2]
    call original_ascii
    display 1,1,col,col_len
    mov bx,[idt1]
    call original_ascii
    
    display 1,1,tmsg,tmsg_len
    mov bx,[t1]
    call original_ascii
    
    display 1,1,mmsg,mmsg_len
    mov bx,[msw1+2]
    call original_ascii
    mov bx,[msw1]
    call original_ascii
end:
    display 1,1,nline,nlen
    display 60,0,0,0

original_ascii:          ; procedure for displaying the contents 
    mov rax,0 
    mov rcx,4 
    mov rdi,buff
up2:rol bx,4
    mov dl,bl 
    and dl,0fH
    cmp dl,09H
    jbe down2
    add dl,07H
down2:add dl,30H
    mov [rdi],dl
    inc rdi
    dec rcx
    jnz up2
    display 1,1,buff,4
ret 

