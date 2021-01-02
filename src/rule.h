#ifndef RULE_H
#define RULE_H

#include <string.h>
#include <stdio.h>

#define FACT_LEN 256

typedef struct rule_t {
  char fact[FACT_LEN];
  int ccl;
  struct rule_t* next;
};

//create a new void rule and return the pointer to it
*rule_t new_rule();

//add a fact to a rule
int add_fact(*char fact, *rule_t rule);

//add a conclusion to a rule
int create_ccl(*char fact, *rule_t rule);

//return 1 if the rule has no facts (it can have a ccl), 0 otherwise
int test_empty_facts(*rule_t rule);

//return 1 if the fact is in the rule(and not the ccl), 0 otherwise
int test_fact(*char fact, *rule_t rule);

//remove the fact from the rule.
int remove_fact(*char fact, *rule_t rule);

//return a pointer linked to the first fact of the rule
*char rule_t_head_fact(*rule_t rule);

//return a pointer linked to the conclusion of the rule
*char rule_ccl(*rule_t rule);

#endif
