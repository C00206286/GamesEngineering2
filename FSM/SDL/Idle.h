#pragma once
#include "State.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


static int currentAnimationNum;


class Idle : public State
{
public:
	Idle() {};
	~Idle() {};
	void jumping(Animation * a);
	void climbing(Animation * a);
};