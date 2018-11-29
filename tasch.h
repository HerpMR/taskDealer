#ifndef TASCH_H
#define TASCH_H

#include <stdio.h>
#include <stdlib.h>

// Use this struct for scheduling algorithm
typedef struct{
	char name[10];
	int t_arrival;
	int t_cost;
	int status;
} task;

/*
	*task.status value is :
	0: done,
	1: executable,
	2: dealing,
	3: waiting
*/


// print task what has done
void printstatus(task done,int time){
	printf("Task'%s' is done (arr_time = %3d, fin_time = %3d)\n",
		done.name, done.t_arrival, time);	
}

// Use for arrival.c & dealtime.c
void deal(task todo,int *pass){
	if(*pass < todo.t_arrival)	*pass = todo.t_arrival;
	*pass += todo.t_cost;
	todo.status = true;
	printstatus(todo,*pass);
}

// Select and Move to queue top (by ma1750)
void sort(task *TASKLIST,int top,int num,int time){
	for (int i = top; i < num; ++i){
		if (TASKLIST[i].t_arrival <= time && TASKLIST[top].t_cost > TASKLIST[i].t_cost){
			task tmp = TASKLIST[top];
			TASKLIST[top] = TASKLIST[i];
			TASKLIST[i] = tmp;
		}
	}
}

// Round-Robin system.
void robinstream(task *TASKLIST,int num,int *time){
	return;
}

#endif

