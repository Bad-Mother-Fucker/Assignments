

typedef struct s_string_array {

  int size;
  char** array;

} string_array;


char * my_join(string_array* param_1, char* param_2) {

    char totlen = 0;

    for(int i = 0; i < param_1->size; i++) {
      totlen += strlen(param_1->array[i]);
    }

    totlen += param_1->size;

    char* finalString = (char*) malloc(sizeof(char) * totlen);

    int count = 0;

    for(int i=0; i<param_1->len; i++) {
      int j = 0;
      char* word = param_1->array[i];
      while(word[j+1]) {
        finalString[c++] = word[j++];
      }
      finalString[c++] = *param_2;
    }

    finalString[totlen] = '\0';

    return finalString;
}
