#pragma once

#include "Entity.h"
#include "Client.h"

class EntityManager {

private:
	bool lose = false;

public:
	Client* firstClient;
	void tick();
	void render();
	void addEntity(Entity *e);
	void addClient(Client *c);
	void removeLeavingClients();
	bool didILose();
	std::vector<Entity*> entities;
	int client_counter = 0;

};