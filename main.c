#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Parking.h"
#include "Car.h"

typedef struct {
    char plate[8];
    int maneuver;
} Car;

typedef struct {
    Alley alley1;
    Alley alley2;
    Car queue[20];
    int start_queue;
    int end_queue;
} Parking;

void menu() {
    int option;
    Parking p;
    inicializar_estacionamento(&p);
    do {
        printf("\nEstacionamento:\n");
        printf("1. Entrada de Carro\n");
        printf("2. Saída de Carro\n");
        printf("3. Exibir Estado do Estacionamento\n");
        printf("0. Sair\n");
        scanf("%d", &option);
        
        switch(option) {
            case 1: {
                struct Car c;
                printf("Digite a placa do carro: ");
                scanf("%s", c.plate);
                c.maneuver = 0;
                gerenciar_entrada(&p, c);
                break;
            }
            case 2: {
                char placa[8];
                printf("Digite a placa do carro que deseja retirar: ");
                scanf("%s", placa);
                gerenciar_saida(&p, placa);
                break;
            }
            case 3: {
                exibir_estacionamento(&p);
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
