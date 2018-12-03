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

/*
// static variable
static int queuehead;
static int queuetail;

// Do enqueue
void Enqueue(task data,task *TASKLIST){
	queuetail = (++queuetail) % 100;
	TASKLIST[queuetail] = data;
	if(queuehead == queuetail){
		printf("Error: Overflow..\n");
		return;
	}
}

// Do dequeue
task Dequeue(task *TASKLIST){
	if(queuehead == queuetail){
		printf("Error: Underflow..\n");
		return;
	}
	else{
		queuehead = (++queuehead) % 100;
		return TASKLIST[queuehead];
	}
}
*/

// Print task what has done
void printstatus(task done,int time,int lim){
	if(!done.status){
		printf("Task'%s' is done (arr_time = %3d, fin_time = %3d)\n",
			done.name, done.t_arrival, time);
	}
	else{
		printf("Task'%s' is paused (start(restart)_time = %3d, pause_time = %3d)\n",
			done.name, time - lim, time);
	}
}

// Use for arrival.c & dealtime.c
void deal(task todo,int *pass){
	if(*pass < todo.t_arrival)	*pass = todo.t_arrival;
	*pass += todo.t_cost;
	todo.status = 0;
	printstatus(todo,*pass,0);
}

#endif

