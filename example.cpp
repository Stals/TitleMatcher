// This file is a console example of using titlematcher.h
//TODO replace with simple examples. This code should go to the new git repo.

//how to compile
// sudo g++ -ggdb db.cpp entitymatcher.cpp titlematcher.cpp  example.cpp -lmongoclient -lboost_system -lboost_thread -lboost_filesystem -lboost_program_options -o titlematcher

#include <iostream>
#include <string>
#include "titlematcher.h"
#include "title.h"

void printTop5(TitleMatcher& titleMatcher){
	std::list<std::string> lst = titleMatcher.getTitles(100);
	int i = 1;
	std::cout<<"Top 5 games:"<<std::endl;
	for (std::list<std::string>::iterator it = lst.begin(); it!= lst.end(); ++it, ++i){
		std::cout<<i<<". "<<(*it)<<std::endl;
	}
	std::cout<<std::endl;
}

void print(int num, Title& title){
	std::cout<<"#"<<num<<" ";
	std::cout<<title.name<<std::endl;
	std::cout<<title.date<<std::endl;
	std::cout<<title.genre<<std::endl;
	std::cout<<title.description<<std::endl;
}

int main(){
	TitleMatcher titleMatcher;
	while(true){
		print(1, titleMatcher.title_1);
		std::cout<<std::endl;
		print(2, titleMatcher.title_2);

		std::cout<<"What is your choice? (1 or 2):";
		std::string input;
		std::cin>>input;
		int choice = (input == "1")? 1 : 2;

		titleMatcher.submitChoice(choice);
		printTop5(titleMatcher);
	}
}

