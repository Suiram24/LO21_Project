#ifndef KB_H
#define KB_H

#include <string.h>
#include <stdio.h>
#include "rule.h"


 struct kb {
  rule_t* rule;
  struct kb* next;
};
typedef struct kb kb_t;

//create a new void knowledge base and return the pointer to it
kb_t* new_kb();

//add a rule to an existing knowledge base
int addrule(rule_t* rule, kb_t* kb);

//return a pointer to the first rule of a knowledge base
rule_t* kb_first_rule(kb_t* kb);

#endif
