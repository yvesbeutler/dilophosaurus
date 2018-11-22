#include <iostream>
#define GLEW_STATIC
#include <GL/glew.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

int main(int argc, char** argv) {
	SDL_Window* window;
	SDL_Init(SDL_INIT_EVERYTHING);

	// define the window
	window = SDL_CreateWindow("Dilophosaurus", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);

	// create a context for openGL (state machine)
	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	bool close = false;
	while(!close) {

		// delete old buffer content
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// double buffering
		SDL_GL_SwapWindow(window);

		// close window if clicked on exit
		SDL_Event event;
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT) {
				close = true;
			}
		}
	}

	return 0;
}