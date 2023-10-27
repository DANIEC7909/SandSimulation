#include "Entity.h"
void Entity::OnStart()
{
}
void Entity::OnDestroy()
{
}
//#include "Engine.h"
Entity::Entity(const std::string& name, Engine& engine) : Name(name),EngineRef(engine)
{
	Entity::Name = name;
	Entity::EngineRef = engine;
	SDL_Log("New Entity created");
    OnStart();
	
}

Entity::~Entity()
{
	
	OnDestroy();
}



