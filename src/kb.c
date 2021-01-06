#include <string.h>
#include <stdio.h>
#include "kb.h"
#include "rule.h"


kb_t* new_kb(){
  kb_t *newkb = malloc(sizeof(kb_t));
  newkb->rule = NULL;
  newkb->next = NULL;
  return newkb;
}

int addrule(rule_t* rule, kb_t* kb){
  kb_t *newrule;
  newrule = new_kb();

  while(kb->next!=0){

    kb = kb->next;
  }
  kb->next = newrule;
  newrule->rule = rule;
  return 0;
}

rule_t* kb_first_rule(kb_t* kb){
  if(kb->next == 0){
    return NULL;
  }else {
      return kb->next->rule;
  }

}
