#ifndef DB_H
#define DB_H

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

	// get all the titles from db
	std::vector<Title> getTitles();
	// for example genre == RPG, year >= 2010 or name == Skyrim (or id = 12 insted)
	std::vector<Title> getTitlesWhere(std::string condition);
private:
	 DBClientConnection c;
};

#endif
