#include "db.h"
DB::DB(){
	c.connect("localhost");
	// get number of titles on startup so that i dont access db everytime i need to know it.
	numberOfTitles = c.count("TitleMatcher.titles");
}

//TODO mb get number of titles every time so that changing the db will effect running program?
int DB::getNumberOfTitles(){
	std::cout<<"number of titles = "<<numberOfTitles<<std::endl;
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

std::vector<Title> DB::getTitles(){  
	auto_ptr<DBClientCursor> cursor =
	c.query("TitleMatcher.titles", BSONObj());
	while( cursor->more() )
		cout << cursor->next().toString() << endl;

	return std::vector<Title>();
}

std::vector<Title> DB::getTitlesWhere(std::string condition){
	return std::vector<Title>();
}
