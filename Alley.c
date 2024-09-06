#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alley.h"
#include "Parking.h"
#include "Car.h"

// Cria um novo beco
Alley *create_alley() {
    Alley *a = (Alley *) malloc(sizeof(Alley));
    if (a != NULL) {
        a->head = NULL;
        a->count = 0;
        a->maneuvers = 0; 
    }
    return a;
}

// Libera a memória de um beco
void release_alley(Alley *a) {
    if (a != NULL) {
        Elem *in;
        while (a->head != NULL) {
            in = a->head;
            a->head = a->head->next;
            free(in);
        }
        free(a);
    }
}

// Adiciona um carro ao beco
int push_car(Alley *a, Car c) {
    if (alley_full(a))
        return 0;  
    Elem *new = (Elem*) malloc(sizeof(Elem));
    if (new == NULL)
        return 0;
    new->car = c;
    new->next = a->head;
    a->head = new;
    a->count++;
    return 1;
}

// Remove um carro do beco
int pop_car(Alley *a) {
    if (alley_empty(a))
        return 0;  
    Elem *in = a->head;
    a->head = in->next;
    free(in);
    a->count--;
    return 1;
}

// Verifica se o beco está cheio
int alley_full(Alley *a) {
    return (a->count >= 10);  
}

// Verifica se o beco está vazio
int alley_empty(Alley *a) {
    return (a->head == NULL);
}

// Exibe os carros no beco
void display_alley(Alley *a) {
    if (a == NULL) return;
    Elem *in = a->head;
    while (in != NULL) {
        printf("Carro: %s, Manobras: %d\n", in->car.plate, in->car.maneuver);
        in = in->next;
    }
    printf("Manobras totais no beco: %d\n", a->maneuvers);  
}

// Adiciona um carro ao beco
int add_car_to_alley(Alley *a, Car c) {
    if (a->count >= 10) {
        return 0;  
    }

    Elem *new_elem = (Elem *)malloc(sizeof(Elem));
    if (!new_elem) {
        printf("Erro ao alocar memória para novo carro.\n");
        return 0;
    }
    new_elem->car = c;
    new_elem->next = a->head;
    a->head = new_elem;
    a->count++;
    return 1;  
}

// Remove um carro do beco e contabiliza as manobras apenas nesse beco
int remove_car_from_alley(Alley *a, char *plate) {
    if (alley_empty(a)) {
        return 0;  
    }

    Alley *temp = create_alley();  
    Elem *current = a->head;
    int found = 0;

    // Percorre o beco até encontrar o carro alvo
    while (current != NULL) {
        if (strcmp(current->car.plate, plate) == 0) {
            found = 1;  
            break;  
        } else {
            current->car.maneuver++;  
            push_car(temp, current->car);  
            pop_car(a);  
            a->maneuvers++;  
            current = a->head;  
        }
    }

    // Se o carro foi encontrado, removê-lo do beco
    if (found) {
        pop_car(a);  
    }

    // Reinsere todos os carros da pilha temporária no beco original
    while (!alley_empty(temp)) {
        Car temp_car = temp->head->car;
        pop_car(temp);  
        push_car(a, temp_car);  
    }

    release_alley(temp); 
    return found;  
}
