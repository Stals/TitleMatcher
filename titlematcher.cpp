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

// TODO should return list of title names (not id's)
const std::list<int> TitleMatcher::getTitles(int top){
	const std::list<int> titles = entityMatcher.getEntities();
	
	std::list<int>::const_iterator it = titles.begin();
	for(int i = 0; it != titles.end(); ++it, ++i){
		if (i == top) 
			break;
	}
	const std::list<int> result(titles.begin(), it);
	return result;
}
