#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc,char *argv[]){

	int N=5, i, pid,status;
	for (i=0; i<N; i++){

		pid = fork();
		if(pid == -1)
			perror("errore figlio non creato");
		if (pid==0){
			printf("Sono il FIGLIO con PID: %d\n", getpid());
			printf("del padre:%d\n",getppid());
			exit(2);		
		}
		
	}


	for (size_t i = 0; i < N; i++)
	{
		wait(&status);

		printf("figlio terminato con stato %d\n",status);
	}
	
	

	return 0;	
}
