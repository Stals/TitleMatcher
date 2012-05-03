#ifndef TITLE_H
#define TITLE_H

struct Title{
	int id;
	std::string name;
	int year; //TODO mb make month and day?
	std::string genre; //TODO could be several genres and i should be able to make matcher for specific genres
	std::string description;
	Title():id(0), name(""), year(0), genre(""), description(""){		
	}

	Title(int id, std::string name, int year, std::string genre, std::string description){
		this->id = id;
		this->name = name;
		this->year = year;
		this->genre = genre;
		this->description = description;
	}
};
#endif
