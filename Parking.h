#include "Car.h"
#include "Alley.h"

struct Parking {
    Alley beco1;
    Alley beco2;
    Car queue[20];
    int start_queue;
    int end_queue;
};

void initialize_parking(Parking *p);  // Inicializar becos e fila
void manage_input(Parking *p, struct Car c);  // Entrada de carros
void manage_exit(Parking *p, char *plate);  // Saída de carros
void print_parking(Parking *p);  // Exibir estado atual dos becos e fila