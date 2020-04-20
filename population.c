#include <stdio.h>
#include <stdlib.h>
#include "element.h"
#include "population.h"

int total_sum(int n){
  return n*(n-1)/2;
}

Population new_Population(char *name, int size){
  Population population;
  sprintf(population.name, "%s" , name);
  population.n_elements=0;
  population.size = size;
  population.element = malloc(size * sizeof(Element));
  population.distance = malloc(total_sum(size)*sizeof(float));
  return population;

}

int add_element_to_population(Population *population, Element element){
  population->element[population->n_elements] = element;
  population->n_elements++;
  return population->n_elements;
}

int print_Population(Population population){
  int i;
  int n;
  printf("List of elements\n");
  for(i=0;i<population.n_elements;i++){
    print_Element(population.element[i]);
  }
  n = sizeof(population.distance)/sizeof(float);
  printf("List of distances\n");
  for(i=0;i<n ;i++){
    printf("%lf\t",population.distance[i]);
  }
  printf("\n");

  
  return 1;
}

