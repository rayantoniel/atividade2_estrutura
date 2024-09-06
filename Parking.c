#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parking.h"
#include "Alley.h"
#define MAX_QUEUE_SIZE 20
#include "Car.h"

void initialize_parking(Parking *p) {
    if (p == NULL) return;

    p->alley1 = create_alley();  // Cria o beco 1
    p->alley2 = create_alley();  // Cria o beco 2

    p->start_queue = 0;
    p->end_queue = 0;
    for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
        p->queue[i] = (Car){0};  // Inicializar cada carro com valores padrão
    }
}

void manage_input(Parking *p, Car c) {
    // Verifica se há espaço na fila
    if ((p->end_queue + 1) % MAX_QUEUE_SIZE == p->start_queue) {
        printf("A fila de espera está cheia. Não é possível adicionar mais carros.\n");
        return;
    }

    // Adiciona o carro à fila
    p->queue[p->end_queue] = c;
    p->end_queue = (p->end_queue + 1) % MAX_QUEUE_SIZE;

    // Verifica se há espaço em algum dos becos
    if (add_car_to_alley(p->alley1, c)) {
        return;
    }
    if (add_car_to_alley(p->alley2, c)) {
        return;
    }

    printf("Todos os becos estão cheios. Carro aguardando na fila.\n");
}

void manage_exit(Parking *p, char *plate) {
    // Remove o carro dos becos
    if (remove_car_from_alley(p->alley1, plate) ||
        remove_car_from_alley(p->alley2, plate)) {
        // Se o carro não foi encontrado nos becos, procura na fila
        for (int i = p->start_queue; i != p->end_queue; i = (i + 1) % MAX_QUEUE_SIZE) {
            if (strcmp(p->queue[i].plate, plate) == 0) {
                // Remove o carro da fila
                for (int j = i; j != p->end_queue; j = (j + 1) % MAX_QUEUE_SIZE) {
                    p->queue[j] = p->queue[(j + 1) % MAX_QUEUE_SIZE];
                }
                p->end_queue = (p->end_queue - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
                printf("Carro com placa %s removido da fila.\n", plate);
                return;
            }
        }
        printf("Carro com placa %s não encontrado.\n", plate);
    } else {
        printf("Carro com placa %s removido dos becos.\n", plate);
    }
}

void print_parking(Parking *p) {
    printf("Beco 1:\n");
    display_alley(p->alley1);
    printf("Beco 2:\n");
    display_alley(p->alley2);
    printf("Fila de Espera:\n");
    for (int i = p->start_queue; i < p->end_queue; i++) {
        printf("Carro: %s\n", p->queue[i].plate);
    }
}



