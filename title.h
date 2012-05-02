#ifndef TITLE_H
#define TITLE_H

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
#endif
