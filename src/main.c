#include <string.h>
#include <stdio.h>
#include "kb.h"
#include "rule.h"
#include "ie.h"

int main(){
  char v[3] = "";
  char a[3] = "A";
  char b[3] = "B";
  char c[3] = "C";
  char d[3] = "D";
  char e[3] = "E";
  char f[3] = "F";
  char g[3] = "G";

  //first rule : (A and B -> C)
  rule_t *regle1;
  regle1 = new_rule();
  add_fact(&a, regle1);
  add_fact(&b, regle1);
  create_ccl(&c, regle1);

  //second rule : (D and B and E -> G)
  rule_t *regle2;
  regle2 = new_rule();
  add_fact(&d, regle2);
  add_fact(&c, regle2);
  create_ccl(&g, regle2);

  //first rule : (A and B -> C)
  rule_t *regle3;
  regle3 = new_rule();
  add_fact(&a, regle3);
  add_fact(&b, regle3);
  add_fact(&e, regle3);
  add_fact(&d, regle3);
  add_fact(&c, regle3);
  add_fact(&g, regle3);
  create_ccl(&f, regle3);

//knowledge base with rules 1 and 2
  kb_t* pkb = new_kb();
  addrule(regle1, pkb);
  addrule(regle2, pkb);
  addrule(regle3, pkb);

//fact list
  facts_t* factList = malloc(sizeof(facts_t));
  strcpy(factList->fact, &v);
  factList->next = NULL;
  add_fact_to_list(&a, factList);
  add_fact_to_list(&b, factList);
  add_fact_to_list(&d, factList);
  add_fact_to_list(&e, factList);

//computing
  facts_t* result = inference_engine(pkb, factList);

//prompt result
  facts_t *res = result;
  printf("list : ");
  while (res != 0){
    printf("%s \n", res->fact);
    res = res->next;
  }

  return 0;
}
