#include "BlueLeeverFactory.h"

//Create a blue leever.
std::unique_ptr<Object> BlueLeeverFactory::create()
{
	return (std::unique_ptr<Object>)(new BlueLeever());
}