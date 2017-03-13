#include "RedOctorokFactory.h"
//Create a red octorok.
std::unique_ptr<Object> RedOctorokFactory::create()
{
	return (std::unique_ptr<Object>)(new RedOctorok());
}