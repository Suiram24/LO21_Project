#ifndef KB_H
#define KB_H

#include <string.h>
#include <stdio.h>


typedef struct kb {
  rule* rule;
  struct kb* next;
};

kb* new_kb();

int addrule(*rule, *kb)

*rule kb_first_rule(*kb);

#endif
