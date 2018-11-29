
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tasch.h"	// Original header files
// #include "stacklib.h"
// #include "queuelib.h"

void sort(task *,int,int,int);

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
		TASKLIST[i].status = 1;
	}

	printf("\nOutput:\n");
	while(++queuetop < N){
		if(queuetop >= 100){
			printf("Error: queue size shortage..\n");
			return -1;
		}
		else{
			sort(TASKLIST,queuetop,N,time);
			deal(TASKLIST[queuetop], &time);
		}
	}
	printf("%d\n",time);
	return 0;
}

// Select and Move to queue top (by ma1750)
void sort(task *TASKLIST,int top,int num,int time){

	// ここの処理回数減らしたい
	for (int i = top; i < num; ++i){
		if (TASKLIST[i].t_arrival <= time && TASKLIST[top].t_cost > TASKLIST[i].t_cost){
			task tmp = TASKLIST[top];
			TASKLIST[top] = TASKLIST[i];
			TASKLIST[i] = tmp;
		}
	}
}

