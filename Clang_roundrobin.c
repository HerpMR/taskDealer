
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
	task TASKLIST[300];

	// Input
	printf("## Scheduler of Round-Robin method\ninput:\n");
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		scanf(" %s %d %d",
			TASKLIST[i].name, &TASKLIST[i].t_arrival, &TASKLIST[i].t_cost);
		TASKLIST[i].status = 1;	// all tasks is executable
	}
	scanf(" %d", &lim);
	// enqueue(&TASKLIST[0]);
	TASKLIST[0].status = 1;

	// Output
	printf("\nOutput:\n");
	robinstream(TASKLIST,N,lim, &time);
	printf("%d %.2f\n",time,qtime);
	return 0;
}

// Round-Robin system.
void robinstream(task *TASKLIST,int size,int limit,int *time){
	int i = 0;
	int cont = 1;
	while(cont){
		cont = 0;

		// trace and check
		if(TASKLIST[i % size].status){

			if(TASKLIST[i % size].t_arrival <= *time){
				if(TASKLIST[i % size].t_cost <= limit){
					*time += TASKLIST[i % size].t_cost;
					TASKLIST[i % size].t_cost = 0;
					TASKLIST[i % size].status = 0;
					qtime += (double)(*time - TASKLIST[i % size].t_arrival) / (double)size;
					printstatus(TASKLIST[i % size],*time,limit);
				}
				else{
					TASKLIST[i % size].t_cost -= limit;
					*time += limit;
					printstatus(TASKLIST[i % size],*time,limit);
					TASKLIST[i % size].status = 3;
				}
			}
			else timeadjust(TASKLIST[(i - 1) % size], &(*time));
		}
		++i;
		for (int j = 0; j < size; ++j)	cont += TASKLIST[j].status;
	}
	return;
}

