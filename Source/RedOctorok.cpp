#include "RedOctorok.h"

void RedOctorok::Update(GAME_FLT gameTime)
{
    float radius = 50;
	//Assume the center of the circle to be the startPosition + radius.
	center.x = startPosition.x + radius;
	center.y = startPosition.y + radius;

	position.x = center.x + (cos(angle * (PI / 360)) * radius); //Calculate the new x position.
	position.y = center.y + (sin(angle * (PI / 360)) * radius); //Calculate the new y position.
    setAngle((getAngle() + 0.1)); //Calculate new angle.
}

//Draw the red octorok.
void RedOctorok::Draw(GAME_FLT gameTime, View* view)
{
	texture->Draw(gDevice->getRenderer(), view, position, angle, NULL); 
}