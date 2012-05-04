#ifndef TITLE_H
#define TITLE_H
#include <vector>
#include <string>

struct Title{
	int id;
	std::string name;
	int year; //TODO mb make month and day?
	std::vector<std::string> genres; //TODO could be several genres and i should be able to make matcher for specific genres
	std::string description;
	Title():id(0), name(""), year(0), genres(), description(""){		
	}

	Title(int id, std::string name, int year, std::vector<std::string> genres, std::string description){
		this->id = id;
		this->name = name;
		this->year = year;
		this->genres = genres;
		this->description = description;
	}
};
#endif
