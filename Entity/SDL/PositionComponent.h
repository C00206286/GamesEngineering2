#pragma once
#include "Component.h"
#include <iostream>



class PositionComponent : public Component
{
public:
	PositionComponent(int startPositionX, int startPositionY) : positionX(startPositionX),positionY(startPositionY) { id = 2; }
	/* Data Only */
	int getPositionX() { return positionX; }
	int getPositionY() { return positionY; }
	void setPositionX(int givenX) {
		this->positionX = givenX;
	}
	void setPositionY(int givenY) {
		this->positionY = givenY;
	}
private:
	int positionX;
	int positionY;

};
