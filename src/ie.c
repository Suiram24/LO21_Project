#include <string.h>
#include <stdio.h>
#include "kb.h"
#include "rule.h"
#include "ie.h"

int is_fact_true(*char fact, *facts_t factList){
  do {
    if(strcmp(*factList.fact, fact) == 0){
      return 1;
    }
    factList = *factList.next;
  } while (*factList.next != NULL);

  if(strcmp(*factList.fact, fact) == 0){
    return 1;
  }else {
    return 0;
  }

}

*facts_t is_rule_true(*rule rule, *facts_t facts){
  if((test_empty_facts(rule)==0)&&(rule_ccl(rule)!=NULL)){
    do {
      if(!is_fact_true(*rule.fact, facts)){
        return NULL;
      }
      rule = *rule.next;
    } while((*rule.next != NULL);

    return *rule.fact;
  }else {
    return NULL;
  }

}

int add_fact_to_list(*char fact, *facts_t factList){
  if (is_fact_true(fact, factList)) {
    return 1;
  }else {
    facts_t newFact;
    strcpy(newFact.fact, fact);
    newfact.next = *factList.next;
    *factList.next = &newFact;
    return 0;

  }
}

*facts_t inference_engine(*kb_t kb, *facts_t facts){
  kb_t  *pKB = kb;
  facts_t *pFacts = facts;
  facts_t resultFacts;

  while (pFacts != NULL) {
    add_fact_to_list(*pFacts.fact, &resultFacts);
    pFacts = *pFacts.next;
  }
  
  while (pKB != NULL) {
    if(is_rule_true(*pKB.rule, &resultFacts)){
      add_fact_to_list(rule_ccl(*pkb.rule),&resultFacts);
    }
  }
  return &resultFacts;
}
