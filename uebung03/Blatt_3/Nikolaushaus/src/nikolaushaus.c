
/**
 *@file nikolaushaus.c
 *@brief Zeichnet Nikolaushaus in eigenem Fenster
 *
 * In diesem Programm wird mithilfe von SDL ein rotes Nikolaushaus in einem 
 * Fenster gezeichnet. Der SDL-Rendere übergibt dabei die Aufgabe des zeichnens 
 * an die Grafikkarte.
 *
 *
 * @author Daniel Kliewer
 * @author Dominik Jülich
 * @author Nesibe Mücahit
 *
 * return 0
 */

#include <SDL2/SDL.h>

int main (void){
	
	SDL_Window* window;
	SDL_Renderer* renderer;

	SDL_Init: SDL_Init(SDL_INIT_VIDEO);

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {	
		printf("SDL_Init failed: %s\n", SDL_GetError());
		return 1;
	}

	/* Erstellt Window mit Breite 800 und Hoehe 600 */
	window = SDL_CreateWindow( "Nikolaushaus", 0, 0, 800, 600, SDL_WINDOW_SHOWN);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	SDL_RenderDrawLine(renderer, 300, 500, 500, 500);	/* Untere Linie vom Haus*/
	SDL_RenderDrawLine(renderer, 300, 500, 300, 300);	/* Linke Seite */
	SDL_RenderDrawLine(renderer, 500, 500, 500, 300);	/* Rechte Seite */
	SDL_RenderDrawLine(renderer, 300, 300, 500, 300);	/* Obere Seite */
	SDL_RenderDrawLine(renderer, 300, 500, 500, 300);	/* Diagonale UL nach OR*/
	SDL_RenderDrawLine(renderer, 500, 500, 300, 300);	/* Diagonale UR nach OL */
	SDL_RenderDrawLine(renderer, 300, 300, 400, 200);	/* Dach Links */
	SDL_RenderDrawLine(renderer, 500, 300, 400, 200);	/* Dach Rechts */

	
	SDL_RenderPresent(renderer);
	
	SDL_Delay(10000);

	SDL_DestroyRenderer(renderer);

	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
