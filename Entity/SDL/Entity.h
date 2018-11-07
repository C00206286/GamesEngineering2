#pragma once
#include <vector>
#include <iostream>
#include "Component.h"
class Entity
{
public:
	Entity(int idGiven) { id = idGiven; };
	int id;
	void addComponent(Component* c) { components.push_back(c); }
	void removeComponent(Component* c) {/* TBI */ }
	std::vector<Component*> getComponents() { return components; }
private:
	std::vector<Component*> components;
};