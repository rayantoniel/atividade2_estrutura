#include "Car.h"

typedef struct {
    Car car;
    struct elem *next;
} Elem;

typedef struct{
    Elem *head;
    int count;
} Alley;

Alley *create_alley();  // Criar beco
void release_alley(Alley *a);  // Liberar memória do beco
int push_car(Alley *a, Car c);  // Adicionar carro no topo do beco
int pop_car(Alley *a);  // Remover o carro no topo do beco
int alley_full(Alley *a);  // Verificar se o beco está cheio
int alley_empty(Alley *a);  // Verificar se o beco está vazio
void display_alley(Alley *a);  // Exibir carros no beco
void initialize_alley(Alley *a);
int add_car_to_alley(Alley *a, Car c);
int remove_car_from_alley(Alley *a, char *plate);

