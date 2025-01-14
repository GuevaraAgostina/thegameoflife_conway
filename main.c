#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL.h>
#include "functions.h"

//configuracion del codeblocks para compilar SDL

//project>properties>project's build options> search settings, linker and linker settings
//(compiler)\include\SDL2; (linker)\lib ; (other linker) -lmingw32 -lSDL2main -lSDL2

int main(int argc, char *argv[])
{
    int mat[cf_max][cc_max];
    int cf = 30,cc = 40;
    int cont = 0,continuar = 1;
    char rta[3], rta2[3];
    int delay = 50;

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event e;
    SDL_Rect fillRect;
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); // Color blanco para células vivas
    int cellSize = 20; // Tamaño de cada célula


    if (SDL_Init(SDL_INIT_VIDEO) != 0){

        printf("SDL No se ha podido inicializar! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }


    window = SDL_CreateWindow("Juego de la vida",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          1632,
                          1050,
                          SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Error en la creacion de la ventana: %s\n", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("No se ha podido crear el lienzo! SDL Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }


    modosdejuego(mat,cf,cc);


    while(continuar){ //se puede poner solo continuar?

       // Procesa eventos SDL
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                continuar = 0;
            }
        }

        // Limpia la pantalla
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);

        // Dibuja la matriz

        for (int i = 0; i < cf; i++) {
            for (int j = 0; j < cc; j++) {
                if (mat[i][j] == 1) { // Si la célula está viva
                    fillRect.x = j * cellSize; //Pos X
                    fillRect.y = i * cellSize; //Pos Y
                    fillRect.h = cellSize; //Alto
                    fillRect.w = cellSize; //Ancho
                    SDL_SetRenderDrawColor(renderer, 0x03, 0x11, 0x98, 0x82);
                    SDL_RenderFillRect(renderer, &fillRect); // Dibuja la célula
                }

            }
        }

        SDL_RenderPresent(renderer); // Actualiza la ventana


        estadomatriz(mat,cf,cc);


        cont++;

        if(cont == 100){

            printf("\nDesea seguir viendo generaciones?");
            fflush(stdin);
            scanf("%2s", rta);

            if(strcmpi(rta,"si") == 0){
                cont = 0;

                printf("\nDesea cambiar el modo de juego?");
                fflush(stdin);
                scanf("%2s", rta2);

                if(strcmpi(rta2,"si") == 0)
                    modosdejuego(mat,cf,cc);
                else continue;
            }


            else
                continuar = 0;
        }


        SDL_SetWindowTitle(window, "juego de la vida de conway");
        SDL_Delay(delay);

    }

        // Limpieza de SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;

}
