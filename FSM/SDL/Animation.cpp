#include "Animation.h"
#include "Idle.h"

double animationCount = 0;
double delayCount = 0;

Animation::Animation()
{
	current = new Idle();
	currentAnimationNum = 0;
}
void Animation::idle()
{
	current->idle(this);
}
void Animation::jumping()
{
	currentAnimationNum = 4;
	current->jumping(this);

}
void Animation::climbing()
{
	currentAnimationNum = 2;
	current->climbing(this);
}
SDL_Rect Animation::AnimationUpdate(SDL_Rect rectImage)
{
	// Idle
	if(currentAnimationNum == 0)
	{
		rectImage.y = 0;
		rectImage.x = 425;
		delayCount = delayCount + 1;
		if (delayCount > 10000)
		{
			animationCount = 0;
			delayCount = 0;
			currentAnimationNum = 1;
		}
	}
	// Idling animation
	if(currentAnimationNum == 1)
	{
		rectImage.x = 0;
		rectImage.y = 425;
		if (rectImage.x < 510)
		{
			rectImage.x = rectImage.x + 85 * animationCount;
			if (delayCount > 1000)
			{
				if (animationCount < 5)
				{
					animationCount = animationCount + 1;
					delayCount = 0;

				}
				if (animationCount == 5)
				{
					animationCount = 0;
					currentAnimationNum = 0;
				}
			}
			delayCount = delayCount + 1;
		}
	}

	// Idle to Climbing

	if(currentAnimationNum == 2)
	{
		rectImage.x = 425;
		rectImage.y = 0;
		if (rectImage.x > 0)
		{
			rectImage.x = rectImage.x - 85 * animationCount;
			if (delayCount > 1000)
			{
				if (animationCount < 5)
				{

					animationCount = animationCount + 1;
					delayCount = 0;

				}
				if (animationCount == 5)
				{
					animationCount = 0;
					currentAnimationNum = 3;
					idle();
				}
			}
			delayCount = delayCount + 1;
		}
	}
	//Idle to Jumping
	if (currentAnimationNum == 4)
	{
		rectImage.x = 0;
		rectImage.y = 340;
		if (rectImage.x < 510)
		{
			rectImage.x = rectImage.x + 85 * animationCount;
			if (delayCount > 1000)
			{
				if (animationCount < 5)
				{
					animationCount = animationCount + 1;
					delayCount = 0;

				}
				if (animationCount == 5)
				{
					animationCount = 0;
					currentAnimationNum = 5;
					idle();
				}
			}
			delayCount = delayCount + 1;
		}
	}
	// Jumping To Idle
	if (currentAnimationNum == 5)
	{
		rectImage.x = 425;
		rectImage.y = 340;
		if (rectImage.x > 0)
		{
			rectImage.x = rectImage.x - 85 * animationCount;
			if (delayCount > 1000)
			{
				if (animationCount < 5)
				{
					animationCount = animationCount + 1;
					delayCount = 0;
				}
				if (animationCount == 5)
				{
					currentAnimationNum = 0;
					animationCount = 0;
				}


			}
			delayCount = delayCount + 1;
		}
	}

	// Climbing to Idle
	if (currentAnimationNum == 3)
	{
		rectImage.x = 0;
		rectImage.y = 0;
		if (rectImage.x < 510)
		{
			rectImage.x = rectImage.x + 85 * animationCount;
			if (delayCount > 1000)
			{
				if (animationCount < 5)
				{
					animationCount = animationCount + 1;
					delayCount = 0;
				}
				if (animationCount == 5)
				{
					currentAnimationNum = 0;
					animationCount = 0;
				}

			}
			delayCount = delayCount + 1;
		}
	}
	return rectImage;
}