
#include <string.h>
#include <stdio.h>
#include "rule.h"

rule_t* new_rule(){
  rule_t *newRule = malloc(sizeof(rule_t));
  strcpy(newRule->fact,"");
  newRule->ccl =0;
  newRule->next = NULL;

  return newRule;
}

int add_fact(char* fact, rule_t* rule){

  rule_t *rule_transit, *rule_ccl, *new_fact;
  new_fact = new_rule();
  rule_transit=rule;


      while ((rule->next) != 0){

          rule_transit=rule;
          rule = rule->next;

      }

      rule_ccl=rule;
      strcpy(new_fact->fact,fact);


      if (rule->ccl==1){
          rule_transit->next=new_fact;
          new_fact->next=rule_ccl;
      } else {
          rule->next= new_fact;
      }
      return 1;

}

int create_ccl(char* fact, rule_t* rule){

  while (rule->next != 0) {
    rule = rule->next;

  }
  if(rule->ccl == 0){
    rule_t *ccl = new_rule();
    strcpy(ccl->fact, fact);
    ccl->ccl = 1;
    rule->next = ccl;
    return 0;
  }else {
    return 1;
  }

}

int test_empty_facts(rule_t* rule){

  if(rule->next == 0){

    return 1;
  }else if (rule->next->ccl == 1){

    return 1;
  }else{

    return 0;
  }
}

int test_fact(char* fact, rule_t* rule){
  while (rule->next!=0){
      if (strcmp(rule->fact,fact)==0){
          return 1;
      }
      rule=rule->next;
  }
  if ((rule->ccl == 0) && (strcmp(rule->fact,fact)==0) ){
      return 1;
  }else {
    return 0;
  }
}

int remove_fact(char* fact, rule_t* rule){
  rule_t *rule_transit,*rule_ccl;
  if (test_empty_facts(rule)==1){
      return 0;
  } else {
      rule_transit=rule;
      while (rule!=0){

        if ((strcmp(rule->fact,fact)==0)&&(rule->ccl == 0)){
            rule_transit->next = rule->next;
            free(rule);
            return 1;
        }
        rule_transit=rule;
        rule=rule->next;
      }
      return 0;
  }
}

char* rule_head_fact(rule_t* rule){
  if (test_empty_facts(rule)==1){
      return NULL;
  } else {
    return rule->next->fact;
  }
}

char* rule_ccl(rule_t* rule){
  while (rule->next != 0) {
    rule = rule->next;
  }
  if (rule->ccl == 1){
    return &(rule->fact);
  }else {
    return NULL;
  }
}
