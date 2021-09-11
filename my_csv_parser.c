#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef char** string_array_array;

/*typedef struct r_row_cols{
	int rows;
	int columns;
}row_cols;*/

int get_rows(char *string){
	int rows = 1;
	for(int i=0;string[i] != '\0';i++)
		if(string[i] == '\n') rows++;

	if(string[strlen(string)-1] == '\n') rows -= 1;

	return rows;
}

int get_columns(char *string, char *sep){
	int columns = 0;
	char *t;

	char str[strlen(string)], sp[strlen(string)];
	strcpy(str, string);
	strcpy(sp, sep);
	t = strtok(str, sep);
	while(t != NULL){
		t = strtok(NULL, sp);
		columns++;
	}

	/*for(int i=0;string[i];i++)
		if(string[i] == sep[0]) columns++;*/

	return (columns+=1);
}

/*row_cols get_size(char *string, char *separator){
	row_cols rc;
	int rows=0, columns=0;
	char s[strlen(string)], sep[strlen(separator)];
	char *t;
	strcpy(s, string);
	strcpy(sep, separator);
	t = strtok(s, separator);
	while(t != NULL){
		t = strtok(NULL, sep);
		columns++;
	}
	columns += 1;
	for(int i=0;i<strlen(string);i++){
		if(string[i] == '\n') rows++;
	}
	rc.rows = rows;
	rc.columns = columns;

	return rc;
}*/

string_array_array* my_csv_parser(char *param_1, char *param_2){
	char *split;
	char over_1[strlen(param_1)], over_2[strlen(param_2)];
	//row_cols rc;
	int rows=0, columns=0;
	strcpy(over_1, param_1);
	strcpy(over_2, param_2);
	char **ret_value;

	rows = get_rows(param_1);
	columns = get_columns(param_1, param_2);

	//rc = get_size(param_1, param_2);
	//rows = rc.rows;
	//columns = rc.columns;

	printf("rows:%d\n", rows);
	printf("columns:%d\n", columns);

	ret_value = malloc(rows);

	/*for(int i=0;i<20;i++){
		ret_value[i] = malloc(10*sizeof(char));
	}

	split = strtok(over_1, param_2);

	int n=0;
	while(split != NULL){
		printf("%s\n", split);
		//if(strcmp(split, "\n") == 0) continue;
		ret_value[n] = split;
		split = strtok(NULL, over_2);
		n++;
	}
	for(int i=0;i<7;i++)
		printf("%s\n", ret_value[i]);*/

	return (string_array_array*) ret_value;
}

int main(){
	csv_parse("a,b,c,e\n1,2,3,4\n", ",");
	csv_parse("abc/def\n12/34", "/");

	return 0;
}
