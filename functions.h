#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <SDL.h>
#define cc_max 60
#define cf_max 60

void muestromatriz(int mat[][cc_max], int cf,int cc);
int contarvecinos(int mat[][cc_max] ,int i, int j, int cf,int cc);
int estadomatriz(int mat[][cc_max],int cf,int cc);
void inicializar_sapo(int matriz[][cc_max],int cf,int cc);
void inicializar_glider(int matriz[][cc_max],int cf,int cc);
void inicializar_glidergun(int matriz[][cc_max],int cf,int cc);
void inicializar_pulsar(int matriz[][cc_max],int cf,int cc);
void modosdejuego(int matriz[][cc_max],int cf,int cc);



#endif // FUNCTIONS_H_INCLUDED
