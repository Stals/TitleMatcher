// This file is a console example of using titlematcher.h
//TODO replace with simple examples. This code should go to the new git repo.

#include <iostream>
#include <string>

#include "titlematcher.h"

TitleMatcher titleMatcher;


void printTitle(Title title){
	std::cout<<title.name<<std::endl;
	std::cout<<title.date<<std::endl;
	std::cout<<title.genre<<std::endl;
	std::cout<<title.description<<std::endl;
}

void printTitles(){
	//TODO print position number.
	std::cout<<"\n------------------------------------"<<std::endl;
	std::cout<<"#1 ";
	printTitle(titleMatcher.title_1);
	std::cout<<"\n-----------------VS-----------------"<<std::endl;
	std::cout<<"#2 ";
	printTitle(titleMatcher.title_2);
	std::cout<<"\n------------------------------------"<<std::endl;
}

void printTop5(){
	std::list<std::string> lst = titleMatcher.getTitles(5);
	int i = 1;
	std::cout<<"Top 5 games:"<<std::endl;
	for (std::list<std::string>::iterator it = lst.begin(); it!= lst.end(); ++it, ++i){
		std::cout<<i<<". "<<(*it)<<std::endl;
	}
	std::cout<<std::endl;
}

void match(){
	while(true){
		std::string input;

		printTitles();
		std::cout<<"Print '1' or '2' to select that title.\nOr print '-1' and '-2' if you dont know it.\nPrint 'quit' to exit: ";
		std::cin>>input;
		if(input == "1")
			titleMatcher.submitChoice(1);
		else if(input == "2")
			titleMatcher.submitChoice(2);
		else if(input == "-1")
			titleMatcher.dontKnowTitle(1);
		else if(input == "-2")
			titleMatcher.dontKnowTitle(2);
		else if(input == "quit")
			break;
	}
}

//TODO get unknown list
int main(){
	std::string input;

	while(true){
		std::cout<<"\nPrint 'top' to get top5 titles.\nOr print 'match' to start matching titles: ";
		std::cin>>input;
		if(input == "top")
			printTop5();
		else if(input == "match")
			match();
	}
}