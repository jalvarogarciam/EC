# Practica 4, Ejercicio 1: evitar las comprobaciones

# Ahorrarse teclear estas instrucciones cada vez
# que se empieza a depurar el programa bomba


# Debido al nombre de fichero "bomba-gdb.gdb"
# se carga automaticamente al ejecutar "gdb bomba"

set write on
layout asm
layout regs
br main


run

#set {char} *(main+165)=0xeb
#set {char} *(main+201)=0xeb
#set {char} *(main+292)=0xeb
#set {char} *(main+328)=0xeb

# Verifica los cambios
#x/i *main+165
#x/i *main+201
#x/i *main+292
#x/i *main+328

quit

BnaAaroOpROCoFlSYRyViexH
HexiVyRY