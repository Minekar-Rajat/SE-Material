
section .text

global main 		;must be declared forlinker (ld)

main: 			;tells linker entry point

_start:	mov edx,len     ;message length
	mov ecx,msg     ;message to write
	mov ebx,1       ;file descriptor (stdout)
	mov eax,4       ;system call number (sys_write)
	int 0x80        ;call kernel
tt1:    nop
	
	mov eax,1	;system call number (sys_exit)
	int 0x80	;call kernel

section .data
msg db 'Hello, world!',0xa; our helloworld string
len equ $ - msg            ;length of our dear string

; To run this progream there are three steps, First;
; $ nasm -f elf64 helloworld.asm
; $ ld -o ass2 helloworld.o
;$ ./ass2         

