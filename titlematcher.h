#ifndef TITLEMATCHER_H
#define TITLEMATCHER_H

#include <iostream>
#include <string>
//#include <ctime.h> //for random
#include <vector>
#include <list>
#include <tr1/unordered_set>

#include "entitymatcher.h"

//  TODO 
//- save unknown titles to a file, and dont give it again to a user.
//- Add db
//	- load titles from db
//	- save user ratings to db
//	- save unknown list to db
//- add spesific matches for date and genre.   year 2000 - 2010 or pick one genre to give you titles

// Here i need to get 2 random titles from db - give them via method and then recieve witch was selected and tell Titlematcher about it.
// should store 2 current things to match and change them if needed (if user dont know this title)
// also unknown titles should save to a file.
// user of this should have oportunity to get each of titles to show them to end user.

struct Title{
	int id;
	std::string name;
	std::string date;
	std::string genre; //TODO could be several genres and i should be able to make matcher for specific genres
	std::string description;
	Title():id(0), name(""), date(""), genre(""), description(""){		
	}

	Title(int id, std::string name, std::string date, std::string genre, std::string description){
		this->id = id;
		this->name = name;
		this->date = date;
		this->genre = genre;
		this->description = description;
	}
};

class TitleMatcher{
public:
	// loads 2 random titles from db (if select creteria was not specified)
	TitleMatcher(); //TODO with a username?
	~TitleMatcher();

	Title title_1;
	Title title_2;

	// Adds title to unknown list and changes Title for next matching 
	// titleNumber could be 1 or 2 (for title_1 and title_2)
	//TODO if title is already in a ratings but user uses dontKnow - what should happen 
	//	1.(it shouldnt be added to unknown) 
	//  2. it should be deleted from a rating list and added to the unknownTitles
	void dontKnowTitle(int titleNumber); // TODO rename

	// changes rating for title_1 and title_2 and gets new titles into title_1 and title_2
	void submitChoice(int choice);

	//TODO should return list of title names (not id's)
	// return top 20 titles if top wasn't specified
	const std::list<int> getTitles(unsigned int top = 20);


private:
	EntityMatcher entityMatcher; //TODO load previous ratings from a file ot db
	/* FOR TESTING*/ std::vector<Title> titles;

	// stores a list of unknown titles id's
	//Note: change hash function if needed
	std::tr1::unordered_set<int> unknownTitles;

	//gets new title into 'title'
	void getNewTitle(Title& title);
	// Gets new titles in title_1 and title_2
	void getNewTitles();
};

#endif
