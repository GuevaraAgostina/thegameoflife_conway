#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int contarvecinos(int mat[][cc_max],int i, int j, int cf,int cc)
{
    int vecinos=0;
    int k,l;

    // Iteramos sobre los vecinos en el rango de -1 a 1 para filas y columnas
    for (k = i - 1; k <= i + 1; k++)
    {
        for (l = j - 1; l <= j + 1; l++)
        {
            // Verificamos si estamos dentro del rango y no son la celda actual
            if ((k >= 0 && k < cf) && (l >= 0 && l < cc) && !(k == i && l == j))
            {

                // !=3 porque significa que esa celula estaba muerta y en la prox generacion revivira, osea revive temporalmente por lo que no debemos contarla como viva
                if (mat[k][l] != 0 &&mat[k][l]!=3 )
                    vecinos++;
            }
        }
    }

    return vecinos;
}

int estadomatriz(int mat[][cc_max],int cf,int cc)
{
    int i,j,vecinos;

    /*
    3-- estaba muerta y vive o revive;
    2--estaba viva y muere.
    Usamos VALORES TEMPORALES para no alterar la matriz actual
    */
    for(i = 0; i < cf; i++)
    {
        for(j = 0; j < cc; j++)
        {
            vecinos=contarvecinos(mat,i,j,cf,cc);

            if (mat[i][j] == 1)
            {
                // muere si tiene menos de 2 o más de 3 vecinos
                if (vecinos < 2 || vecinos > 3)
                    mat[i][j] = 2;  // celula viva muere temporalmente
                // Si tiene 2 o 3 vecinos, no hacemos nada (sigue viva EN UNO)
            }
            // Si la celula esta muerta y tiene exactamente 3 vecinos, revive
            else if (mat[i][j] == 0 && vecinos == 3)
                mat[i][j] = 3;  // celula muerta revive temporalmente
        }
    }

    //definimos los valores definitivamente
    for(i = 0; i < cf; i++)
    {
        for(j = 0; j < cc ; j++)
        {
            if(mat[i][j] == 2)
                mat[i][j] = 0;
            else if (mat[i][j] == 3)
                mat[i][j] = 1;  // Revive definitivamente
        }
    }

    return 0;
}


void muestromatriz(int mat[][cc_max], int cf,int cc)
{
    int i,j;

    printf("\n");
    for(i = 0; i < cf; i++)
    {
        for(j = 0; j < cc; j++)
            printf(" %2d ",mat[i][j]);
        printf("\n");
    }
}


