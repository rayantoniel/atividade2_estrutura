#ifndef ALLEY_H
#define ALLEY_H
#include "Car.h"

typedef struct elem{
    Car data;
    struct elem *next;
} Elem;

typedef struct elem *Alley;

Alley *create_alley();  // Criar beco
void release_alley(Alley *a);  // Liberar memória do beco
int push_car(Alley *a, Car c);  // Adicionar carro no topo do beco
int pop_car(Alley *a);  // Remover o carro no topo do beco
int alley_full(Alley *a);  // Verificar se o beco está cheio
int alley_empty(Alley *a);  // Verificar se o beco está vazio
void display_alley(Alley *a);  // Exibir carros no beco

#endif
