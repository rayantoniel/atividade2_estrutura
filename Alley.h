#ifndef ALLEY_H
#define ALLEY_H
#include "Car.h"

typedef struct Elem{
    Car car;
    struct Elem *next;
} Elem;

typedef struct{
    Elem *head;
    int count;
} Alley;

Alley *create_alley();  
void release_alley(Alley *a);  
int push_car(Alley *a, Car c);  
int pop_car(Alley *a);  
int alley_full(Alley *a);  
int alley_empty(Alley *a);  
void display_alley(Alley *a);  
void initialize_alley(Alley *a);
int add_car_to_alley(Alley *a, Car c);
int remove_car_from_alley(Alley *a, char *plate);

#endif