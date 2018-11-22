
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "stacklib.h"
// #include "queuelib.h"

typedef struct{
	char name[10];
	int t_arrival;
	int t_cost;
	bool status;
} task;

// prototype & variable
void deal(task,int *);
void printstatus(task,int);
void i_sort(task *,int);	// insertion sort

int main(int argc, char const *argv[]){
	int N;
	int time = 0;
	int queuetop = -1;
	bool available = true;	// 0: false, 1: true
	task TASKLIST[100];

	printf("## Scheduler of Processing time order method\ninput:\n");
	scanf("%d",&N);
	for (int i = 0; i < N; ++i){
		scanf(" %s %d %d",
			TASKLIST[i].name, &TASKLIST[i].t_arrival, &TASKLIST[i].t_cost);
		TASKLIST[i].status = false;
	}

	printf("\nOutput:\n");
	i_sort(TASKLIST,N);
	while(++queuetop < N){
		if(queuetop >= 100){
			printf("Error: queue overflow..\n");
			return -1;
		}
		else deal(TASKLIST[queuetop], &time);
	}
	printf("%d\n",time);
	return 0;
}

// Do insertion sort in queue
void i_sort(task *TASKLIST,int num){
	int j;
	task data;

	for (int i = 1; i < num; ++i){
		data = TASKLIST[i];
		j = i;
		while((j > 0) && (TASKLIST[j - 1].t_cost > data.t_cost)){
			TASKLIST[j] = TASKLIST[j - 1];
			--j;
		}
		TASKLIST[j] = data;
	}
}

void deal(task todo,int *pass){
	if(*pass < todo.t_arrival)	*pass = todo.t_arrival;
	*pass += todo.t_cost;
	todo.status = true;
	printstatus(todo,*pass);
}

void printstatus(task done,int time){
	printf("Task'%s' is done (arr_time = %3d, fin_time = %3d)\n",
		done.name, done.t_arrival, time);	
}

