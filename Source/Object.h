#pragma once
#include <random>
#include <memory>
#include "SDL.h"
#include "Definitions.h"
#include "View.h"
#include "InputDevice.h"
#include "Texture.h"
#include "GraphicsDevice.h"
#include "tinyxml\tinyxml.h"

class Object
{
public:
	Object();
	~Object();
	bool Initialize(TiXmlElement*, GraphicsDevice*, InputDevice*, std::shared_ptr<Texture>);
	virtual void Update(GAME_FLT); //= 0;
	virtual void Draw(GAME_FLT, View*);// = 0;
	GAME_VEC getPosition();
	void setPosition(GAME_VEC);
	GAME_FLT getAngle();
	void setAngle(GAME_FLT);
	float genRndNum(float, float);

protected:
	GraphicsDevice* gDevice;
	InputDevice* iDevice;
	std::shared_ptr<Texture> texture;
	GAME_VEC position;
	GAME_VEC startPosition;
	GAME_FLT angle;
    bool goBackward;

};