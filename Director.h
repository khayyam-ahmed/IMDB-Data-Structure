#pragma once

#include <string>
#include "LinkedList.h"

class Movie;
class Director
{
public:
	std::string name;
	int facebook_likes; 
	LinkedList<Movie>* Movies_directed;
	Director();
};


