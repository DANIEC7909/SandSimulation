#include "Engine.h"
#include "Entity.h"
Entity& Engine::Instantiate(std::shared_ptr<Entity> entity)
{
	Engine::Entities.push_back(std::move(entity));
	return *Engine::Entities.back();
}



void Engine::Destroy(std::shared_ptr<Entity> entity) {

	auto predicate = [&entity](const std::shared_ptr<Entity>& e) {
		return e.get() == entity.get();
		};

	Engine::Entities.erase(std::remove_if(Engine::Entities.begin(), Engine::Entities.end(), predicate), Engine::Entities.end());
	
}

Engine::Engine()
{
	SDL_Init(SDL_INIT_VIDEO);

	Window = SDL_CreateWindow(Engine::AppName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WindowW, WindowH, 0);
	if (!Window) {
		SDL_Log("Cannot create windww %s", SDL_GetError());
		return;
	}
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);

}

Engine::~Engine()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Log("Engine Stopped!");
	SDL_Quit();
}
