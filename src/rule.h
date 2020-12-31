#ifndef RULE_H
#define RULE_H

#include <string.h>
#include <stdio.h>

#define FACT_LEN 256

typedef struct rule {
  char fact[FACT_LEN];
  int ccl;
  struct rule* next;
};

*rule new_rule();

int add_fact(*fact, *rule);

int create_ccl(*fact, *rule);

int test_empty_facts(*rule);

int test_fact(*fact, *rule);

int remove_fact(*fact, *rule);

*char rule_head_fact(*rule);

*char rule_ccl(*rule);

#endif
