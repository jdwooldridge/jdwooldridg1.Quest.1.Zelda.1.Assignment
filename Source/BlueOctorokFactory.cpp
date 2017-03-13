#include "BlueOctorokFactory.h"
//Create a blue octorok.
std::unique_ptr<Object> BlueOctorokFactory::create()
{
	return (std::unique_ptr<Object>)(new BlueOctorok());
}