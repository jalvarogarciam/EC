.section .data
lista:		.int 1,2,10,  1,2,0b10,  1,2,0x10
longlista:	.int   (.-lista)/4
resultado:	.int   0
formato: 	.asciz	"suma = %u = 0x%x hex\n"

# opción: 1) no usar printf, 2)3) usar printf/fmt/exit, 4) usar tb main
# 3) gcc suma.s -o suma -no-pie –nostartfiles		6544 B
# 4) gcc suma.s -o suma	-no-pie				8664 B

.section .text
# _start: .global _start
.global  main
main:
	call trabajar	# subrutina de usuario
    mov $formato, %rdi       # Cadena de formato en %rdi
    mov resultado, %esi      # Primer argumento en %esi
    mov resultado, %esi      # Segundo argumento en %edx (corregido)
    xor %eax, %eax           # RAX debe ser 0 para printf
    call printf              # Llamada a printf

    # Salir del programa
    mov $60, %rax            # syscall: exit
    xor %rdi, %rdi           # estado de salida 0
    syscall
	ret

trabajar:
	mov     $lista, %rbx
	mov  longlista, %rbp
	call suma		# == suma(&lista, longlista);
	mov  %eax, resultado
	mov  %edx, resultado+4
	ret

suma:
	mov  $0, %r13d
	mov  $0, %r12d
	mov  $0, %rcx

bucle:
	mov  (%rbx,%rcx,4), %eax
	cltd
	add %eax, %r13d
	adc  %edx, %r12d
	inc   %rcx
	cmp   %rcx, %rbp
	jnc   bucle

division:
	mov %r13d, %eax
	mov %r12d, %edx
	idiv %ebp	# %eax=cociente, %edx=resto
	ret




imprim_C:
	mov   $formato,  %rdi
	mov   resultado, %rsi
	mov   resultado, %rdx
	xor   %eax, %eax	# varargin sin xmm
	call  printf		# == printf(formato, res, res);
	ret


acabar_C:			# requiere libC
	mov  $0, %edi
	call _exit		# ==  exit(resultado)
	ret
