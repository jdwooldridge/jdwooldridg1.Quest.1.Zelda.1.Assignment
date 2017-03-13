#include "BlueOctorok.h"

void BlueOctorok::Update(GAME_FLT gameTime)
{
        setAngle(getAngle() + genRndNum(0, 0.1)); //Rotate the octorok in place.
}

//Draw the octorok.
void BlueOctorok::Draw(GAME_FLT gameTime, View* view)
{
	texture->Draw(gDevice->getRenderer(), view, position, angle, NULL);
}