#include <string.h>
#include <stdio.h>
#include "kb.h"
#include "rule.h"


kb_t* new_kb(){
  kb_t newkb;
  return &newkb;
}

int addrule(rule_t* rule, kb_t* kb){
  kb_t *newrule;
  newrule = new_kb();
  while(kb->next!=NULL){
    kb = kb->next;
  }
  kb->next = newrule;
  newrule->rule = rule;
  return 0;
}

rule_t* kb_first_rule(kb_t* kb){
  if(kb->next == NULL){
    return NULL;
  }else {
      return kb->next->rule;
  }

}
