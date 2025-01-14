#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


void modosdejuego(int matriz[][cc_max],int cf,int cc)
{
    int patron = 0;
    printf("Que patron desea utilizar? (coloque el numero correspondiente):\n1 - sapo\n2 - planeador\n3 - canion de planeadores\n4 - pulsar\n ");
    scanf("%d",&patron);


    switch(patron){
        case 1: inicializar_sapo(matriz,cf,cc);
            break;
        case 2: inicializar_glider(matriz,cf,cc);
            break;
        case 3: inicializar_glidergun(matriz,cf,cc);
            break;
        case 4: inicializar_pulsar(matriz,cf,cc);
            break;
    }
}


void inicializar_sapo(int matriz[][cc_max],int cf,int cc) {
    int i,j;
    // Inicializa todas las celdas como muertas (0)
    for (i = 0; i < cf; i++) {
        for ( j = 0; j < cc; j++) {
            matriz[i][j] = 0;
        }
    }

    matriz[1][2] = 1;
    matriz[1][3] = 1;
    matriz[1][4] = 1;
    matriz[2][1] = 1;
    matriz[2][2] = 1;
    matriz[2][3] = 1;

}


void inicializar_glider(int matriz[][cc_max],int cf,int cc) {
    int i,j;
    // Inicializa todas las celdas como muertas (0)
    for (i = 0; i < cf; i++) {
        for ( j = 0; j < cc; j++) {
            matriz[i][j] = 0;
        }
    }

    matriz[0][1] = 1;
    matriz[1][2] = 1;
    matriz[2][0] = 1;
    matriz[2][1] = 1;
    matriz[2][2] = 1;

}


void inicializar_glidergun(int matriz[][cc_max],int cf,int cc) {
    int i,j;
    // Inicializa todas las celdas como muertas (0)
    for (i = 0; i < cf; i++) {
        for ( j = 0; j < cc; j++) {
            matriz[i][j] = 0;
        }
    }

    matriz[17][1] = 1;
    matriz[17][2] = 1;
    matriz[18][1] = 1;
    matriz[18][2] = 1;


    matriz[15][21] = 1;
    matriz[16][21] = 1;
    matriz[16][22] = 1;
    matriz[15][22] = 1;
    matriz[14][23] = 1;
    matriz[14][25] = 1;
    matriz[13][25] = 1;
    matriz[17][21] = 1;
    matriz[17][22] = 1;
    matriz[18][23] = 1;
    matriz[18][25] = 1;
    matriz[19][25] = 1;

    matriz[15][13] = 1;
    matriz[15][14] = 1;
    matriz[18][18] = 1;
    matriz[18][15] = 1;
    matriz[16][12] = 1;
    matriz[16][16] = 1;
    matriz[17][11] = 1;
    matriz[17][17] = 1;
    matriz[18][11] = 1;
    matriz[18][17] = 1;
    matriz[19][11] = 1;
    matriz[19][17] = 1;
    matriz[20][12] = 1;
    matriz[20][16] = 1;
    matriz[21][13] = 1;
    matriz[21][14] = 1;


    matriz[15][35] = 1;
    matriz[15][36] = 1;
    matriz[16][35] = 1;
    matriz[16][36] = 1;


}



void inicializar_pulsar(int matriz[][cc_max],int cf,int cc) {
    int i,j;
    // Inicializa todas las celdas como muertas (0)
    for (i = 0; i < cf; i++) {
        for ( j = 0; j < cc; j++) {
            matriz[i][j] = 0;
        }
    }


    //PULSAR
    matriz[1][3] = 1;
    matriz[1][4] = 1;
    matriz[1][5] = 1;
    matriz[1][9] = 1;
    matriz[1][10] = 1;
    matriz[1][11] = 1;

    matriz[6][3] = 1;
    matriz[6][4] = 1;
    matriz[6][5] = 1;
    matriz[6][9] = 1;
    matriz[6][10] = 1;
    matriz[6][11] = 1;
    matriz[8][3] = 1;
    matriz[8][4] = 1;
    matriz[8][5] = 1;
    matriz[8][9] = 1;
    matriz[8][10] = 1;
    matriz[8][11] = 1;
    matriz[13][3] = 1;
    matriz[13][4] = 1;
    matriz[13][5] = 1;
    matriz[13][9] = 1;
    matriz[13][10] = 1;
    matriz[13][11] = 1;

    matriz[3][1] = 1;
    matriz[3][6] = 1;
    matriz[3][8] = 1;
    matriz[3][13] = 1;
    matriz[4][1] = 1;
    matriz[4][6] = 1;
    matriz[4][8] = 1;
    matriz[4][13] = 1;
    matriz[5][1] = 1;
    matriz[5][6] = 1;
    matriz[5][8] = 1;
    matriz[5][13] = 1;
    matriz[9][1] = 1;
    matriz[9][6] = 1;
    matriz[9][8] = 1;
    matriz[9][13] = 1;
    matriz[10][1] = 1;
    matriz[10][6] = 1;
    matriz[10][8] = 1;
    matriz[10][13] = 1;
    matriz[11][1] = 1;
    matriz[11][6] = 1;
    matriz[11][8] = 1;
    matriz[11][13] = 1;



}
