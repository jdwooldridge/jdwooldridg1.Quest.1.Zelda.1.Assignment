#pragma once
#include "ObjectFactory.h"

class RedLeeverFactory : public ObjectFactory
{
	virtual std::unique_ptr<Object> create();
};