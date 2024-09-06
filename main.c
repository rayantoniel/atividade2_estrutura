#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parking.h"
#include "Car.h"

void menu() {
    int option;
    int alley_number;

    Parking p;
    initialize_parking(&p);

    do {
        printf("\n========= ESTACIONAMENTO =========\n");
        printf("\n1. Entrada de Carro\n");
        printf("2. Saída de Carro\n");
        printf("3. Exibir Estado do Estacionamento\n");
        printf("0. Sair\n");

        scanf("%d", &option);
        
        switch(option) {
            case 1: {
                Car c;

                printf("\nDigite a placa do carro: ");
                scanf("%s", c.plate);
                c.maneuver = 0;

                printf("\nEscolha o beco (1 ou 2): ");
                scanf("%d", &alley_number);
                if (alley_number < 1 || alley_number > 2) {
                    printf("\nBeco inválido!\n");
                    break;
                }

                manage_input(&p, c, alley_number);

                break;
            }
            case 2: {
                char plate[8];

                printf("\nDigite a placa do carro que deseja retirar: ");
                scanf("%s", plate);
                manage_exit(&p, plate);

                break;
            }
            case 3: {
                print_parking(&p, alley_number);

                break;
            }
            case 0:
                printf("\nFinalizado!\n");

                break;
            default:
                printf("\nOpção invalida!\n");
        }
    } while(option != 0);
}

int main() {
    menu();
    return 0;
}