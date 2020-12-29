*rule new_rule(){
  struct rule newRule;

  return &newRule;
}

int create_ccl(*fact, *rule){
  while (*rule.next != NULL) {
    rule = *rule.next;
  }
  *int ccl = newrule();
  *ccl.fact = *fact;
  *ccl.ccl = 1;
  *rule.next = ccl;
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
