#include "InputDevice.h"

InputDevice::InputDevice()
{

}

InputDevice::~InputDevice()
{

}

bool InputDevice::Initialize()
{
	//========================================
	//Construct Event System
	//========================================
	event = std::make_unique<SDL_Event>();
	if (!event) {
		printf("SDL Event could not initialize!");
		exit(1);
	}
	return true;
}

//Translate the
GAME_EVENT InputDevice::Translate()
{
	switch (event->key.keysym.sym) //Get the key event.
	{
	case SDLK_LEFT: //Return GAME_LEFT if the left arrow key was pressed.
		return GAME_LEFT;
		break;
	case SDLK_RIGHT: //Return GAME_RIGHT if the right arrow key was pressed.
		return GAME_RIGHT;
		break;
	case SDLK_UP: //Return GAME_UP if the up arrow key was pressed.
		return GAME_UP;
		break;
	case SDLK_DOWN: //Return GAME_DOWN if the down arrow key was pressed.
		return GAME_DOWN;
		break;
	}

	return GAME_NA; //Return nothing by default.
}

//Poll for the current event and return its equivalent GAME_EVENT.
GAME_EVENT InputDevice::GetEvent()
{
	if(SDL_PollEvent(event.get()))
		return Translate();
}