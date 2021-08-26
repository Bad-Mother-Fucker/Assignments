int* my_range(int param1, int param2) {

  if(param1 >= param2) return NULL;

  int size = param2 - param1;
  int* array = malloc(sizeof(int)*size);

  for(int i = 0; i< size; i++) {
    array[i] = param1 + i;
  }

  return array; 

}
