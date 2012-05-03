#ifndef GETRANDOM_H
#define GETRANDOM_H
#include <ctime>
// TODO use boost.random
namespace utils {
	// returns a random number between l and h
	int getRandom(unsigned int l, unsigned int h){
		return (rand() % h) + l; 
	}
}
#endif
