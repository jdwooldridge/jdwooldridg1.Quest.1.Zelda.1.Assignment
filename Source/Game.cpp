#include "Game.h"

Game::Game()
{
	/*gDevice._Myptr() = new GraphicsDevice(SCREEN_WIDTH, SCREEN_HEIGHT);
	aLibrary._Myptr() = new ArtAssetLibrary();
	timer._Myptr() = new Timer();
	view._Myptr() = new View();
	gLibrary._Myptr() = new GameAssetLibrary();
	iDevice._Myptr() = new InputDevice();*/

	gDevice = std::make_unique<GraphicsDevice>(SCREEN_WIDTH, SCREEN_HEIGHT);
	aLibrary = std::make_unique<ArtAssetLibrary>();
	timer = std::make_unique<Timer>();
	view = std::make_unique<View>();
	gLibrary = std::make_unique<GameAssetLibrary>();
	iDevice = std::make_unique<InputDevice>();
	gameTime = 0;
}

Game::~Game()
{
	gDevice->ShutDown();
}

bool Game::Initialize()
{

	if (!gDevice->Initialize(false)) //Initialize graphics device; throw error if it is not possible.
	{
		std::cout << "Could not initialize graphics device!" << std::endl;
		return false;
	}
	if (!aLibrary->Initialize(gDevice.get())) //Initialize art library; throw error if it is not possible.
	{
		std::cout << "Could not initialize art library!" << std::endl;
		return false;
	}
	if (!gLibrary->Initialize()) //Initialize game asset library; throw error if it is not possible.
	{
		std::cout << "Could not initialize game asset library!" << std::endl;
		return false;
	}
	if (!iDevice->Initialize()) //Initialize input device; throw error if it is not possible.
	{
		std::cout << "Could not initialize input device!" << std::endl;
		return false;
	}
	if (!timer->Initialize()) //Initialize timer; throw error if it is not possible.
	{
		std::cout << "Could not initialize timer!" << std::endl;
		return false;
	}
	if (!view->Initialize(iDevice.get(), 0, 0)) //Initialize view; throw error if it is not possible.
	{
		std::cout << "Could not initialize game view!" << std::endl;
		return false;
	}
	timer->start(); //Start the timer.
	return true;
}

//Update every object in the objects vector, along with the view.
bool Game::Update()
{
	view->Update(gameTime); //Update the view.
	for (auto&& object : objects) //Iterate over every object and update them.
		object->Update(gameTime);
	return true;
}

//Perform updating and drawing of objects, amongst other things.
bool Game::Run()
{
	Update(); //Update objects.
	Draw(); //Draw objects.
	++gameTime; //Increment game time.
	if (timer->getTicks() < FRAME_DELAY) //Adjust frame rate.
		SDL_Delay(FRAME_DELAY - timer->getTicks());
	return false;
}

//Draw every object.
void Game::Draw()
{
	gDevice->Begin(); //C
	for(auto&& object : objects)
	{ 
		object->Draw(gameTime, view.get());
	}
	gDevice->Present();
}

bool Game::LoadLevel(std::string levelConfigFile, std::string objectConfigFile)
{
	Reset();

	//Load files.
	TiXmlDocument lvlConfig(levelConfigFile.c_str());
	TiXmlDocument objConf(objectConfigFile.c_str());

	//Don't do anything if the config files cannot be loaded.
	if (!lvlConfig.LoadFile()) {
		std::cout << "Error: Could not load level XML file!";
		return false;
	}

	if (!objConf.LoadFile()) {
		std::cout << "Error: Could not load object XML file!";
		return false;
	}

	TiXmlElement* objRoot = objConf.FirstChildElement("Objects");
	objRoot = objRoot->FirstChildElement("Creature");
	while (objRoot)
	{
		std::string name = objRoot->Attribute("name");
		std::string path = objRoot->Attribute("sprite");

		aLibrary->AddAsset(name, path);

		objRoot = objRoot->NextSiblingElement("Creature");
	}

	TiXmlElement* lvlRoot = lvlConfig.FirstChildElement("Level2");

	lvlRoot = lvlRoot->FirstChildElement("GameAsset");
	//std::unique_ptr<Object> tmp(); //THIS PROBABLY CAUSES PROBLEMS.
	while (lvlRoot)
	{
		std::shared_ptr<ObjectFactory> objectFactory = gLibrary->Search(lvlRoot->Attribute("name")); //Find object factory for the loaded object.
		std::shared_ptr<Object> tmp = objectFactory->create(); //Create the object.
		if (!tmp->Initialize(lvlRoot, gDevice.get(), iDevice.get(), aLibrary->Search(lvlRoot->Attribute("name")))) //Inititalize the object.
		{
			std::cout << "Error: Could not initialize object!";
			return false;
		}
		else
			objects.push_back(tmp);
		lvlRoot = lvlRoot->NextSiblingElement("GameAsset");
	}
	return true;
}

//Purge the objects vector.
void Game::Reset()
{
	objects.clear();
}