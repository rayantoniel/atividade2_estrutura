#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Alley.h"
#include "Car.h"


struct Car {
    char plate[8];
    int maneuver;
};

struct elem {
    struct Car data;
    struct elem *next;
};

typedef struct elem Elem;  // Definindo um alias para "struct elem"
typedef struct elem *Alley; 

Alley *create_alley() {
    Alley *a = (Alley *) malloc(sizeof(Alley));
    if (a != NULL)
        *a = NULL;  // Beco começa vazio
    return a;
}

// Função para liberar a memória de um beco
void release_alley(Alley *a) {
    if (a != NULL) {
        Elem *in;
        while ((*a) != NULL) {
            in = *a;
            *a = (*a)->next;
            free(in);
        }
        free(a);
    }
}

int push_car(Alley *a, struct Car c) {
    if (alley_full(a))
        return 0;  // Beco cheio
    struct elem *new = (struct elem*) malloc(sizeof(struct elem));
    if (new == NULL)
        return 0;
    new->data = c;
    new->next = (*a);
    *a = new;
    return 1;
}

int pop_car(Alley *a) {
    if (alley_empty(a))
        return 0;  // Beco vazio
    struct elem *in = *a;
    *a = in->next;
    free(in);
    return 1;
}

// Função para verificar se o beco está cheio
int alley_full(Alley *a) {
    // Como estamos usando uma lista dinâmica, o beco só fica cheio se chegarmos a 10 carros
    int tamanho = 0;
    Elem *in = *a;
    while (in != NULL) {
        tamanho++;
        in = in->next;
    }
    return (tamanho >= 10);
}

// Função para verificar se o beco está vazio
int alley_empty(Alley *a) {
    return (*a == NULL);
}

// Função para exibir os carros no beco
void display_alley(Alley *a) {
    if (a == NULL) return;
    Elem *in = *a;
    while (in != NULL) {
        printf("Carro: %s, Manobras: %d\n", in->data.plate, in->data.maneuver);
        in = in->next;
    }
}

