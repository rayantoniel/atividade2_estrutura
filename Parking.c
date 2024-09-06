#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parking.h"

void print_parking(Parking *p) {
    printf("Beco 1:\n");
    display_beco(&p->beco1);
    printf("Beco 2:\n");
    display_beco(&p->beco2);
    printf("Fila de Espera:\n");
    for (int i = p->inicio_fila; i < p->fim_fila; i++) {
        printf("Carro: %s\n", p->fila[i].placa);
    }
}
