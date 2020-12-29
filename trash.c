struct rule {
    char fact[FACT_LEN];
    int ccl;
    struct rule* next;

};


*rule new_rule(); //0
int add_fact(*fact, *rule);//1
int create_ccl(*fact, *rule);//0
int test_fact(*fact, *rule);//1
int remove_fact(*fact, *rule);//1
int test_empty_facts(*rule);//0
*char rule_head_fact(*rule);//1
*char rule_ccl(*rule);//0



struct bc {
  rule* rule;
  struct bc* next;
}

int addrule(*rule, *bc);
*rule bc_first_rule(*bc);
