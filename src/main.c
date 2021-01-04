#include <string.h>
#include <stdio.h>
#include "kb.h"
#include "rule.h"
#include "ie.h"

int main(){
  char a[3] = "A";
  char b[3] = "B";
  char c[3] = "C";
  char d[3] = "D";
  rule_t *pregle;
  pregle = new_rule();
  printf("test 1: %d\n", pregle->next);
  add_fact(&a, pregle);
  add_fact(&b, pregle);
  printf("test 2\n");
  create_ccl(&c, pregle);
  printf("test 3\n");
  printf("test : %s \n", &a);
  return 0;
}
