
#include <string.h>
#include <stdio.h>

*rule new_rule(){
  struct rule newRule;

  return &newRule;
}

int create_ccl(*fact, *rule){
  while (*rule.next != NULL) {
    rule = *rule.next;
  }
  if(*rule.ccl == 0){
    rule *ccl = newrule();
    strcpy(*ccl.fact, *fact);
    *ccl.ccl = 1;
    *rule.next = ccl;
    return 0;
  }else {
    return 1;
  }
  
}

int test_empty_facts(*rule){
  if(*rule.next == NULL){
    return 1;
  }else if (*(*rule.next).ccl == 1){
    return 1;
  }else{
    return 0;
  }
}

*char rule_ccl(*rule){
  while (*rule.next != NULL) {
    rule = *rule.next;
  }
  if (*rule.ccl == 1){
    return &(*rule.fact);
  }else {
    return NULL;
  }
}
