#include "Movie.h"
#include "Director.h"
#include "Actor.h"
#include "LinkedList.h"
//#include "AVL_Tree.h"
#include <vector>
#include <sstream>
#include <iostream>
#include <stdlib.h>

using namespace std;
Movie::Movie() {
    actor_1 = new Actor();
    actor_2 = new Actor();
    actor_3 = new Actor();
    director = new Director();
    title_year = new Node<int, Movie>();
    next = NULL;
}

Movie::Movie(std::string Comma_Seperated_String, LinkedList<Actor>* AL, LinkedList<Director>* DL, AVL_Tree<int, Movie>* YT) {
    actor_1 = new Actor();
    actor_2 = new Actor();
    actor_3 = new Actor();
    director = new Director();
    title_year = new Node<int, Movie>();
    next = NULL;

    std::vector<std::string> Movie_Information_Vector;
    std::stringstream ss(Comma_Seperated_String);

    while (ss.good()) {
        std::string temp;
        getline(ss, temp, ',');
        Movie_Information_Vector.push_back(temp);
    }
    assDataToAllFields(Movie_Information_Vector);
    director = DL->InsertSorted(director)->data;
    actor_1 = AL->InsertSorted(actor_1)->data;
    actor_2 = AL->InsertSorted(actor_2)->data;
    actor_3 = AL->InsertSorted(actor_3)->data;
    title_year = YT->add(title_year->key);
    cout << endl;
}

std::string correctify(string name) {
    int len = name.length();
    char chr;
    for (int i = 1; i <= len; i++) {
        chr = name[len - i];
        if (!(chr > 37 && chr < 127)) {
            name[len - i] = ' ';
        }
        else {
            name = name.substr(0, len - i + 1);
            return name;
        }
    }
}

void Movie::assDataToAllFields(std::vector<std::string> v)
{
    try{
        name = correctify(v[0]);
    }
    catch (...){
        name = "";
    }
    //Assigning Genres
    try
    {
        stringstream str(v[1]);
        while (str.good())
        {
            std::string temp;
            getline(str, temp, '|');
            genres.push_back(temp);
        }
    }
    catch (...)
    {
        genres.clear();
    }


    //Assigning year

    try
    {
        title_year->key = stoi(v[2]);
    }
    catch (...)
    {
        title_year->key = -1;
    }




    //Assigning imdb_score
    try
    {
        imdb_score = stod(v[3]);
        //throw (4);
    }
    catch (...)
    {
        imdb_score = -1;
    }

    //Assigning Director
    try
    {
        director->name = v[4];
        //Assigning his Facebook_Likes
        try
        {
            director->facebook_likes = stoi(v[5]);
        }
        catch (const std::exception&)
        {
            director->facebook_likes = -1;
        }
    }
    catch (const std::exception&)
    {
        delete director;
        director = NULL;
    }

    

    //setting director facebook likes
    

    //setting num_critic_for_reviews
    try
    {
        num_critic_for_reviews = stoi(v[6]);
        //throw (7);
    }
    catch (...)
    {
        num_critic_for_reviews = -1;
    }


    //setting duration
    try
    {
        duration = stoi(v[7]);
        //throw(8);
    }
    catch (...)
    {
        duration = -1;
    }


    //Assigning Actor 1 Node
    //string actorname_1 = v[8];
    try
    {
        actor_1->name = v[8];
        //Actor 1 facebook likes
        try
        {
            actor_1->facebook_likes = stoi(v[9]);
        }
        catch (...)
        {
            actor_1->facebook_likes = -1;
        }
    }
    catch (...)
    {
        delete actor_1;
        actor_1 = NULL;
    }
    

    
    

    //Assigning Actor 2 Node
    try
    {
        actor_2->name = v[10];
        //Actor 2 facebook likes
        try
        {
            actor_2->facebook_likes = stoi(v[11]);
        }
        catch (...)
        {
            actor_2->facebook_likes = -1;
        }
    }
    catch (...)
    {
        delete actor_2;
        actor_2 = NULL;
    }
    

    


    //Assigning Actor 3 Node
    try
    {
        actor_3->name = v[12];
        //Actor 3 facebook likes
        try
        {
            actor_3->facebook_likes = stoi(v[13]);
        }
        catch (...)
        {
            actor_3->facebook_likes = -1;
        }
    }
    catch (...)
    {
        delete actor_3;
        actor_3 = NULL;
    }
    
    

    //Setting Gross
    try
    {
        gross = stoi(v[14]);
        //throw (15);
    }
    catch (...)
    {
        gross = -1;
    }


    //setting num_voted_users
    try
    {
        num_voted_users = stoi(v[15]);
        //throw(16);
    }
    catch (...)
    {
        num_voted_users = -1;
    }


    //setting cast_total_facebook_likes
    try
    {
        cast_total_facebook_likes = stoi(v[16]);
        //throw(17);
    }
    catch (...)
    {
        cast_total_facebook_likes = -1;
    }


    //setting facenumber_in_poster
    try
    {
        facenumber_in_poster = stoi(v[17]);
        //throw (18);
    }
    catch (...)
    {
        facenumber_in_poster = -1;
    }

    //Setting Plot_keywords
    try
    {
        stringstream str(v[18]);
        while (str.good()) {
            string temp;
            getline(str, temp, '|');
            plot_keywords.push_back(temp);
            //throw (19);
        }
    }
    catch (...)
    {
        plot_keywords.clear();
    }



    //setting imdb link
    try
    {
        movie_imdb_link = v[19];
        //throw (20);
    }
    catch (...)
    {
        movie_imdb_link = " ";
    }


    //setting num_user_for_reviews
    try
    {
        num_user_for_reviews = stoi(v[20]);
        //throw(21);
    }
    catch (...)
    {
        num_user_for_reviews = -1;
    }


    //setting language
    try
    {
        language = v[21];
        //throw(22);
    }
    catch (...)
    {
        language = " ";
    }


    //setting country
    try
    {
        country = v[22];
        //throw (23);
    }
    catch (...)
    {
        country = " ";
    }

    try {
        content_rating = v[23];
        //throw (24);
    }
    catch (...) {
        content_rating = " ";
    }

    try
    {
        budget = stoi(v[24]);
        //throw (25);
    }
    catch (...)
    {
        budget = -1;
    }

    try
    {
        aspect_ratio = stod(v[25]);
        //throw (26);
    }
    catch (...)
    {
        aspect_ratio = -1.0;
    }

    try
    {
        movie_facebook_likes = stoi(v[26]);
        //throw (27);
    }
    catch (...)
    {
        movie_facebook_likes = -1;
    }

    try
    {
        color = v[27];
        //throw(28);
    }
    catch (...)
    {
        color = " ";
    }

}

void Movie::DeleteMovie() {
    director->Movies_directed->deleteList();
    delete director->Movies_directed;
    delete director;

    actor_1->Movies_Acted_In->deleteList();
    delete actor_1->Movies_Acted_In;

    actor_2->Movies_Acted_In->deleteList();
    delete actor_2->Movies_Acted_In;

    actor_3->Movies_Acted_In->deleteList();
    delete actor_3->Movies_Acted_In;

    delete actor_1;
    delete actor_2;
    delete actor_3;
}

void Movie::printMovie() {
    //0
    cout << "MovieTitle = " << name << endl;

    //1
    cout << "Genres : " << endl;
    for (int i = 0; i < genres.size(); i++) {
        cout << "\t" << genres[i] << endl;
    }

    //2
    cout << "title_year : " << title_year << endl;

    //3
    cout << "imdb_score : " << imdb_score << endl;

    //4
    cout << "Director name : " << director->name << endl;

    //5
    cout << "director_facebook_likes : " << director_facebook_likes << endl;

    //6
    cout << "num_critic_for_reviews : " << num_critic_for_reviews << endl;

    //7
    cout << "Duration : " << duration << endl;

    //8
    cout << "Actor 1 Name : " << actor_1->name << endl;
    //9
    cout << "actor_1_facebook_likes : " << actor_1_facebook_likes << endl;

    //10
    cout << "Actro 2 Name : " << actor_2->name << endl;
    //11
    cout << "actor_2_facebook_likes : " << actor_2_facebook_likes << endl;


    //12
    cout << "Actro 3 Name : " << actor_3->name << endl;
    //13
    cout << "actor_3_facebook_likes : " << actor_3_facebook_likes << endl;

    //14
    cout << "gross : " << gross << endl;

    //15
    cout << "num_voted_users : " << num_voted_users << endl;

    //16
    cout << "cast_total_facebook_likes : " << cast_total_facebook_likes << endl;

    //17
    cout << "facenumber_in_poster : " << facenumber_in_poster << endl;

    //18
    cout << "Plot Keywords : " << endl;
    for (int i = 0; i < plot_keywords.size(); i++) {
        cout << "\t" << plot_keywords[i] << endl;
    }

    //19
    cout << "movie_imdb_link : " << movie_imdb_link << endl;

    //20
    cout << "num_user_for_reviews : " << num_user_for_reviews << endl;

    //21
    cout << "language : " << language << endl;

    //22
    cout << "country : " << country << endl;

    //23
    cout << "content_rating : " << content_rating << endl;

    //24
    cout << "budget : " << budget << endl;

    //25
    cout << "aspect_ratio : " << aspect_ratio << endl;

    //26
    cout << "movie_facebook_likes : " << movie_facebook_likes << endl;

    //27
    cout << "color : " << color << endl;

}
