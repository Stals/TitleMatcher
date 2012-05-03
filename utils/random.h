#ifndef GETRANDOM_H
#define GETRANDOM_H
#include <ctime>

// header to get random number so that i can change algorithm but code depending on it will now change
namespace utils {
	// returns a random number between l and h
	int getRandom(unsigned int l, unsigned int h){
		return (rand() % h) + l; 
	}
}
#endif
