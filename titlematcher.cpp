#include "titlematcher.h"
#include <cstdlib>

#include "utils/random.h"
TitleMatcher::TitleMatcher(){
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
		default:
			std::cerr<<titleNumber<<" is not allowed in TitleMatcher::dontKnowTitle(). Use 1 for title_1 or 2 for title_2."<<std::endl;
	}
}

void TitleMatcher::submitChoice(int choice){
	entityMatcher.match(title_1.id, title_2.id, choice);
	getNewTitles();
}

// TODO get names from a db
std::list<std::string> TitleMatcher::getTitles(unsigned int top){
	const std::list<int> titles = entityMatcher.getEntities();
	std::list<std::string> result;

	std::list<int>::const_iterator it = titles.begin();
	for(int i = 0; it != titles.end(); ++it, ++i){
		if (i == top) 
			break;
		result.push_back(titles_db.getTitle(*it).name);
	}
	return result;
}

//TODO remove debug messages
void TitleMatcher::getNewTitle(Title& title){
	// get number total number of titles in db
	int numOfTitles = titles_db.getNumberOfTitles();

	// get new titles until they are different and not in a unknown list
	while(true){
		// get random title from db
		int randomID = getRandom(1, numOfTitles);
		/*DEBUG*/std::cout<<"Trying to get ID: "<<randomID<<std::endl;
		title = titles_db.getTitle(randomID);

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