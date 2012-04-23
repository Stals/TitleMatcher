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
			unknownTitles.insert(title_1.id);
			getNewTitle(title_1);
			break;
		case 2:
			unknownTitles.insert(title_2.id);
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

//TODO remove debug messages
void TitleMatcher::getNewTitle(Title& title){
	// get new titles until they are different and not in a unknown list
	while(true){
		title = titles[rand() % titles.size()];

		if(title_1.id == title_2.id){
			// if titles equals - get new litle
			std::cout<<title.name<<" - Titles equals, so getting new one."<<std::endl;
			continue;
		}
		
		if(unknownTitles.find(title.id) != unknownTitles.end()){
			// if title was found in a unknown list - get new title
			std::cout<<title.name<<" was found in unknown. Getting new one."<<std::endl;
			continue;
		}

		//else: title is ok. break the infinite loop
		std::cout<<title.name<<" - title is ok"<<std::endl;
		break;
	}
}

void TitleMatcher::getNewTitles(){
	getNewTitle(title_1);
	getNewTitle(title_2);
}