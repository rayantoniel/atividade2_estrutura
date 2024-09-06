#ifndef PARKING_H
#define PARKING_H
#include "Car.h"
#include "Alley.h"
#define MAX_QUEUE_SIZE 20
#define MAX_ALLEYS 2
#define MAX_CARS_PER_ALLEY 10

typedef struct {
    Alley *alley1;
    Alley *alley2;
    Car queue[MAX_QUEUE_SIZE];
    int start_queue;
    int end_queue;
     Alley alleys[MAX_ALLEYS];
} Parking;


void initialize_parking(Parking *p);  
void manage_input(Parking *p, Car c, int alley_number);  
void manage_exit(Parking *p, char *plate);  
void print_parking(Parking *p, int alley_number);  
void display_alley(Alley *a);

#endif