#include "entitymatcher.h"
typedef std::list<int>::iterator entitiesIter;

EntityMatcher::EntityMatcher(std::list<int> entities){
	this->entities = entities;
}

EntityMatcher::~EntityMatcher(){
}

const std::list<int>& EntityMatcher::getEntities(){
	return entities;
}

struct EntityMatcher::Entity{
	int id;
	entitiesIter iter;
	int position;
	Entity(int id, entitiesIter iter, int position){
		this->id = id;
		this->iter = iter;
		this->position = position;
	}
};


// If id was found - returns Entity object(id of entity, iterator to to it in a entities list and its position).
// If element was not found returns Entity object(id, entities.end() and 0)
EntityMatcher::Entity EntityMatcher::find(int id){
	// position - position of entity with this id
	int position = 1;
	for (entitiesIter iter = entities.begin(); iter!= entities.end(); ++iter, ++position){
		if((*iter) == id){
			return Entity(id, iter, position);
		}
	}
	// if id was not found - return id, entities.end() and 0
	return Entity(id, entities.end(), 0);
}

// mathes 2 entities changing their rating. Variable 'choice' could equals to 1 or 2 meaning wich entity won (entity with id_1 or id_2).
void EntityMatcher::match(int id_1, int id_2, int choice){
	//TODO can this be done in a better way?
	/*
	if (choice == 1){
		Entity winner = find(id_1);
		Entity looser = find(id_2);
	}else{
		Entity winner = find(id_2);
		Entity looser = find(id_1;)
	}
	*/
	Entity winner = (choice == 1)? find(id_1) : find(id_2);
	Entity looser = (choice == 1)? find(id_2) : find(id_1);

	bool winnerInEntities = winner.position != 0;  // winner.iter != entities.end();
	bool looserInEntities = looser.position != 0;  // looser.iter != entities.end();
	
	if(winnerInEntities && looserInEntities){
		// If winner's rating is higher than looser's
		if(winner.position > looser.position){
			// winner goes before looser (if looser was #1 winner becomes #1 and looser becomes #2)
			entities.splice (looser.iter, entities, winner.iter);
		}
		// else - nothing changes
	}
	
	if(!winnerInEntities && looserInEntities){
		// winner goes before looser
		entities.insert(looser.iter, winner.id);
	}


	if(winnerInEntities && !looserInEntities){
		// looser goes to the end of a list
		entities.push_back(looser.id);
	}

	if(!winnerInEntities && !looserInEntities){
		// both winner and looser go to the end of a list 
		entities.push_back(winner.id);
		entities.push_back(looser.id);
	}	
}
