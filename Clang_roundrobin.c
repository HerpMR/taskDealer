
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	// Use strcmp(...)
#include <stdbool.h>
#include "tasch.h"	// Original header files
// #include "stacklib.h"
// #include "queuelib.h"

int sum = 0;
void robinstream(task *,int,int,int *);

int main(int argc, char const *argv[]){
	int N;
	int lim,time = 0;
	bool available = true;	// 0: false, 1: true
	task TASKLIST[100];
	queuehead = queuetail = 0;

	// Input
	printf("## Scheduler of Round-Robin method\ninput:\n");
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		scanf(" %s %d %d",
			TASKLIST[i].name, &TASKLIST[i].t_arrival, &TASKLIST[i].t_cost);
		TASKLIST[i].status = 1;	// all tasks is executable
	}
	scanf(" %d", &lim);
	enqueue(TASKLIST[0]);
	TASKLIST[0].status = 1;

	// Output
	printf("\nOutput:\n");
	robinstream(TASKLIST,N,lim, &time);
	printf("%d %.2f\n",time, (double)sum / N);
	return 0;
}

// Round-Robin system.
void robinstream(task *TASKLIST,int size,int limit,int *time){
	int cont;
	task todo;

	do{
		todo = dequeue();
		cont = 0;
		timeadjust(todo, &(*time));

		// trace and check
		// todo.t_arrival <= *time
		if(todo.status && todo.t_cost){
			if(todo.t_cost <= limit){
				*time += todo.t_cost;
				todo.t_cost = 0;
				todo.status = 0;
				sum += *time - todo.t_arrival;
				printstatus(todo,*time,limit);
			}
			else{
				todo.t_cost -= limit;
				*time += limit;
				printstatus(todo,*time,limit);
				todo.status = 3;
				enqueue(todo);
			}
			for (int k = 0; k < size; ++k){
				if(!strcmp(TASKLIST[k].name,todo.name)){
					TASKLIST[k] = todo;
					printf("// dbg: task* data Copied. (TASKLIST[%d] <- todo)\n", k);
					printf("// dbg: TASKLIST[%d].t_cost = %d, todo.t_cost = %d\n",
						k,TASKLIST[k].t_cost, todo.t_cost);
					printf("// dbg: TASKLIST[%d].status = %d, todo.status = %d\n\n",
						k,TASKLIST[k].status,todo.status);
					break;
				}
			}
		}

		// memo: where will be put (12/13)
		for(int i = 0; i < size; ++i){
			if(TASKLIST[i].t_arrival <= *time && TASKLIST[i].status == 1){
				enqueue(TASKLIST[i]);
				// TASKLIST[i].status = 3;
			}
		}
		
		for (int i = 0; i < size; ++i)	cont += TASKLIST[i].status;
	} while(cont);
	return;
}

