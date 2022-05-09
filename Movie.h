#pragma once

#include <string>
#include <vector>
#include "AVL_Tree.h"

class Actor;
class Director;
template<class T> class LinkedList;
//template<class Key, class Data> class AVL_Tree;


using namespace std;

class Movie
{
public:

    //Adding just so that i can read the entire file.
    Movie* next;
    
    std::string name;//0

                                //Movie(std::string name);


    std::vector<std::string> genres;//1

    Node<int, Movie>* title_year;//2
    double imdb_score;//3

    Director* director;//4
    int director_facebook_likes;//5

    int num_critic_for_reviews;//6
    int duration;//7

    Actor* actor_1;//8
    int actor_1_facebook_likes;//9

    Actor* actor_2;//10
    int actor_2_facebook_likes;//11

    Actor* actor_3;//12
    int actor_3_facebook_likes;//13

    int gross;//14
    int num_voted_users;//15
    int cast_total_facebook_likes;//16
    int facenumber_in_poster;//17

    std::vector<std::string> plot_keywords;//18

    std::string movie_imdb_link;//19
    int num_user_for_reviews; //20
    std::string language; //21
    std::string country;//22

    std::string content_rating;//23

    int budget;//24

    double aspect_ratio;//25

    int movie_facebook_likes;//26

    std::string color; //27

    Movie();
    Movie(std::string Comma_Seperated_String, LinkedList<Actor>* AL, LinkedList<Director>* DL, AVL_Tree<int, Movie>* YT);
    void assDataToAllFields(std::vector<std::string> v);
    void printMovie();
    void DeleteMovie();
    
};

