#pragma once

#include <string>
#include "LinkedList.h"

class Movie;
class Actor
{
public:
	std::string name;
	int facebook_likes;
	LinkedList<Movie>* Movies_Acted_In;
	Actor();
};

