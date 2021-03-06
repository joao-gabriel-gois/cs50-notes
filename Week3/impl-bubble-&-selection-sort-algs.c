#include <cs50.h>
#include <stdio.h>
/*
  Implementing Bubble and Selection of sort and printing all outputs
*/
void bubble_sort(int array_length, int array[array_length]);
void selection_sort(int array_length, int array[array_length]);
// Util
void print_array(int array_length, int array[array_length]);

int main(void) {
  int bubble_array_to_sort[] = { 3, 2, 5, 4, 1, 9, 7, 11, 6, 12, 8 };
  int selection_array_to_sort[] = { 5, 4, 3, 2, 11, 9, 6, 1, 7, 8, 12, 10, 111 };
  int merge_array_to_sort[] = { 3, 99, 0, 33, 1, 9, 75, 11, 6, 211, 7, 16, 1000, -3 };
  
  printf("\n\033[01;33mBefore sort:\n");
  printf("\033[00;03mArray to Bubble: \033[03;34m");
  print_array(11, bubble_array_to_sort);
  printf("\033[00;03mArray to Selection: \033[03;34m");
  print_array(13, selection_array_to_sort);

  bubble_sort(11, bubble_array_to_sort);
  selection_sort(13, selection_array_to_sort);

  printf("\n\033[01;32mAfter Sort:\n");
  printf("\033[00;03m1) Bubble:\033[03;34m");
  print_array(11, bubble_array_to_sort);
  printf("\033[00;03m2) Selection: \033[03;34m");
  print_array(13, selection_array_to_sort);

  printf("\033[m\n");
  return 0;
}


void bubble_sort(int array_length, int array[array_length]) {
  int swap_counter = -1;

  while (swap_counter != 0) {
    swap_counter = 0;
    for (int i = 1; i < array_length; i++) {
      int previous = array[i - 1];
      int current = array[i];

      if (previous > current) {
        array[i - 1] = current;
        array[i] = previous;

        swap_counter++;
      }
    }
  }

  return;
}

void selection_sort(int array_length, int array[array_length]) {
  int sorted_array_length = 0;

  while (sorted_array_length != array_length) {
    int current_min_index = sorted_array_length;
    int current_min = array[sorted_array_length];

    for (int i = sorted_array_length; i < array_length - 1; i++) {
      int next = array[i + 1];
      if (current_min > next) {
        current_min_index = i + 1;  
        current_min = next;        
      }
    }

    // current minimum value on unsorted array now has the value of the first element of it
    array[current_min_index] = array[sorted_array_length];
    // Bellow we are putting the found minimum value  in the first element of the unsorted array,
    //    that is, the last element of sorted one. With this, we swap as expected both.
    array[sorted_array_length] = current_min;

    sorted_array_length++;
  }

  return;
}

void print_array(int array_length, int array[array_length]) {
  printf("[ ");
  
  for (int i = 0; i < array_length; i++) {
    printf(
      "%i%s",
      array[i],
      i != array_length - 1 ? ", " : " "
    );
  }

  printf("];\n");

  return;
}
