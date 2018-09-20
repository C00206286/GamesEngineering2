#include "BridgePattern.h"

int main(void)
{
	DrawAPI* api = new DrawImpl();
	Character* character = new Player(api);
	character->Draw();
	std::cin.get();
}