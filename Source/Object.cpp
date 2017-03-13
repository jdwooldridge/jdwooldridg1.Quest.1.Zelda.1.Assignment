#include "Object.h"

Object::Object()
{

}

Object::~Object()
{

}
//Initialize an object.
bool Object::Initialize(TiXmlElement* root, GraphicsDevice* gDevice, InputDevice* iDevice, std::shared_ptr<Texture> texture)
{
	//Initialize the devices and set goBackward to its initial value of false.
	this->gDevice = gDevice;
	this->iDevice = iDevice;
	this->texture = texture;
    goBackward = false;

	//Set position and angle values if the XML element isn't a nullptr.
	if (root != nullptr)
	{
		//Parse the X, Y, and angle attributes into constant chars.
		const char* x = root->Attribute("x");
		const char* y = root->Attribute("y");
		const char* a = root->Attribute("angle");

		//Put the integer equivalent of the above chars into the object's startposition (X, Y) coordinates and the angle.
		startPosition.x = (GAME_FLT)atoi(x); 
		startPosition.y = (GAME_FLT)atoi(y);
		angle = (GAME_FLT)atoi(a);

		//Set the object's X and Y to the start values.
		position.x = startPosition.x;
		position.y = startPosition.y;

		root = root->NextSiblingElement("GameAsset"); //Retrieve the next GameAsset element.
		return true;
	}
	else //XML element was nullptr.
		return false;
}

void Object::Update(GAME_FLT)
{
}

void Object::Draw(GAME_FLT, View *)
{
}

//Retrieve the object's position.
GAME_VEC Object::getPosition()
{
	return position;
}

//Set the object's position.
void Object::setPosition(GAME_VEC position)
{
	this->position = position;
}

//Get the object's angle.
GAME_FLT Object::getAngle()
{
	return angle;
}

//Set the object's angle.
void Object::setAngle(GAME_FLT angle)
{
	this->angle = angle;
}

//Generate a random number between the min and max parameters.
float Object::genRndNum(float min, float max)
{
	static std::random_device rDev;
	static std::default_random_engine e(rDev());
	static std::uniform_real_distribution<float> d(min,max);
	return d(e);
}
