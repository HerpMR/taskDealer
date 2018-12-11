
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tasch.h"	// Original header files
// #include "stacklib.h"
// #include "queuelib.h"

double qtime = 0.00;
void robinstream(task *,int,int,int *);

int main(int argc, char const *argv[]){
	int N;
	int lim,time = 0;
	int queuetop = -1;
	bool available = true;	// 0: false, 1: true
	task TASKLIST[100];

	printf("## Scheduler of Round-Robin method\ninput:\n");
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		scanf(" %s %d %d",
			TASKLIST[i].name, &TASKLIST[i].t_arrival, &TASKLIST[i].t_cost);
		TASKLIST[i].status = 1;	// all tasks is executable
	}
	scanf(" %d", &lim);

	printf("\nOutput:\n");
	while(++queuetop < N){
		if(queuetop >= 100){
			printf("Error: queue size shortage..\n");
			return -1;
		}
		else robinstream(TASKLIST,N,lim, &time);
	}
	printf("%d %.2f\n",time,qtime);
	return 0;
}

// Round-Robin system.
void robinstream(task *TASKLIST,int size,int limit,int *time){
	int cont = 1;
	while(cont){
		cont = 0;

		for (int i = 0; i < size; ++i){

			// trace and check
			if(TASKLIST[i].status){

				if(TASKLIST[i].t_arrival <= *time){
					if(TASKLIST[i].t_cost <= limit){
						*time += TASKLIST[i].t_cost;
						TASKLIST[i].t_cost = 0;
						TASKLIST[i].status = 0;
						qtime += (double)(*time - TASKLIST[i].t_arrival) / (double)size;
						printstatus(TASKLIST[i],*time,limit);
					}
					else{
						TASKLIST[i].t_cost -= limit;
						*time += limit;
						printstatus(TASKLIST[i],*time,limit);
						TASKLIST[i].status = 3;
					}
				}
				else timeadjust(TASKLIST[i - 1], &(*time));
			}
		}
		for (int i = 0; i < size; ++i)	cont += TASKLIST[i].status;
	}
	return;
}

