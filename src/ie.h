#ifndef IE_H
#define IE_H

#include <string.h>
#include <stdio.h>
#include "rule.h"
#include "kb.h"

#define FACT_LEN 256

typedef struct facts_t {
  char fact[FACT_LEN];
  struct facts_t* next;
};

//return a linked list of the true facts
*facts_t interference_engine(*kb kb, *facts_t facts);

//return NULL is the rule is false, and the ccl if the rule is true
*facts_t is_rule_true(*rule rule, *facts_t facts);

//return 1 if true, 0 if false
int is_fact_true(*char fact, *facts_t factList);

#endif
