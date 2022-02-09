section .data

msg: db 10, "Enter",10
     db "1.Successive Addition", 10
     db "2. Add and Shift", 10
     db "Exit", 10

len_msg: equ $-msg

msg1: db  "Enter a number :",10
len_msg1: equ $-msg1

count: db 00
count2: db 00

section .bss

num: resb 2
num1: resb 3
num2: resb 3
result: resb 8
choice: resb 2

%macro scall 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .text
global _start
_start:

scall 1,1,msg,len_msg
scall 0,1,choice,2

cmp byte[choice], 31H
je first


cmp byte[choice], 32H
je second


cmp byte[choice], 33H
je exit

first:
call SA
jmp _start

second:
call AddShift
jmp _start

SA:
scall 1,1,msg1,len_msg1
scall 0,1,num1,3

scall 1,1,msg1,len_msg1
scall 0,1,num2,3
mov rax, 00

mov ax, word[num1]
mov word[num], ax
call AtoH

mov word[num1], bx

mov ax, word[num2]
mov word[num], ax
call AtoH

mov word[count], bx
mov rax, 00

loop:
add ax, word[num1]
dec byte[count]
jnz loop

mov rdx, rax
call HtoA

ret

AddShift:
scall 1,1,msg1,len_msg1
scall 0,1,num1, 3

scall 1,1,msg1,len_msg1
scall 0,1,num2, 3

ret

AtoH:
mov rsi, num
mov byte[count2], 2
mov bx, 00
up2:
rol bx, 04
mov dl, byte[rsi]
cmp dl, 39H
jbe next2
sub dl, 07H
next2:
sub dl, 30H
add bl, dl
inc rsi
dec byte[count2]
jnz up2
ret




HtoA:
mov rsi, result
mov byte[count], 4
up:
rol dx, 04
mov cl, dl
and cl, 0FH
cmp cl, 09H
je next
add cl, 07H
next:
add cl, 30H
mov byte[rsi], cl
inc rsi
dec byte[count]
jnz up

scall 1,1,result,8
ret

exit:
mov rax, 60
mov rdi, 0
syscall