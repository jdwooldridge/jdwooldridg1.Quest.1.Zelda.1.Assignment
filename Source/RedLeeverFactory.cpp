#include "RedLeeverFactory.h"

//Create a red Leever.
std::unique_ptr<Object> RedLeeverFactory::create()
{
	return (std::unique_ptr<Object>)(new RedLeever());
}