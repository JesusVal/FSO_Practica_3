#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define CICLOS 2000000000
//#define CICLOS 10000

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
	double value = 0;
	
/*Tiempo inicial: Al inicio de la ejecucion*/
	gettimeofday(&ts, NULL);
	start_ts = ts.tv_sec * 1000000 + ts.tv_usec; // Tiempo inicial
	
/*
	for(int i = 0 ; i < CICLOS ; i++)
	{
		value = value + pow(-1, i)/(2.0*i+1);
		//printf("pow %f\n",pow(-1,i));
	}
	value = value * 4;
	*/
	//printf("Soy una ejecucion %f\n", value);
	
	
/*Tiempo final: Al final de la ejecucion*/
	gettimeofday(&ts, NULL);
	stop_ts = ts.tv_sec * 1000000 + ts.tv_usec; // Tiempo final
	
	elapsed_time = (int) (stop_ts - start_ts);
	printf("proceso %d, %d microsegundos\n", getpid(), elapsed_time);
	printf("Segundos: %f\n", (double) elapsed_time/1000000.0);
	printf("Valor aproximado de pi : %f\n", value);

	
	return 0;
}