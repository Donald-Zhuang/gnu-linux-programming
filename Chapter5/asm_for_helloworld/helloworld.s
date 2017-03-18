.equ sys_exit,  1
.equ sys_wrtie, 4
.equ dev_stdout,1

.section .data
msg:
.ascii "Hello World!\n"
len:
.long .-msg

.section .text
_start:
    movl $sys_wrtie,  %eax
    movl $dev_stdout, %ebx
    movl $msg, %ecx
    movl len, %edx
    int $0x80

    movl $sys_exit, %eax
    movl $0, %ebx
    int $0x80
.global _start

