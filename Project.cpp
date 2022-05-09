
#include <iostream>
#include "Movie.h"
#include "Actor.h"
#include "Director.h"
#include <fstream>
#include "HashTable.h"
#include "AVL_Tree.h"

using namespace std; 


int main()
{
    std::cout << "Hello World!\n";
    ifstream IMBD_Database;
    IMBD_Database.open("IMDB_Top5000.csv");

    HashTable<string, Movie>* MH = new HashTable<string, Movie>();
    LinkedList<Actor>* AL = new LinkedList<Actor>();
    LinkedList<Director>* DL= new LinkedList<Director>();
    AVL_Tree<int, Movie>* YT = new AVL_Tree<int, Movie>();

    try
    {
        int i = 0;
        while (IMBD_Database.good() && i<5044) {
            string MovieInformation;
            getline(IMBD_Database, MovieInformation);
            if (i == 0) { i++; continue; }

            
            
            Movie* temp = new Movie(MovieInformation, AL, DL, YT);
            MH->insertItem(temp->name, temp);
            
            temp->director->Movies_directed->InsertAtEnd(temp);
            temp->actor_1->Movies_Acted_In->InsertAtEnd(temp);
            temp->actor_2->Movies_Acted_In->InsertAtEnd(temp);
            temp->actor_3->Movies_Acted_In->InsertAtEnd(temp);
            temp->title_year->data->insertItem(temp->name, temp);
            i++;
        }
    }
    catch (...)
    {
        cout << "[INFO] End of the list" << endl;
    }

    /*cout << "Enter any name of a movie: ";
    string str = "Avatar";
    Movie* tmp = new Movie();
    tmp->name = str;
    
    
    ML->Search<Movie>(tmp);
    ML->Loc_->data->director->Movies_directed->PrintList();*/
    //ML->Loc_->data->printMovie();
    //MoviesList->PrintList();

    system("pause");
    system("CLS");

    string name = "Avatar";
    cout << "Testing hashtable's search function. Searching for " <<name<< endl;
    MH->searchTable(name)->printMovie();

}
