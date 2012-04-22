#include "titlematcher.h"
#include <cstdlib>

TitleMatcher::TitleMatcher(){
	titles.push_back(Title(1,"Oblivion","2006","RPG","Developer: Bethesda soft."));
	titles.push_back(Title(2,"Skyrim","2011","RPG","Developer: Bethesda soft."));
	titles.push_back(Title(3,"Morrowind","2000","RPG","Developer: Bethesda soft."));
	titles.push_back(Title(4,"Fallout 3","2008","RPG","Developer: Bethesda soft."));
	titles.push_back(Title(5,"Burnout: Paradise","","",""));
	titles.push_back(Title(6,"Legends of Grimrock","2012","Dungeon Crawler",""));
	titles.push_back(Title(7,"Super Meat Boy","","",""));
	getNewTitles();
}

TitleMatcher::~TitleMatcher(){

}

void TitleMatcher::dontKnowTitle(int titleNumber){
	switch (titleNumber){
		case 1:
			getNewTitle(title_1);
			break;
		case 2:
			getNewTitle(title_2);
			break;
		//TODO default:
			//error
	}
}

void TitleMatcher::submitChoice(int choice){
	entityMatcher.match(title_1.id, title_2.id, choice);
	getNewTitles();
}

// TODO should return list of title names (not id's)
const std::list<int> TitleMatcher::getTitles(unsigned int top){
	const std::list<int> titles = entityMatcher.getEntities();
	
	std::list<int>::const_iterator it = titles.begin();
	for(int i = 0; it != titles.end(); ++it, ++i){
		if (i == top) 
			break;
	}
	const std::list<int> result(titles.begin(), it);
	// Get names from a vector before i add db
	return result;
}

void TitleMatcher::getNewTitle(Title& title){
	// get new titles until they are different
	do{
		title = titles[rand() % titles.size()];
	}while(title_1.id == title_2.id);

}

void TitleMatcher::getNewTitles(){
	getNewTitle(title_1);
	getNewTitle(title_2);
}