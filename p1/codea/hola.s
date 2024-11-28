.data
msg:    .string "¡hola, mundo!\n"
mosg:   .string "adios, mundo"
tam:    .quad . - msg

.text
_start: .globl _start
        call  write       # llamada a función
        call  exit        # llamada a función

write:  mov   $1,   %rax  # write
        mov   $1,   %rdi  # stdout
        mov   $msg, %rsi  # texto
        mov   tam,  %rdx  # tamaño
        syscall           # llamada a write
        ret

exit:   
        add $200, %rsp
        ret
