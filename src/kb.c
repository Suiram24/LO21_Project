#include <string.h>
#include <stdio.h>
#include "kb.h"
#include "rule.h"


kb* new_kb(){
  struct kb newkb;
  return &newkb;
}

int addrule(*rule, *kb){
  kb *newrule;
  newrule = new_kb();
  while(*kb.next!=NULL){
    kb = *kb.next;
  }
  *kb.next = newrule;
  *newrule.rule = rule;
  return 0;
}

*rule kb_first_rule(*kb){
  return *(*kb.next).rule;
}
