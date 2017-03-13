#include "ObjectFactory.h"

std::unique_ptr<Object> ObjectFactory::create()
{
	return std::unique_ptr<Object>();
}
