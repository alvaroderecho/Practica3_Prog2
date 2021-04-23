#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "list.h"

#define MAX_TESTS 20
#define MAX_SET 1024

int main(int argc, char** argv) {

  int test = 0;
  int all = 1;

  if (argc < 2) {
    printf("Running all test for module Set:\n");
  } else {
    test = atoi(argv[1]);
    all = 0;
    printf("Running test %d:\t", test);
    if (test < 1 || test > MAX_TESTS) {
      printf("Error: unknown test %d\t", test);
      exit(EXIT_SUCCESS);
    }
  }
  if (all || test == 1) test1_set_create();
  if (all || test == 2) test1_set_destroy();
  if (all || test == 3) test2_set_destroy();
  if (all || test == 4) test1_set_add_values();
  if (all || test == 5) test2_set_add_values();
  if (all || test == 6) test3_set_add_values();
  if (all || test == 7) test4_set_add_values();
  if (all || test == 8) test1_set_del_values();
  if (all || test == 9) test2_set_del_values();
  if (all || test == 10) test3_set_del_values();
  if (all || test == 11) test4_set_del_values();
  if (all || test == 12) test1_set_print();
  if (all || test == 13) test2_set_print();
  if (all || test == 14) test1_set_get_ids();
  if (all || test == 15) test1_set_get_numids();
  if (all || test == 16) test1_set_containsId();
  if (all || test == 17) test2_set_containsId();
  if (all || test == 18) test3_set_containsId();
  
  PRINT_PASSED_PERCENTAGE;

  return 1;
}


