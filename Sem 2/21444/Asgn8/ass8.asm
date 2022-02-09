Section .data
a:db 'a.txt',0
b:db 'b.txt',0
c:db 'c.txt',0
msg:db "file not opened successfully",10
msglen: equ $- msg
Section .bss
%macro scall 4
	mov rax,%1
	mov rdi,%2
	mov rsi,%3
	mov rdx,%4
	Syscall
%endmacro
afd:resq 1
bfd:resq 1
cfd:resq 1
buffer: resb 1000
Section .text
Global main
main:
	
	scall 2,a,2,0777
	mov qword[afd],rax

	scall 2,b,2,0777
	mov qword[bfd],rax

	;scall 2,c,2,0777
	;mov qword[cfd],rax

	scall 0,[afd],buffer,1000
	mov r8,rax
	scall 1,[bfd],buffer,r8

	scall 1,1,buffer,r8

	mov rax,87
	mov rdi,c
	syscall
	
	scall 3,[afd],0,0     ;to close files
	scall 3,[bfd],0,0
	scall 3,[cfd],0,0

	
	scall 2,c,2,0777
	bt rax,63
	jc fo
	jmp ufo
fo:	scall 1,1,msg,msglen

ufo:



	scall 60,0,0,0

