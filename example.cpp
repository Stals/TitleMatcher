// WARNING^ Later this will be console or GUI. So that i need titlematcher.h to give me some methods to use..
// it should have oporunity to display discription, genres and such. So it should have access to Entity struct and entities vector.

#include <iostream>
#include <string>

#include "titlematcher.h"

void printTitle(Title title){
	std::cout<<title.name<<std::endl;
	std::cout<<title.date<<std::endl;
	std::cout<<title.genre<<std::endl;
	std::cout<<title.description<<std::endl;
}

int main(){
	TitleMatcher titleMatcher;

	//TODO print 1 and 2 for title so that user can understand
	printTitle(titleMatcher.title_1);
	std::cout<<"-----------------VS-----------------"<<std::endl;
	printTitle(titleMatcher.title_2);

	
	//TODO rewrite this part i guess.
	std::string userChoice;
	std::cout<<"What will be your choice? (1/2):"; //TODO tell i need to get 1 or 2
	std::cin>>userChoice;
	
	int choice;
	//magickly turn it to int
	if (userChoice == "1")
		choice = 1;
	else if(userChoice == "2")
		choice = 2; 
	else{
		std::cout<<"You can only print 1 or 2"<<std::endl;
		choice = 2; //TODO delete - just for now to check if everything is working
	}	

	titleMatcher.submitChoice(choice);

	const std::list<int> lst = titleMatcher.getTitles();
	for (std::list<int>::const_iterator it = lst.begin(); it!= lst.end(); ++it){
		std::cout<<(*it)<<std::endl;
	}


}