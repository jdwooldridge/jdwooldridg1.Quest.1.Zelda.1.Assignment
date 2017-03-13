#include "RedLeever.h"

void RedLeever::Update(GAME_FLT gameTime)
{
	float distanceToGo = startPosition.x + 20; //Set the distance that the leever will travel.

     if(getPosition().x >= distanceToGo) //If the leever has gone the determined travel distance, go backward.
    {
        goBackward = true;
    }
    if(getPosition().x <= startPosition.x - distanceToGo) //If the leever has not reached the distance it will travel, keep going forward.
    {
        goBackward = false;
    }
    if(goBackward) //Decrement the leever's x value if it's travelling backward.
        position.x -= genRndNum(0, 0.1);
    else //Otherwise keep going forward.
        position.x += genRndNum(0, 0.1);
}

//Draw the leever.
void RedLeever::Draw(GAME_FLT gameTime, View* view)
{
	texture->Draw(gDevice->getRenderer(), view, position, angle, NULL);
}