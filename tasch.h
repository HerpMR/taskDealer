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
	2: executing
	3: waiting
*/

// static variable
static int queuehead,queuetail;
static task queue[300];

// Do enqueue
void enqueue(task x){
	queuetail = (queuetail + 1) % 300;
	queue[queuetail] = x;
	if(queuehead == queuetail){
		printf("Error: Overflow..\n");
		return;
	}
}

// Do dequeue
task dequeue(){
	if(queuehead != queuetail){
		queuehead = (queuehead + 1) % 300;
		return queue[queuehead];
	}
}

// Print task what has done or paused
void printstatus(task done,int time,int lim){
	if(!done.status){
		printf("Task'%s' is done (arr_time = %3d, fin_time = %3d)\n",
			done.name, done.t_arrival, time);
	}
	else{
		if(done.status == 1){
			printf("Task'%s' is paused (  start_time = %3d, pause_time = %3d)\n",
				done.name, time - lim, time);
		}
		else if(done.status == 3){
			printf("Task'%s' is paused (restart_time = %3d, pause_time = %3d)\n",
				done.name, time - lim, time);
		}
	}
}

// Gap filling when not arriving
void timeadjust(task todo,int *pass){
	if(*pass < todo.t_arrival)	*pass = todo.t_arrival;
}

// Use for arrival.c & dealtime.c
void deal(task todo,int *pass,int size,double *qtime){
	timeadjust(todo, &*pass);
	*pass += todo.t_cost;
	*qtime += (double)(*pass - todo.t_arrival) / (double)size;
	todo.status = 0;
	printstatus(todo,*pass,0);
}

#endif

