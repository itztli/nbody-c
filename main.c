#include <stdio.h>
#include <stdlib.h>
#include "element.h"

int main(int argn, char **args){
  Element a1,a2;

  a1 = new_Element(1.0, 0.0,0.0, 1.0,0.0);
  a2 = new_Element(1.0, 10.0,0.0, -1.0,0.0);

  print_Element(a1);
  print_Element(a2);
  
  return 1;
}
