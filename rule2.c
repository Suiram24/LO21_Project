typedef struct rule {
    char fact[FACT_LEN];
    int ccl;
    struct rule* next;
};

struct rule* add_fact(fact, *rule){
    if (rule=NULL){
        return rule;
    } else {
        struct rule* rule_transit=rule;
        while (rule_transit->next !=NULL){
            rule_transit = rule_transit->next;
            rule = rule->next;
        }
        rule.fact = fact;
        rule.ccl=0;
        rule = rule -> next;
        rule.fact=rule_transit.fact;
        rule.ccl=1;
    }
    return rule;
}

int test_fact(fact, *rule){
    while (rule->next!=NULL){
        if (rule.fact==fact){
            break;
            return 1;
        }
        rule=rule->next;
    }
    if (rule->next!=NULL){
        return 0;
    }
}

int remove_fact(fact, *rule){
    struct rule* rule_trst=rule;
    if (rule==NULL){
        return rule;
    } else {
        while (rule_trst->next!=NULL){
          if (rule_trst.fact==fact){
              break;
          }
          rule_trst=rule_trst->next;
          rule=rule->next;
        }
        rule_trst=rule_trst->next;
        if (rule_trst->next!=NULL){
            return 0;
        }
        while (rule_trst->next!=NULL){
        rule=rule_trst;
        }
        rule=rule->next;
        rule=NULL;
    }
}

*char rule_head_fact(*rule){
    if (rule==NULL){
        return rule;
    } else {
      return rule.fact;
    }
}
