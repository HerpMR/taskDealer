
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


// ここが恐らく原因だからあとで直す
int deal(task todo,int pass){
	if(pass < todo.t_arrival)	pass = todo.t_arrival;
	printf("before: %d\n", pass);
	pass += todo.t_cost;
	printf("after : %d\n", pass);
	todo.status = true;
	//printstatus(todo,pass);
}

/*
void printstatus(task done,int time){
	printf("Task'%s' is done (fin_time = %d)\n", done->name, time);
}
*/

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
		else{
			time = deal(TASKLIST[stacktop], time);

		}
		printf("// dbg: stacktop = %d ,time = %d\n", stacktop,time);
	}
	return 0;
}

