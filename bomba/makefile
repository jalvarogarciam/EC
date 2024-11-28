all: bomba.c
	gcc -Og bomba.c -o bomba -no-pie -fno-stack-protector -fno-reorder-blocks
	gcc -Og bomba_random.c -o bomba_random -no-pie -fno-stack-protector -fno-reorder-blocks -lm