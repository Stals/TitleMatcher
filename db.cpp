#include "db.h"
DB::DB(){
	c.connect("localhost");
}

DB::~DB(){}

std::vector<Title> DB::getTitles(){  
	auto_ptr<DBClientCursor> cursor =
    c.query("tutorial.persons", BSONObj());
  while( cursor->more() )
      cout << cursor->next().toString() << endl;

	return std::vector<Title>();
}

std::vector<Title> DB::getTitlesWhere(std::string condition){

		return std::vector<Title>();

}
