/* This is a library for matching two entities and buildng a list of entities sorted by rating (flickchart.com style). 
You can match any Entites. For example - games, films, books, board games ect.
This library stores list of entities id's and also changes entities rating depending on a user choice between them.

Mathcing algorithm:
	Both entities are on the list:
		If an entity that was higher won - nothing changed
		Else - winner goes above the looser
	Only one entity is on the list:
		If an entity that wasn't in a list won - it goes above the looser
		If an entity that was in a list won - looser goes to the end of a list (push_back(looser))
	Neither of entities are on the list:
		Winner goes above the looser, both entities added in the end of a list (push_back(winner), push_back(looser))
*/

#ifndef ENTITYMATCHER_H
#define ENTITYMATCHER_H

#include <list>

class EntityMatcher{
public:
	// if we have 'entities' from previous time we will load them
	EntityMatcher(std::list<int> entities = std::list<int>()); 
	~EntityMatcher();

	// Warning: returns a const ref to avoid copying
	const std::list<int>& getEntities();

	// mathes 2 entities changing their rating. Variable 'choice' could equals to 1 or 2 meaning wich entity won (entity with id_1 or id_2).
	void match(int id_1, int id_2, int choice);

private:
	// Todo rewrite using my method and compare speed
	// Stores entities ID
	std::list<int> entities;
	struct Entity;
	Entity find(int id);

};

#endif
