#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>
#include<time.h>
#include "TADFilaCircularPrioridades.h"

char menu(){
    system("cls");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t===========================================\n");
    printf("\t\t\t\t\t  SIMULACAO FILA CIRCULAR COM PRIORIDADES       \n");
    printf("\t\t\t\t\t===========================================\n");
    printf("\t\t\t\t\t   [ ENTER ]  -  Iniciar\n");
    printf("\t\t\t\t\t   [ Qualquer tecla ]  - Sair\n");
    printf("\t\t\t\t\t===========================================\n");

    return toupper(getch());
}


int main(){
    srand(time(NULL));
    TpElemento elem, aux, aux2;
    TpFilaCircPri fila;

    char op, letra;
    int ut, sorteado, linhaI, colunaI, linhaR, colunaR;

    op = menu();
    while(op == 13){

        //desenhos
        system("cls");
        desenhaVetor(11, 30);
        desenhaDescricao();
        desenhaPlacaInformacoes(22, 5);

        //inicializacoes
        FCPInicializar(fila);
        ut = 1;
        letra = 65;
        colunaI =  colunaR = 36;
        linhaI = linhaR = 14;

        while(!FCPCheia(fila.cont) && !kbhit()){

            //Printa informacoes
            textcolor(6);
            limpaLinha(20, 24);
            gotoxy(20, 24);
            printf("UT = %d", ut);
            limpaLinha(20, 25);
            gotoxy(20, 25);
            printf("Inicio da fila = %d", fila.inicio);
            limpaLinha(20, 26);
            gotoxy(20, 26);
            printf("Final da fila = %d", fila.fim);
            limpaLinha(20, 27);
            gotoxy(20, 27);
            printf("Qtde elementos = %d", fila.cont);
            limpaLinha(50, 25);
            gotoxy(50, 24);
            aux2 = FCPElementoInicio(fila);
            if(!FCPVazia(fila.cont)){
                printf("Ultimo elemento a entrar = %c", aux2.Elemento);
                limpaLinha(50, 25);
                gotoxy(50, 25);
                printf("Prioridade = %d", aux2.Prioridade);
            }
            limpaLinha(50, 26);
            gotoxy(50, 26);
            if(!FCPVazia(fila.cont)){
                printf("Ultimo elemento a sair = %c", aux.Elemento);
                limpaLinha(50, 27);
                gotoxy(50, 27);
                printf("Prioridade = %d", aux.Prioridade);
            }
            textcolor(15);

            //Reset's
            if(letra == 90)
                letra = 65;

            //A cada iteração a fila é exibida
            apagaConteudoVetor();
            FCPExibir(fila);

            //insercao
            if(ut % 3 == 0){

                elem.Elemento = letra++;
                elem.Prioridade = rand()%3 +1;
                FCPInserir(fila, elem);

            }

            //Remocao
            if(ut % 7 == 0){

                aux = FCPRetirar(fila);

            }


            Sleep(1000);
            ut++;
        }
        getch();
        op = menu();
    }



    return 1;
}

