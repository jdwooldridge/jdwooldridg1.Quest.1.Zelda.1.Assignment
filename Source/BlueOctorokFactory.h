#pragma once
#include "ObjectFactory.h"
#include "BlueOctorok.h"

class BlueOctorokFactory : public ObjectFactory
{
public:
	virtual std::unique_ptr<Object> create();
};