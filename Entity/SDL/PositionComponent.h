#pragma once
#include "Component.h"
#include <iostream>



class PositionComponent : public Component
{
public:
	PositionComponent() : positionX(100),positionY(100) {}
	/* Data Only */
	int getPositionX() { return positionX; }
	int getPositionY() { return positionX; }
	void setPositionX(int positionX) {
		this->positionX = positionX;
	}
	void setPositionY(int positionY) {
		this->positionY = positionY;
	}
private:
	int positionX;
	int positionY;

};
