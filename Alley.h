#include "Car.h"

struct Alley {
    Car cars[10];
    int top;
};

typedef struct elem *Alley;

Alley *create_alley();  // Criar beco
void release_alley(Alley *a);  // Liberar memória do beco
int push_car(Alley *a, struct Car c);  // Adicionar carro no topo do beco
int pop_car(Alley *a);  // Remover o carro no topo do beco
int alley_full(Alley *a);  // Verificar se o beco está cheio
int alley_empty(Alley *a);  // Verificar se o beco está vazio
void display_alley(Alley *a);  // Exibir carros no beco
