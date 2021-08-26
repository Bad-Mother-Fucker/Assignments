char* my_strcpy(char* param_1, char* param_2, int param_3) {
  param_1 = malloc(sizeof(char)* (param_3+1));

  for(int i = 0; i<param_3; i++) {
    param_1[i] = param_2[i];
  }
  return param_1;
}
