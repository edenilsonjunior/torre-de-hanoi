#include "../include/jogo.h"

int main(int argc, char *argv[]){

    srand((unsigned int)time(NULL));

    Game jogo = iniciar_jogo();

    SDL_Event evento;
    int parou = false;

    while (!parou){
        while (SDL_PollEvent(&evento) != 0){

            if (evento.type == SDL_QUIT){
                parou = true;
            }

            else if (evento.type == SDL_MOUSEBUTTONDOWN){

                // Acha o indice do botao que foi clicado
                int temp = descobrir_click(jogo);

                // Faz uma jogada se o indice for entre 0 e 2
                if (temp == TORRE_1 || temp == TORRE_2 || temp == TORRE_3) jogada(jogo, temp);
                
                else if (temp == REINICIAR) reset_game(jogo);
                
                else if (temp == DESISTIR) resolver_jogo(jogo);
                
                else if (temp == SAIR) parou = true;
            }
        }

        // Se o jogo acabou e o usuario ganhou, exibe o background de vencedor            
        if(is_full(jogo->torres[TORRE_3]) && (jogo->status == JOGANDO)){
            jogo->status = GANHOU;
        }

        exibir_torres(jogo);
        exibir_contador(jogo);
        // exibir_botoes(jogo);
        
        SDL_RenderPresent(jogo->renderer);
    }
    end_game(jogo);

    return 0;
}