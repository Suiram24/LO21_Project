#include <string.h>
#include <stdio.h>

typedef struct rule {
  char fact[FACT_LEN];
  int ccl;
  struct rule* next;
};

int add_fact(*fact, *rule){
  rule *rule_transit, *rule_cc1;
  struct rule new_fact;
  rule_transit=rule;

      while (*rule.next !=NULL){
          rule_transit=rule;
          rule = *rule.next;
      }
      rule_ccl=rule;
      strcpy(new_fact.fact,fact);
      
      if (rule.ccl==1){
          *rule_transit.next=&new_fact;
          new_fact.next=rule_ccl;
      } else {
          *rule.next= &new_fact;
      }
      return 1;
      
}

int test_fact(*fact, *rule){
  while (*rule.next!=NULL){
      if (strcmp(*rule.fact,fact)==0){
          return 1;
      }
      rule=*rule.next;
  }
  if ((*rule.ccl == 0) && (strcmp(*rule.fact,fact)==0) ){
      return 1;
  }else {
    return 0;
  }
}

int remove_fact(*fact, *rule){
  int *rule_trst,*rule_ccl;
  if (test_empty_facts(rule)==1){
      return 0;
  } else {
      while (rule!=NULL){
        rule_transit=rule;
        if ((strcmp(*rule.fact,fact)==0)&&(*rule.ccl == 0)){
            *rule_transit.next = *rule.next;
            free(rule);
            return 1
        }
        rule=*rule.next;
      }
      return 0;      
  }
}

*char rule_head_fact(*rule){
  if (test-empty-facts(rule)==1){
      return NULL;
  } else {
    return *((*rule.next).fact);
  }
}
