#ifndef TITLEMATCHER_H
#define TITLEMATCHER_H

#include <iostream>
#include <string>
//#include <ctime.h> //for random
#include <vector>
#include <list>

#include "entitymatcher.h"

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

	// Adds to unknown list and changes Title 
	// titleNumber could be 1 or 2
	void dontKnowTitle(int titleNumber); // TODO rename

	// changes rating for title_1 and title_2 and gets new titles into title_1 and title_2
	void submitChoice(int choice);

	//TODO should return list of title names (not id's)
	// return top 20 titles if top wasn't specified
	const std::list<int> getTitles(int top = 20);


private:
	EntityMatcher entityMatcher; //TODO load previous ratings from a file ot db
	/* FOR TESTING*/ std::vector<Title> titles;
	// Gets new titles in title_1 and title_2
	void getNewTitles();
};

#endif
