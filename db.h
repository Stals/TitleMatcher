#ifndef DB_H
#define DB_H
//TODO genre should be a list of strings
#include <vector>
#include <string>
#include <iostream> // for debug

#include "client/dbclient.h"
#include "title.h"

//TODO move this so that using mongo will not to everywhere
using namespace mongo;
//TODO mb rename
class DB{
	
public:	
	DB();

	int getNumberOfTitles(); //TODO rename 

	// returns title from db by its ID.
	Title getTitle(int id);
	
	// for example genre == RPG, year >= 2010 or name == Skyrim (or id = 12 insted)
	Title getTitleWhere(std::string condition);
private:
	 DBClientConnection c;
	 int numberOfTitles;
};

#endif
