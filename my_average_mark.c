

float my_average_mark(string_integer_array* param1) {
  int sum = 0;

  for(int i = 0; i < param1->size; ++i) {
    sum += param1->array[i]->integer;
  }

  return sum / param1->size;
}
