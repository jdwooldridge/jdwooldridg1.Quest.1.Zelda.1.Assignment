#pragma once
#include "Object.h"

class BlueLeever : public Object
{
	virtual void Update(GAME_FLT);
	virtual void Draw(GAME_FLT, View*);
};