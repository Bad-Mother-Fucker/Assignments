#include<stdlib.h>
#include<stdio.h>
#define MAX_STR_SZ 256


char* rostring(char * param_1) {


	int i = 0;
	while(param_1[i] == ' ') i++;

	int c = 0;
	char word [100];

	while(param_1[i] != ' ')
		word[c++] = param_1[i++];

	char* newstring = (char*) malloc(c);


	while(param_1[i] == ' ') i++;

	int j = 0;

	while(param_1[i] != '\0' && param_1[i] != '\n' ) {

		newstring[j++] = param_1[i++];

	}

	for(int z = 0; z < c; z++ ) {
		newstring[j++] = word[z];
	}

	newstring[j] = '\0';

	return newstring;

}



int main() {

	char *s = malloc(100);

	printf("Insert string \n");

    fgets(s, MAX_STR_SZ, stdin);

	char * string = rostring(s);

	printf("%s", string);

	free(s);
	free(string);


}
