#pragma once
#include <memory>
#include "SDL.h"
#include "Definitions.h"

class InputDevice
{
public:
	InputDevice();
	~InputDevice();
	bool Initialize();
	GAME_EVENT GetEvent();
private:
	std::unique_ptr<SDL_Event> event;
	GAME_EVENT Translate();
};