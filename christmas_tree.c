#include<stdio.h>
#include<stdlib.h>

void f(char *s)
{
        printf("%*s%*s",50+strlen(s)/2,s,50-strlen(s)/2,"");
}


int main (int argc, char* argv[]) {

	int num;
	int balls = 1;
	int levels = 4;	


	if (argc < 2) {
	   num = 1;
	}else {
	   num =  atoi(argv[1]);
	}

	
	
	for(int i = 0; i< num ; i++) {
	
	   for(int j = 0; j < levels;j++){
		char* level = malloc(balls);
		for(int z = 0; z< balls; z++) {
			level[z] = '*';
		}
		level[balls] = '\0';
		f(level);
		balls +=2;
		f("\n");
		free(level);
	   }
	   balls -=2;
	   levels ++;

	}

	f("|");
}

