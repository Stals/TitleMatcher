// WARNING^ Later this will be console or GUI. So that i need titlematcher.h to give me some methods to use..
// it should have oporunity to display discription, genres and such. So it should have access to Entity struct and entities vector.

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
	//TODO print 1 and 2 for title so that user can understand
	std::cout<<"\n------------------------------------"<<std::endl;
	printTitle(titleMatcher.title_1);
	std::cout<<"\n-----------------VS-----------------"<<std::endl;
	printTitle(titleMatcher.title_2);
	std::cout<<"\n------------------------------------"<<std::endl;
}

void printTop5(){
	const std::list<int> lst = titleMatcher.getTitles(5);
	int i = 1;
	std::cout<<"Top 5 games:"<<std::endl;
	for (std::list<int>::const_iterator it = lst.begin(); it!= lst.end(); ++it, ++i){
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