typedef struct rule {
    char fact[FACT_LEN];
    int ccl;
    struct rule* next;
};

struct rule* add_fact(fact, *rule){
    if (rule.next==NULL){
        return 0;
    } else {
        struct rule* rule_transit;
        while (rule.next !=NULL){
            rule = rule.next;
        }
        if (rule.ccl==1){
            rule_transit.next=*rule;
            rule.next=*fact;
            rule=rule.next;
            rule.next=*rule_transit;
        } else {
            rule.next=*fact;
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
    struct rule* rule_trst=rule;
    if (rule.next==NULL){
        return 0;
    } else {
        while (rule.next!=NULL){
          if (strcmp(rule.fact,fact)==0){
              break;
          }
          rule_trst=rule_trst->next;
          rule=rule->next;
        }
        rule_trst=rule_trst->next;
        if (rule.next!=NULL){
            return 1;
        }
        while (rule_trst->next!=NULL){
        rule=rule_trst;
        }
        rule=rule->next;
        rule=NULL;
    }
}

*char rule_head_fact(*rule){
    if (rule.next==NULL){
        return rule;
    } else {
      return rule.fact;
    }
}
