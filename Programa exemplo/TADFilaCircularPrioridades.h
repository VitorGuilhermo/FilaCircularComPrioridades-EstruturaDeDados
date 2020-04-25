#define MAXFILA 10

struct TpElemento{
    char Elemento;
    int Prioridade;
};
struct TpFilaCircPri{
    int inicio, fim, cont;
    TpElemento fila[MAXFILA];
};

void FCPInicializar(TpFilaCircPri &F){
    F.inicio = 0;
    F.fim = -1;
    F.cont = 0;
}

void FCPInserir(TpFilaCircPri &FCP, TpElemento Elemento){
    TpElemento aux;
    int i;

    if(FCP.fim == MAXFILA -1)   // se o fim for a ultima posição do vetor, ele recebe -1 para assim ser inserido na posição 0 (o inicio)
        FCP.fim = -1;

    FCP.fila[++FCP.fim] = Elemento;
    i = FCP.fim;

    while(i>FCP.inicio && FCP.fila[i].Prioridade < FCP.fila[i-1].Prioridade){
        aux = FCP.fila[i];
        FCP.fila[i] = FCP.fila[i-1];
        FCP.fila[i-1] = aux;
        i--;
    }

    FCP.cont ++;
}

TpElemento FCPRetirar (TpFilaCircPri &FCP){
    TpElemento aux;

    aux = FCP.fila[FCP.inicio++];      // a variável aux recebe o elemento do início da fila, o que vai ser retirado

    if(FCP.inicio == MAXFILA)     // se o inicio for == MAXFILA ele recebe 0, ele "reseta", volta pro início
        FCP.inicio = 0;

    FCP.cont --;  //decrementa o contador, ja que foi retirado um elemento

    return aux;
}

TpElemento FCPElementoInicio(TpFilaCircPri F){
    return F.fila[F.inicio];
}

TpElemento FCPElementoFIM(TpFilaCircPri F ){
    return F.fila[F.fim];
}

char FCPVazia( int cont ){
    return cont == 0;
}

char FCPCheia(int cont){
    return cont == MAXFILA;
}

void FCPExibir(TpFilaCircPri F){
    TpElemento aux;
    int coluna = 36;
    while(!FCPVazia(F.cont)){
        aux = FCPRetirar(F);
        gotoxy(coluna, 14);
        printf("%c%d", aux.Elemento, aux.Prioridade);
        coluna += 5;
    }
}


//desenhos
void desenhaVetor(int linha, int coluna){
    char vetor[][100] = {
                                "  ______________________________________________________",
                                " |   _________________________________________________  |",
                                " |_>|    |    |    |    |    |    |    |    |    |    |_|",
                                "    |    |    |    |    |    |    |    |    |    |    |",
                                "    |____|____|____|____|____|____|____|____|____|____|",
                                "      0    1    2    3    4    5    6    7    8    9"
                                };
    textcolor(3);
    for(int i = 0; i<6; i++){
        gotoxy(coluna, linha+i);
        printf("%s\n", vetor[i]);
    }
    textcolor(15);
}

void desenhaDescricao(){
    textcolor(11);
    gotoxy(8, 1);
    printf("==========================================================================================================");
    gotoxy(38, 2);
    printf("SIMULACAO DE UMA FILA CIRCULAR COM PRIORIDADES               ");
    gotoxy(8, 3);
    printf("==========================================================================================================");
    textcolor(15);
}
void desenhaPlacaInformacoes(int linha, int coluna){
    int i;
    char placa [][150] = {
                        " _____________________________________________________________________________________________________________",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|_____________________________________________________________________________________________________________|"
                        };
    textcolor(3);
    for(i = 0; i<7; i++){
        gotoxy(coluna, linha+i);
        printf("%s\n", placa[i]);
    }
    textcolor(15);
}

void limpaLinha(int x, int y){
    int i;
    for(i=0; i< 25; i++){
        gotoxy(x+i, y);
        printf(" ");
    }
}

void apagaConteudoVetor(){
    for(int i = 36; i<86; i=i+5){
        gotoxy(i, 14);
        printf("  ");
    }
}
