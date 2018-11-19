
#include <stdio.h>
// #include "stacklib.h"

typedef struct{
	char name[10];
	int t_arrival;
	int t_cost;
	bool status;
} task;

int deal(task todo,int *pass){
	if(pass < todo->t_arrival)	pass = todo->t_arrival;
	pass += todo->t_cost;
	todo->status = true;
	printstatus(todo,pass);
}

void printstatus(task done,int time){
	printf("Task'%s' is done (fin_time = %d)\n", done->name, time);
}

int main(int argc, char const *argv[]){
	int N;
	int time = 0;
	int stacktop = 0;
	bool available = true;	// 0: false, 1: true
	task TASKLIST[100];

	scanf("%d",&N);
	for (int i = 0; i < N; ++i){
		scanf(" %s %d %d",
			TASKLIST[i]->name, &TASKLIST[i]->t_arrival, &TASKLIST[i]->t_cost);
		TASKLIST[i]->status = false;
	}

	while(1){
		if(stacktop >= N){
			printf("Error: stack overflow..\n");
			return -1;
		}
		else{
			deal(TASKLIST[stacktop++], &time);
		}
		
	}
	return 0;
}
