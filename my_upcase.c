
#include <string.h>
#include <stdio.h>

char* my_upcase(char* param_1) {

  int len = strlen(param_1);

  char* newString = (char *) malloc(sizeof(char)*(len+1));

  int i = 0;

  while(i<len) {
    
    char c = param_1[i];
    if(c!=' ')
      c &= ~' ';
    newString[i] = c;
    i++;
  }

  newString[len] = '\0';

  return newString;

}

int main() {
  printf("%s", my_upcase("AbcE Fgef1"));
}
