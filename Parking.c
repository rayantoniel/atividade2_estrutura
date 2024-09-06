#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parking.h"
#include "Alley.h"

//Cria o estacionamento
void initialize_parking(Parking *p) {
    if (p == NULL) return;

    p->alley1 = create_alley();  
    p->alley2 = create_alley();  

    p->start_queue = 0;
    p->end_queue = 0;
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        p->queue[i] = (Car){0};  // Inicializa cada carro com valores padrão
    }
}

//Entrada dos carros nos becos
void manage_input(Parking* p, Car c, int alley_number) {
    Alley* alley;

    if (alley_number == 1) {
        alley = p->alley1;
    } else if (alley_number == 2) {
        alley = p->alley2;
    } else {
        printf("\nNúmero de beco inválido!\n");
        return;
    }

    if (alley->count >= MAX_CARS_PER_ALLEY) {
        printf("\nO beco está cheio!\n");
        return;
    }

    //Adiciona o carro ao beco
    Elem* new_elem = (Elem*)malloc(sizeof(Elem));
    if (new_elem == NULL) {
        printf("\nErro ao alocar memória para o carro.\n");
        return;
    }

    new_elem->car = c;
    new_elem->next = alley->head;
    alley->head = new_elem;
    alley->count++;

    printf("\nCarro adicionado ao beco %d.\n", alley_number);
}

//Remove carro dos becos
void manage_exit(Parking *p, char *plate) {
    if (remove_car_from_alley(p->alley1, plate) ||
        remove_car_from_alley(p->alley2, plate)) {
        for (int i = p->start_queue; i != p->end_queue; i = (i + 1) % MAX_QUEUE_SIZE) {
            if (strcmp(p->queue[i].plate, plate) == 0) {
                for (int j = i; j != p->end_queue; j = (j + 1) % MAX_QUEUE_SIZE) {
                    p->queue[j] = p->queue[(j + 1) % MAX_QUEUE_SIZE];
                }
                p->end_queue = (p->end_queue - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
                printf("\nCarro com placa %s removido da fila.\n", plate);
                return;
            }
        }
        printf("\nCarro com placa %s não encontrado.\n", plate);
    } else {
        printf("\nCarro com placa %s removido dos becos.\n", plate);
    }
}

void print_parking(Parking *p, int alley_number) {
    printf("\nBeco 1:\n");
    display_alley(p->alley1);
    printf("\nBeco 2:\n");
    display_alley(p->alley2);
    printf("\nFila de Espera:\n");
    for (int i = p->start_queue; i != p->end_queue; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("Carro: %s\n", p->queue[i].plate);
    }
}
