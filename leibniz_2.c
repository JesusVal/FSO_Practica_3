#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <pthread.h>

#define CICLOS 2000000000
#define NTHREADS 4


double valueArr[NTHREADS];


void *leibniz(void *args);


int main()
{
	int i;
	double value = 0.0;
	pthread_t tid[NTHREADS];
	int parArr[NTHREADS];

	long long start_ts;
	long long stop_ts;
	long long elapsed_time;
	long lElapsedTime;
	struct timeval ts;

	gettimeofday(&ts, NULL);
	start_ts = ts.tv_sec; // Tiempo inicial
	

	
	
	for(i=0;i<NTHREADS;i++)
	{
		parArr[i] = i;
		pthread_create(&tid[i],NULL,leibniz,(void *) &parArr[i]);
	}
	

	for(i=0;i<NTHREADS;i++)
		pthread_join(tid[i],NULL);

	for(i = 0 ; i < NTHREADS ; i++)
		value = value + valueArr[i];

	value = value * 4;
	
	gettimeofday(&ts, NULL);
	stop_ts = ts.tv_sec; // Tiempo final

	elapsed_time = stop_ts - start_ts;
	printf("------------------------------\n");
	printf("Aproximacion: %e\n", value);
	printf("TIEMPO TOTAL, %d segundos\n", (int) elapsed_time);
}


void *leibniz(void *args)
{
	int nthread = *((int *) args);

	valueArr[nthread] = 0.0;
	int i;
	int inicio = nthread * (CICLOS/NTHREADS);
	int final = (nthread+1) * (CICLOS/NTHREADS);

	//double valuetemp = 0;

	for(int i =  inicio ; i < final ; i++)
	{
		valueArr[nthread] = valueArr[nthread] + pow(-1, i)/(2.0*i+1);
		//printf("pow %f\n",pow(-1,i));
	}


	printf("Hola mundo desde el hilo %d\n",nthread);
}