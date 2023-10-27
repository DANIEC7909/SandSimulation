
#include "Engine.h"
#include "PixelEntity.h"
using namespace std; 



int main(int argc, char* argv[]) 
{
	shared_ptr<Engine> EnginePtr = make_shared<Engine>();


	float startTime = SDL_GetTicks();
	float deltaTime;

	bool LeftMouseButtonPressed = false;
	std::shared_ptr<vector<SpaceObject>> ObjectsInSpaces= make_shared<vector<SpaceObject>>();
	while (EnginePtr->GameRunning)
	{

		deltaTime = SDL_GetTicks() - startTime;

		startTime = SDL_GetTicks();

		//if (EnginePtr->lastUpdateTime + 60 < SDL_GetTicks())
	//	{
		//	EnginePtr->lastUpdateTime = SDL_GetTicks();

		// poll for events from SDL
		while (SDL_PollEvent(&EnginePtr->InputEvent))
		{
			EnginePtr->GameRunning = EnginePtr->InputEvent.type != SDL_QUIT;
			//temporairly  catch button here.
			if (EnginePtr->InputEvent.type == SDL_MOUSEBUTTONDOWN) {
				if (EnginePtr->InputEvent.button.button == SDL_BUTTON_LEFT) {
					LeftMouseButtonPressed = true;
				}
			}
			if (EnginePtr->InputEvent.type == SDL_MOUSEBUTTONUP) {
				if (EnginePtr->InputEvent.button.button == SDL_BUTTON_LEFT) {
					LeftMouseButtonPressed = false;
				}
			}
		}
		//Temporairly spawn object here.
		if (LeftMouseButtonPressed) {
			VectorInt StartLoc =VectorInt();
			SDL_GetMouseState(&StartLoc.x, &StartLoc.y);
			int id = ObjectsInSpaces->size();
			ObjectsInSpaces->push_back(SpaceObject(id, StartLoc.ToFloat()));

			PixelEntity* pe =dynamic_cast<PixelEntity*>(&EnginePtr->Instantiate(make_shared<PixelEntity>("Pixel", *EnginePtr)));
			pe->position = StartLoc.ToFloat();
			pe->id = id;
			pe->GlobalSpaceObject =(ObjectsInSpaces);
		//	SDL_Log("spawn");
		}

	
		SDL_SetRenderDrawColor(EnginePtr->Renderer, 0, 0, 0, 0);
		SDL_RenderClear(EnginePtr->Renderer);

		//render and tick entities
		if (EnginePtr->Entities.size() > 0) {
			for (auto& entity : EnginePtr->Entities)
			{
				entity->Tick(deltaTime);
				entity->Draw();
				
			}
		}
		SDL_RenderPresent(EnginePtr->Renderer);
	

	}


	return 0;
}
