#pragma once

#include "Engine.h"
 class Entity
{
public: 
	std::shared_ptr<Entity> Parent; 
	Engine& EngineRef;
	std::string Name;
	virtual void OnStart();
	virtual void Tick(float deltaTime) = 0;
	virtual void Draw() = 0;
	virtual void OnDestroy() ;
	Entity(const std::string& Name,Engine& Engine);
	virtual ~Entity();

};

