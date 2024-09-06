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
        a->head = NULL;  // Beco começa vazio
        a->count = 0;
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
        return 0;  // Beco cheio
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
        return 0;  // Beco vazio
    Elem *in = a->head;
    a->head = in->next;
    free(in);
    a->count--;
    return 1;
}

// Verifica se o beco está cheio
int alley_full(Alley *a) {
    return (a->count >= 10);  // Verifica se há 10 carros no beco
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
}


void initialize_alley(Alley *a) {
    a->head = NULL;
    a->count = 0;
}

// Adiciona um carro ao beco
int add_car_to_alley(Alley *a, Car c) {
    if (a->count >= 10) {  // Verifica se o beco está cheio
        return 0;  // Não há espaço
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
    return 1;  // Carro adicionado com sucesso
}

// Remove um carro do beco
int remove_car_from_alley(Alley *a, char *plate) {
    // Verifica se o beco está vazio
    if (alley_empty(a)) {
        return 0;  // Não há carros no beco
    }

    Alley *temp = create_alley();  // Pilha temporária para armazenar os carros manobrados
    Elem *current = a->head;
    int found = 0;

    // Percorre o beco até encontrar o carro alvo
    while (current != NULL) {
        if (strcmp(current->car.plate, plate) == 0) {
            found = 1;
            break;  // Carro encontrado, saímos do laço
        } else {
            // Empilha o carro na pilha temporária e incrementa o número de manobras
            current->car.maneuver++;
            push_car(temp, current->car);
            pop_car(a);  // Remove o carro do beco original
            current = a->head;
        }
    }

    // Se o carro foi encontrado, removê-lo
    if (found) {
        pop_car(a);  // Remove o carro alvo
    }

    // Reinsere todos os carros da pilha temporária no beco original
    while (!alley_empty(temp)) {
        Car temp_car = temp->head->car;
        pop_car(temp);
        push_car(a, temp_car);  // Reinsere o carro no beco original
    }

    release_alley(temp);  // Libera a memória da pilha temporária

    return found;  // Retorna 1 se o carro foi encontrado e removido
}

