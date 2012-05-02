#include "db.h"
DB::DB(){
	c.connect("localhost");
}

std::vector<Title> DB::getTitles(){  
	auto_ptr<DBClientCursor> cursor =
	c.query("Titles.titles", BSONObj());
	while( cursor->more() )
		cout << cursor->next().toString() << endl;

	return std::vector<Title>();
}

std::vector<Title> DB::getTitlesWhere(std::string condition){
	return std::vector<Title>();
}
