#include "PixelEntity.h"

#include "Engine.h"

void PixelEntity::OnStart() 
{
	SDL_Log("Pixel Entity Created!");
}

void PixelEntity::Tick(float deltaTime)
{
    bool canMoveDown = true;
    bool canMoveLeft = true;
    bool canMoveRight = true;

    for (auto& so : *GlobalSpaceObject)
    {
        if (id != so.id) {
            if (position.y + ParticleSpeed == so.position.y && position.x == so.position.x) {
                canMoveDown = false;
            }

            if (position.y == so.position.y && position.x - ParticleSpeed == so.position.x) {
                canMoveLeft = false;
            }

            if (position.y == so.position.y && position.x + ParticleSpeed == so.position.x) {
                canMoveRight = false;
            }
        }
    }
if (!canMoveDown) {
        if (canMoveLeft && canMoveRight) {
            if (rand() % 2 == 0) {
                if (position.x - ParticleSpeed > 0) {
                    position.x -= ParticleSpeed;
                }
            }
            else {
                if (position.x + ParticleSpeed < EngineRef.WindowW) {
                    position.x += ParticleSpeed;
                }
            }
        }
        else if (canMoveLeft && position.x - ParticleSpeed > 0) {
            position.x -= ParticleSpeed;
        }
        else if (canMoveRight && position.x + ParticleSpeed < EngineRef.WindowW) {
            position.x += ParticleSpeed;
        }
    }
    else if (canMoveDown && position.y + ParticleSpeed < EngineRef.WindowH) {
        position.y += ParticleSpeed;
    }

    GlobalSpaceObject->at(id == 0 ? 0 : id - 1).position = position;

}

void PixelEntity::Draw()
{
	SDL_SetRenderDrawColor(EngineRef.Renderer, r, g, b, a);

	SDL_RenderDrawPoint(EngineRef.Renderer, (int)position.x, (int)position.y);
}

void PixelEntity::OnDestroy()
{
	//SDL_Log("PixelEntityDestroyed");
}


