#ifndef GAME_H
#define _GAME_H
#include "SDL.h"
#include "Definitions.h"
#include "InputDevice.h"
#include "ArtAssetLibrary.h"
#include "View.h"
#include "GameAssetLibrary.h"
#include "InputDevice.h"
#include "Object.h"
#include "GraphicsDevice.h"
#include "Timer.h"
#include "BlueOctorokFactory.h"
#include "BlueLeeverFactory.h"
#include "RedLeeverFactory.h"
#include "RedOctorokFactory.h"
#include "tinyxml\tinyxml.h"

#include <iostream>
#include <memory>
#include <vector>

class Game {

public:
	Game();
	~Game();
	bool Initialize();
	void Reset();
	bool LoadLevel(std::string, std::string);
	bool Run();
	bool Update();
	void Draw();

private:
	std::unique_ptr<GameAssetLibrary> gLibrary;
	std::unique_ptr<ArtAssetLibrary> aLibrary;
	std::unique_ptr<GraphicsDevice> gDevice;
	std::unique_ptr<InputDevice> iDevice;
	std::unique_ptr<Timer> timer;
	GAME_FLT gameTime;
	std::unique_ptr<View> view;
	std::vector<std::shared_ptr<Object>> objects;

};

#endif // !GAME_H
