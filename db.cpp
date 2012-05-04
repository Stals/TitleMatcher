#include "db.h"

DB::DB(){
	try{
		c.connect("localhost");
		// get number of titles on startup so that i dont access db everytime i need to know it.
		numberOfTitles = c.count("TitleMatcher.titles");
	}catch( DBException &e ) {
    	std::cerr<<"Unable to connect to DB"<<std::endl;
    	std::cerr<<"caught "<<e.what()<<endl;
  }

}

//TODO mb get number of titles every time so that changing the db will effect running program? 
// (if programm works and i delete somthing from db, program could try to get that deleted element)
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
    title.description = p.getStringField("description");
	// get all the genres	
	std::vector<BSONElement> v = p.getField("genres").Array();
	for(std::vector<BSONElement>::iterator it = v.begin(); it != v.end(); ++it)
		title.genres.push_back(it->String());	
	
	return title;
}


Title DB::getTitleWhere(std::string condition){
	Title title;
	return title;
}
