#pragma once
#include <SDL.h>
#include <iostream>
#include <memory>
#include<string> 
#include <vector>
class Engine
{
public:
	SDL_Renderer* Renderer;
	Uint32 WindowH=600;
	Uint32 WindowW=800;
	SDL_Window* Window;
	SDL_Event InputEvent;
	bool GameRunning = true;
	std::string AppName = "San Simulation";
	unsigned int lastUpdateTime = 0;
	std::vector<std::shared_ptr<class Entity>>Entities;
	Entity& Instantiate (std::shared_ptr<class Entity> entity);
	void Destroy(std::shared_ptr<class Entity> entity);
	Engine();
	~Engine();
};
	struct Vector
	{
		Vector(float _x=0, float _y=0) {
			x = _x;
			y = _y;
		}
		float x;
		float y;
		float CalculateDistance(Vector _position) {
			float deltaX = _position.x - x;
			float deltaY = _position.y - y;
			return std::sqrt(deltaX * deltaX + deltaY * deltaY);
		}
	};
	struct VectorInt
	{
		VectorInt(int _x=0, int _y=0) {
			x = _x;
			y = _y;
		}
		
		Vector ToFloat() {
			return Vector(x, y);
		}
		float CalculateDistance(VectorInt _position) {
			float deltaX = _position.x - x;
			float deltaY = _position.y - y;
			return std::sqrt(deltaX * deltaX + deltaY * deltaY);
		}
		int x;
		int y;
	};

	struct SpaceObject {
		SpaceObject(int _id, Vector _position) {
			id = _id;
			position = _position;
		}
		long int id;
		Vector position;
	};