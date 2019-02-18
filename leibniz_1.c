#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

#define CICLOS 1000000000

int main()
{
/*Variables para contar tiempo*/
	long long start_ts;
	long long stop_ts;
	int elapsed_time;
	long lElapsedTime;
	struct timeval ts;
	
/*Variables de programa*/
	int i;
	
/*Tiempo inicial: Al inicio de la ejecucion*/
	gettimeofday(&ts, NULL);
	start_ts = ts.tv_sec * 1000000 + ts.tv_usec; // Tiempo inicial
	
	
	for(int i = 0 ; i < CICLOS ; i++)
	{
		
	}
	printf("Soy una ejecucion\n");
	
	
/*Tiempo final: Al final de la ejecucion*/
	gettimeofday(&ts, NULL);
	stop_ts = ts.tv_sec * 1000000 + ts.tv_usec; // Tiempo final
	
	elapsed_time = (int) (stop_ts - start_ts);
	printf("proceso %d, %d microsegundos\n", getpid(), elapsed_time);
	printf("Segundos: %f\n", (double) elapsed_time/1000000.0);

	
	return 0;
}