#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "list.h"
#include "list_test.h"

#define MAX_TESTS 14
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
  if (all || test == 1) test1_list_new();
  if (all || test == 2) test1_list_isEmpty();
  if (all || test == 3) test2_list_isEmpty();
  if (all || test == 4) test3_list_isEmpty();
  if (all || test == 5) test1_pushFront();
  if (all || test == 6) test2_pushFront();
  if (all || test == 7) test1_pushBack();
  if (all || test == 8) test2_pushBack();
  if (all || test == 9) test1_popFront();
  if (all || test == 10) test2_popFront();
  if (all || test == 11) test1_popBack();
  if (all || test == 12) test2_popBack();
  if (all || test == 13) test1_list_size();
  if (all || test == 14) test2_list_size();
  
  PRINT_PASSED_PERCENTAGE;

  return 1;
}


void test1_list_new () {
  List *pl = list_new();
  PRINT_TEST_RESULT(pl != NULL);
  list_free(pl);
}

void test1_list_isEmpty() {
  List *pl = NULL;
  PRINT_TEST_RESULT(list_isEmpty(pl) == TRUE);
}

void test2_list_isEmpty() {
  List *pl = list_new();
  PRINT_TEST_RESULT(list_isEmpty(pl) == TRUE);
  list_free(pl);
}

void test3_list_isEmpty() {
  List *pl = list_new();
  int i = 0;
  void *e;
  e=&i;  
  list_pushFront(pl,e);
  PRINT_TEST_RESULT(list_isEmpty(pl) == FALSE);
  list_free(pl);

}

void test1_pushFront () {
  List *pl = list_new();
  int i = 0;
  void *e = &i;
    PRINT_TEST_RESULT(list_pushFront(pl,e) == OK);
      list_free(pl);

}

void test2_pushFront () {
  List *pl = NULL;
  int i = 0;
  void *e = &i;
    PRINT_TEST_RESULT(list_pushFront(pl,e) == ERROR);  

  }

void test1_pushBack () {
  List *pl = list_new();
  int i = 0;
  void *e = &i;
    PRINT_TEST_RESULT(list_pushBack(pl,e) == OK);
      list_free(pl);

}

void test2_pushBack () {
  List *pl = NULL;
  int i = 0;
  void *e = &i;
    PRINT_TEST_RESULT(list_pushBack(pl,e) == ERROR);  

  }

void test1_popFront() {
  List *pl = NULL;
  PRINT_TEST_RESULT(list_popFront(pl) == NULL);

}

void test2_popFront() {
  List *pl = list_new();
  int i = 0;
  void *e = &i;
 list_pushFront(pl,e);
  PRINT_TEST_RESULT(list_popFront(pl) == e);
    list_free(pl);

}

void test1_popBack() {
  List *pl = NULL;
  PRINT_TEST_RESULT(list_popBack(pl) == NULL);

}

void test2_popBack() {
  List *pl = list_new();
    int i = 0;
  void *e = &i;
  list_pushBack(pl,e);
  PRINT_TEST_RESULT(list_popBack(pl) == e);
    list_free(pl);

}

void test1_list_size() {
  List *pl = NULL;
  PRINT_TEST_RESULT(list_size(pl) == -1);
}

void test2_list_size() {
  List *pl = list_new();
  int i = 0;
  void *e = &i;
  list_pushFront(pl,e);
  PRINT_TEST_RESULT(list_size(pl) == 1);
    list_free(pl);

}