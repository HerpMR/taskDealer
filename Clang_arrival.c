
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "stacklib.h"

typedef struct{
	char name[10];
	int t_arrival;
	int t_cost;
	bool status;
} task;

// prototype & variable
void deal(task,int *);
void printstatus(task,int);

int main(int argc, char const *argv[]){
	int N;
	int time = 0;
	int stacktop = -1;
	bool available = true;	// 0: false, 1: true
	task TASKLIST[100];

	scanf("%d",&N);
	for (int i = 0; i < N; ++i){
		scanf(" %s %d %d",
			TASKLIST[i].name, &TASKLIST[i].t_arrival, &TASKLIST[i].t_cost);
		TASKLIST[i].status = false;
	}

	while(++stacktop < N){
		if(stacktop >= 100){
			printf("Error: stack overflow..\n");
			return -1;
		}
		else deal(TASKLIST[stacktop], &time);
	}
	printf("%d\n",time);
	return 0;
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

