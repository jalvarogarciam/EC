// gcc -Og bomba.c -o bomba -no-pie -fno-stack-protector -fno-reorder-blocks
#undef  _FORTIFY_SOURCE
#define _FORTIFY_SOURCE 0

#include <stdio.h>	// para printf(), fgets(), scanf(), clearerr(stdin)
#include <stdlib.h>	// para exit()
#include <string.h>	// para strncmp()
#include <sys/time.h>	// para gettimeofday(), struct timeval
#include <time.h>
#include <math.h>


#define SIZE 16
#define TLIM 5




void boom(char * password, int passcode){
	printf(	"\n"
		"***************\n"
		"*** BOOM!!! ***\n"
		"***************\n"
		"pwd = %s\npin = %i\n", password, passcode);
	exit(-1);
}

void defused(void){
	printf(	"\n"
		"...........................\n"
		".... bomba desactivada ....\n"
		"...........................\n"
		"\n");
	exit(0);
}

char * random_pwd(size_t size_min, size_t size_max){
	srand(time(NULL)); // Inicializa la semilla del generador de números aleatorios
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

	int size = size_min + (rand()%(size_max-size_min-1));
	char * pwd = (char *)malloc((size+1) * sizeof(char)); // +1 para el carácter nulo
	for (size_t i = 0; i < size-1; i++) pwd[i] = charset[rand()%strlen(charset)];
	pwd[size-2]='\n'; pwd[size-1]=0;
	return pwd;
}
int random_psc(size_t min_digits, size_t max_digits){
	int size = min_digits + (rand()%(max_digits-min_digits+1));
	int psc = 0;
	for (size_t i = 0; i < size-1; i++) psc += (rand()%10)*pow(10,i);
	return psc;
}


int main(){
	char *password= random_pwd(4,SIZE);	// contraseÃ±a
	int  passcode  = random_psc(1,5);			// pin
	char pw[SIZE];
	int  pc, n;

	struct timeval tv1, tv2;	// gettimeofday() secs-usecs
	gettimeofday(&tv1, NULL);

	do	printf("\nIntroduce la contraseña: ");
	while (	clearerr(stdin),	// EOF (Ctrl-D)
		fgets(pw, SIZE, stdin) == NULL      );
	if    (	strncmp(pw,password,sizeof(password)) )
		boom(password, passcode);

	gettimeofday(&tv2, NULL);
	if    ( tv2.tv_sec - tv1.tv_sec > TLIM )
		boom(password, passcode);

	do{	printf("\nIntroduce el pin: ");
        switch (n=scanf("%i",&pc)) {
        case  0 : scanf("%*s")==0;	// match.failure
        case EOF: clearerr(stdin);} // EOF (Ctrl-D)
    }while (	n!=1 );

	if    (	pc != passcode )
		boom(password, passcode);

	gettimeofday(&tv1, NULL);
	if    ( tv1.tv_sec - tv2.tv_sec > TLIM )
		boom(password, passcode);

	defused();
}