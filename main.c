/*
    nbody-c
    Copyright (C) 2020 Victor De la Luz
                       vdelaluz@enesmorelia.unam.mx

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>
#include "element.h"
#include "population.h"
#include "recipes.h"



int main(int argn, char **args){
  Element a1,a2;
  Population population;
  float *distance;
  int N = 5;
  int i,j,k;
  int miproc;
  int numproc;

  float start,end;
  
  MPI_Init (&argn, &args); /* Inicializar MPI */
  MPI_Comm_rank(MPI_COMM_WORLD,&miproc); /* Determinar el rango
 del proceso invocado*/
  MPI_Comm_size(MPI_COMM_WORLD,&numproc); /* Determinar el nume
ro de procesos */

  MPI_Barrier (MPI_COMM_WORLD);

  
  population = new_Population("n-body system",N);
  
  for(i=0; i<N; i++){
    add_element_to_population(&population, new_Element(1.0, (float)i, 0.0, 0.0,0.0));
  }

  //a1 = new_Element(1.0, 0.0,0.0, 1.0,0.0);
  //a2 = new_Element(1.0, 10.0,0.0, -1.0,0.0);
  //print_Element(a1);
  //print_Element(a2);

  //add_element_to_population(&population, a1);
  //add_element_to_population(&population, a2);
  k=0;
  //for(i=0;i<population.n_elements-1;i++){

  start = (population.n_distance/numproc)*miproc;
  end = (population.n_distance/numproc)*(miproc+1);
  for(i=0;i<population.n_elements-1;i++){
    //for(j=i+1 ;j<population.n_elements;j++){
    for(j=i+1 ;j<population.n_elements;j++){
      if ((start<=k) && (k<end)){
      //printf("%i,%i\n",i,j);
	  population.distance[k] = compute_distance(population.element[i],population.element[j]);
	}
      k++;
    }
  }
  
  //  population.distance[0] = compute_distance(population.element[0],population.element[1]);



  //compute_distance(population,0,2);
  //compute_distance(population,1,2);
  print_Population(population);

  MPI_Finalize();
  
  return 1;
}
