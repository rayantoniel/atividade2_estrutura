#ifndef PARKING_H
#define PARKING_H
#include "Car.h"
#include "Alley.h"
#define MAX_QUEUE_SIZE 20

typedef struct {
    Alley *alley1;
    Alley *alley2;
    Car queue[MAX_QUEUE_SIZE];
    int start_queue;
    int end_queue;
} Parking;


void initialize_parking(Parking *p);  // Inicializar becos e fila
void manage_input(Parking *p, Car c);  // Entrada de carros
void manage_exit(Parking *p, char *plate);  // Saída de carros
void print_parking(Parking *p);  // Exibir estado atual dos becos e fila
void display_alley(Alley *a);

#endif