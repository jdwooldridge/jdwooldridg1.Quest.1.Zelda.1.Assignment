#pragma once
#include "Object.h"

class RedOctorok : public Object
{
	void Update(GAME_FLT);
	void Draw(GAME_FLT, View*);
private:
	GAME_VEC center; //Private member for red octorok that is used for determining the center of the circle that it will spin around in.
};