#################################################
# printf32e.s
# gcc -m32 printf32e.s -o printf32e
#################################################

.extern exit       # exit en otro sitio
.extern printf     # printf en otro sitio
.globl main        # función principal
.globl _start
#################################################

.data
i:      .int 12345         # variable entera
f:      .string "i = %d\n" # cadena de formato

#################################################

.text

_start:	
	call main
main:   push i             # apila i
        push $f            # apila f
        call printf        # llamada a función
        add  $8, %esp      # restaura pila

        push $0            # 0
        call exit          # llamada a función

#################################################
