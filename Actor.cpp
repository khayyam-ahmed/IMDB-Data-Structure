#include "Actor.h"
#include "Movie.h"

Actor::Actor() {
	Movies_Acted_In = new LinkedList<Movie>();
}
