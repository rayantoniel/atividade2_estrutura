#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parking.h"
#include "Car.h"


void menu() {
    int option;
    Parking p;
    initialize_parking(&p);
    do {
        printf("\nEstacionamento:\n");
        printf("1. Entrada de Carro\n");
        printf("2. Saída de Carro\n");
        printf("3. Exibir Estado do Estacionamento\n");
        printf("0. Sair\n");
        scanf("%d", &option);
        
        switch(option) {
            case 1: {
                Car c;
                printf("Digite a placa do carro: ");
                scanf("%s", c.plate);
                c.maneuver = 0;
                manage_input(&p, c);
                break;
            }
            case 2: {
                char plate[8];
                printf("Digite a placa do carro que deseja retirar: ");
                scanf("%s", plate);
                manage_exit(&p, plate);
                break;
            }
            case 3: {
                print_parking(&p);
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(option != 0);
}

int main() {
    menu();
    return 0;
}