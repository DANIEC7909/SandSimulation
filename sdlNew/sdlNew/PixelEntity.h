#pragma once
#include "Entity.h"
class PixelEntity :  public Entity
{
public:
	PixelEntity(const std::string Name, Engine& EngineRef) : Entity(Name, EngineRef)
	{
		OnStart();
	}
	void OnStart();
	 void Tick(float deltaTime);
	 void Draw() override;
	 void OnDestroy();
	 ~PixelEntity()
	 {
		 OnDestroy();
	 }
	 std::shared_ptr<std::vector<SpaceObject>> GlobalSpaceObject;
	 Uint8 r = 255;
	 Uint8 g = 0;
	 Uint8 b = 0;
	 Uint8 a = 255;

	 int ParticleSpeed=1;

	 Vector position= Vector(340,400);
	 int id;
};

