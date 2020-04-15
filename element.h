#ifndef ELEMENT_H
#define ELEMENT_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct{
  float mass; //kg
  float position[2]; //[x,y] m
  float velocity[2]; // [x,y] m/s
}Element;

#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* ELEMENT_H */

