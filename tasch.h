#ifndef TASCH_H
#define TASCH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Use this struct for scheduling algorithm
typedef struct{
	char name[10];
	int t_arrival;
	int t_cost;
	bool status;
} task;

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



#endif