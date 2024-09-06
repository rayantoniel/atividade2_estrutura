#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parking.h"
#include "Car.h"

void print_parking(Parking *p) {
    printf("Beco 1:\n");
    display_alley(&p->alley1);
    printf("Beco 2:\n");
    display_alley(&p->alley2);
    printf("Fila de Espera:\n");
    for (int i = p->start_queue; i < p->end_queue; i++) {
        printf("Carro: %s\n", p->queue[i].plate);
    }
}
