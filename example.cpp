// This file is a console example of using titlematcher.h
//TODO replace with simple examples. This code should go to the new git repo.

//how to compile
// sudo g++ -ggdb db.cpp entitymatcher.cpp titlematcher.cpp  example.cpp -lmongoclient -lboost_system -lboost_thread -lboost_filesystem -lboost_program_options -o titlematcher

#include <iostream>
#include <string>
#include "titlematcher.h"


void printTop5(TitleMatcher& titleMatcher){
	std::list<std::string> lst = titleMatcher.getTitles(5);
	int i = 1;
	std::cout<<"Top 5 games:"<<std::endl;
	for (std::list<std::string>::iterator it = lst.begin(); it!= lst.end(); ++it, ++i){
		std::cout<<i<<". "<<(*it)<<std::endl;
	}
	std::cout<<std::endl;
}

int main(){
	TitleMatcher titleMatcher;
	titleMatcher.submitChoice(1);
	titleMatcher.submitChoice(1);
	titleMatcher.submitChoice(1);
	titleMatcher.submitChoice(1);
	titleMatcher.submitChoice(1);
	printTop5(titleMatcher);
}

