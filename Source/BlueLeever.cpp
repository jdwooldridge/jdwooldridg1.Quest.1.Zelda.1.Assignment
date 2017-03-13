#include "BlueLeever.h"

void BlueLeever::Update(GAME_FLT gameTime)
{
	GAME_FLT distanceToGo = startPosition.y + 20; //Set the distance that the leever will travel.

    if ( getPosition().y >= distanceToGo ) //If the leever has gone the determined travel distance, go backward.
    {
        goBackward = true;
    }
    if ( getPosition().y <= startPosition.y - distanceToGo ) //If the leever has not reached the distance that it will travel, keep going forward.
    {
        goBackward = false;
    }
    if ( goBackward ) //Decrement the leever's x value if it's travelling backward.
        position.y -= genRndNum( 0, 0.1 );
    else //Otherwise keep going forward.
        position.y += genRndNum( 0, 0.1 );
}

//Draw the leever.
void BlueLeever::Draw(GAME_FLT gameTime, View* view)
{
	texture->Draw(gDevice->getRenderer(), view, position, angle, NULL);
}