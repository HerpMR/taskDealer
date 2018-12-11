
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[]){
	srand((unsigned)time(NULL));

	int N = rand() % 16 + 4;
	int time = rand() % 3;
	char *str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	FILE *WTO = fopen(argv[1],"w");

	fprintf(WTO,"%d\n",N);
	time += rand() % 3;
	for (int i = 1; i <= N; ++i){
		fprintf(WTO, "%c %d %d\n",str[i - 1],time,rand() % 10 + 1);
		time += rand() % 7 + 1;
	}
	fclose(WTO);
	return 0;
}

