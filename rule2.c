typedef struct rule {
    char fact[FACT_LEN];
    int ccl;
    struct rule* next;
};

struct rule* add_fact(fact, *rule){
    int *rule_transit, *rule_cc1;
    struct rule new_fact;
    if (*rule.next==NULL){
        return 0;
    } else {
        while (*rule.next !=NULL){
            rule_transit=rule;
            rule = *rule.next;
        }
        rule_ccl=rule;
        new_fact.fact=fact;
        
        if (rule.ccl==1){
            *rule_transit.next=&new_fact;
            *new_fact.next=&rule_ccl;
        } else {
            *rule.next= &new_fact;
        }
        return 1;
    }
    return rule;
}

int test_fact(fact, *rule){
    while (rule.next!=NULL){
        if (strcmp(rule.fact,fact)==0){
            return 1;
        }
        rule=rule->next;
    }
    if (rule.next!=NULL){
        return 0;
    }
}

int remove_fact(fact, *rule){
    int *rule_trst,*rule_ccl;
    if (rule.next==NULL){
        return 0;
    } else {
        while (rule.next!=NULL){
          rule_transit=rule;
          if (strcmp(rule.fact,fact)==0){
              break;
          }
          rule=*rule.next;
        }
        rule_ccl=rule;
        if (rule.next==NULL){
            return 0;
        } else {
            *rule_transit.next=&rule_ccl;   
        }
        
    }
}

*char rule_head_fact(*rule){
    if (rule.next==NULL){
        return rule;
    } else {
      return rule.fact;
    }
}
