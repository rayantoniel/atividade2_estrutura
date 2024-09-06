#include "Car.h"
#include "Alley.h"

typedef struct{
    char plate[8];
    int maneuver;
} Car;


struct Parking {
    Alley alley1;
    Alley alley2;
    Car queue[20];
    int start_queue;
    int end_queue;
};

void initialize_parking(Parking *p);  // Inicializar becos e fila
void manage_input(Parking *p, struct Car c);  // Entrada de carros
void manage_exit(Parking *p, char *plate);  // Saída de carros
void print_parking(Parking *p);  // Exibir estado atual dos becos e fila