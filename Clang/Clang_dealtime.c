
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tasch.h"	// Original header files
// #include "stacklib.h"
// #include "queuelib.h"

void selectTop(task *,int,int,int);

int main(int argc, char const *argv[]){
	int N;
	int time = 0;
	int queuetop = -1;
	double qtime = 0.00;
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
		selectTop(TASKLIST,queuetop,N,time);
		deal(TASKLIST[queuetop], &time,N, &qtime);
	}
	printf("%d %.2f\n",time,qtime);
	return 0;
}

// Select and Move to queue top (by ma1750)
void selectTop(task *TASKLIST,int top,int num,int time){
	for (int i = top + 1; i < num; ++i){
		if ((TASKLIST[i].t_arrival <= time) && (TASKLIST[top].t_cost > TASKLIST[i].t_cost)){
			task tmp = TASKLIST[top];
			TASKLIST[top] = TASKLIST[i];
			TASKLIST[i] = tmp;
		}
	}
}

