#include "titlematcher.h"


TitleMatcher::TitleMatcher(){
	title_1 = Title(1,"Oblivion","2006","RPG","Developer: Bethesda soft.");
	title_2 = Title(2,"Skyrim","2011","RPG","Developer: Bethesda soft.");

}

TitleMatcher::~TitleMatcher(){

}

void TitleMatcher::submitChoice(int choice){
	entityMatcher.match(title_1.id, title_2.id, choice);
}

// TODO should return list of titles (not id's)
const std::list<int> TitleMatcher::getTitles(){
	const std::list<int> lst = entityMatcher.getEntities();
	return lst;
}