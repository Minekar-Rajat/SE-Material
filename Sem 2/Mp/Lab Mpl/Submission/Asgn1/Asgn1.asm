section .data

array	: dq 0x1111111111111111 , 2222222222222222H , 1234567891012130H , 8910111213141516H , 0x9876543211234567 ,9212121212121212H,0000000000000000H
pos	: db 0
neg	: db 0
count	: db 7
msg1 db   0ah,"Positive Count : "
l1 equ $-msg1	

msg2 db   0ah,"Negative Count : "
l2 equ $-msg2

msg3 db   0ah,"",0ah
l3 equ $-msg3

section .text
global _start 
_start:
	mov rsi,array
	
up:											
	mov rax,qword[rsi]
	BT rax,63
	jc next
	inc byte[pos]
	add rsi,8
	dec byte[count]	
	jnz up
	jmp next2
next:
	inc byte[neg]
	add rsi,8
	dec byte[count]
	jnz up

next2:
	cmp byte[pos],9			
	jbe next3  
	add byte[pos],7
	
				
next3:
	add byte[pos],30H

	cmp byte[neg],9
	jbe next4
	add byte[neg],7

next4:
	add byte[neg],30H

	mov rax,1
	mov rdi,1
	mov rsi,msg1
	mov rdx,l1
syscall

	mov rax,1
	mov rdi,1
	mov rsi,pos
	mov rdx,1
syscall

mov rax,1
	mov rdi,1
	mov rsi,msg2
	mov rdx,l2
syscall

	mov rax,1
	mov rdi,1
	mov rsi,neg
	mov rdx,1
syscall

mov rax,1
	mov rdi,1
	mov rsi,msg3
	mov rdx,l3
syscall

mov rax,60
mov rdi,0
syscall
end:
