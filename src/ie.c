#include <string.h>
#include <stdio.h>
#include "kb.h"
#include "rule.h"
#include "ie.h"

int is_fact_true(char* fact, facts_t* factList){
  while (factList->next != 0){

    if(strcmp(factList->fact, fact) == 0){

      return 1;
    }

    factList = factList->next;



  }


  if(strcmp(factList->fact, fact) == 0){
    return 1;
  }else {
    return 0;
  }

}

facts_t* is_rule_true(rule_t* rule, facts_t* facts){


  if((test_empty_facts(rule)==0)&&(rule_ccl(rule)!=0)){

    do {
      if(!is_fact_true(rule->fact, facts)){
        return NULL;
      }
      rule = rule->next;
    } while(rule->next != 0);

    return rule->fact;
  }else {

    return NULL;
  }

}

int add_fact_to_list(char* fact, facts_t* factList){

  if (is_fact_true(fact, factList)) {

    return 1;
  }else {

    facts_t *newFact = malloc(sizeof(facts_t));
    strcpy(newFact->fact, fact);
    newFact->next = factList->next;
    factList->next = newFact;
    return 0;

  }
}

facts_t* inference_engine(kb_t* kb, facts_t* facts){
    char v[3] = "";
  kb_t  *pKB = kb->next;
  facts_t *pFacts = facts;
  facts_t* resultFacts = malloc(sizeof(facts_t));
  resultFacts->next = NULL;
  strcpy(resultFacts->fact, &v);


  while (pFacts != 0) {


    add_fact_to_list(pFacts->fact, resultFacts);
    pFacts = pFacts->next;
  }

  while (pKB != 0) {

    if(is_rule_true(pKB->rule, resultFacts)){

      add_fact_to_list(rule_ccl(pKB->rule),resultFacts);
    }

    pKB = pKB->next;

  }
  return resultFacts;
}
