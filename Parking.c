#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parking.h"
#include "Car.h"

typedef struct{
    char plate[8];
    int maneuver;
} Car;


typedef struct {
    Alley alley1;
    Alley alley2;
    Car queue[20];
    int start_queue;
    int end_queue;
} Parking;

void print_parking(Parking *p) {
    printf("Beco 1:\n");
    display_beco(&p->alley1);
    printf("Beco 2:\n");
    display_beco(&p->alley2);
    printf("Fila de Espera:\n");
    for (int i = p->start_queue; i < p->end_queue; i++) {
        printf("Carro: %s\n", p->queue[i].plate);
    }
}
