// This file is a console example of using titlematcher.h
//TODO replace with simple examples. This code should go to the new git repo.

//how to compile
// sudo g++ -ggdb db.cpp entitymatcher.cpp titlematcher.cpp  example.cpp -lmongoclient -lboost_system -lboost_thread -lboost_filesystem -lboost_program_options -o titlematcher

#include <iostream>
#include <string>
#include "titlematcher.h"
#include "title.h"

void printTop5(TitleMatcher& titleMatcher){
	std::list<std::string> lst = titleMatcher.getTitles(5);
	int i = 1;
	std::cout<<"Top 5 games:"<<std::endl;
	for (std::list<std::string>::iterator it = lst.begin(); it!= lst.end(); ++it, ++i){
		std::cout<<i<<". "<<(*it)<<std::endl;
	}
	std::cout<<std::endl;
}


void printTitle(int num, Title& title){
	std::cout<<"#"<<num<<" ";
	std::cout<<title.name<<std::endl;
	std::cout<<title.date<<std::endl;
	std::cout<<title.genre<<std::endl;
	std::cout<<title.description<<std::endl;
}


void printTitles(TitleMatcher& titleMatcher){
	//TODO print position number.
	std::cout<<"\n------------------------------------"<<std::endl;
	printTitle(1, titleMatcher.title_1);
	std::cout<<"\n-----------------VS-----------------"<<std::endl;
	printTitle(2, titleMatcher.title_2);
	std::cout<<"\n------------------------------------"<<std::endl;
}


void match(TitleMatcher& titleMatcher){
	while(true){
		std::string input;

		printTitles(titleMatcher);
		std::cout<<"Print '1' or '2' to select that title.\n"
				   "Or print '-1' and '-2' if you dont know it.\n"
				   "Print 'quit' to exit: ";
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
	TitleMatcher titleMatcher;
	std::string input;

	while(true){
		std::cout<<"\nPrint 'top' to get top5 titles.\n"
				"Or print 'match' to start matching titles: ";
		std::cin>>input;
		if(input == "top")
			printTop5(titleMatcher);
		else if(input == "match")
			match(titleMatcher);
	}
}

