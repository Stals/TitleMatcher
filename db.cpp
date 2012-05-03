#include "db.h"

DB::DB(){
	c.connect("localhost");
	// get number of titles on startup so that i dont access db everytime i need to know it.
	numberOfTitles = c.count("TitleMatcher.titles");
}

//TODO mb get number of titles every time so that changing the db will effect running program?
int DB::getNumberOfTitles(){
	return numberOfTitles;
}

Title DB::getTitle(int id){
	// return a title where db_id == id
	auto_ptr<DBClientCursor> cursor = 
	c.query("TitleMatcher.titles", BSON("id"<<id));
	BSONObj p = cursor->next();

	Title title;
	title.id = id;
    title.name = p.getStringField("name");
    title.year = p.getIntField("year");
    title.genre = p.getStringField("genre");
    title.description = p.getStringField("description");
	
	return title;
}


Title DB::getTitleWhere(std::string condition){
	Title title;
	return title;
}
