#pragma once
#include "ObjectFactory.h"
#include "RedLeever.h"

class RedLeeverFactory : public ObjectFactory
{
public:
	virtual std::unique_ptr<Object> create();
};