#include <math.h>
#include "recipes.h"

float compute_distance(Element A, Element B){
  float x_a,x_b, y_a,y_b;
  x_a = A.position[0];
  y_a = A.position[1];
  x_b = B.position[0];
  y_b = B.position[1];
 return sqrt(pow(x_a-x_b,2) + pow(y_a-y_b,2));
 
}



unsigned long factorial(unsigned long f)
{
    if ( f == 0 ) 
        return 1;
    return(f * factorial(f - 1));
}

