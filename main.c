#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "population.h"
#include "recipes.h"

int main(int argn, char **args){
  Element a1,a2;
  Population population;
  float *distance;
  int N = 2;

  
  a1 = new_Element(1.0, 0.0,0.0, 1.0,0.0);
  a2 = new_Element(1.0, 10.0,0.0, -1.0,0.0);
  //print_Element(a1);
  //print_Element(a2);
  population = new_Population("2 body system",N);
  add_element_to_population(&population, a1);
  add_element_to_population(&population, a2);

  population.distance[0] = compute_distance(population.element[0],population.element[1]);

  //compute_distance(population,0,2);
  //compute_distance(population,1,2);

  print_Population(population);
  




  
  return 1;
}
