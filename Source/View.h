#pragma once
#include "SDL.h"
#include "InputDevice.h"
#include "Definitions.h"

class View
{
public:
	View();
	~View();
	bool Initialize(InputDevice*, GAME_FLT, GAME_FLT);
	bool Update(GAME_FLT);
	GAME_VEC getPosition();

private:
	InputDevice* iDevice;
	GAME_VEC position;
	GAME_VEC center;

};

