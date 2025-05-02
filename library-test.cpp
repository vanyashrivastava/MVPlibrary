#include <iostream>
#include <vector>
#include <cstdlib>
#include "library.h"
#include <fstream>
using namespace std;

int main() {
    srand(time(0));
    char go;
    cout << "Welcome to the MVP Library!" << endl;
    int ans;
    cout << "Would you like to pass in a file to your own Library (Please make sure it in the correct format)?" << endl; 
    cout << "If not, our default library will be provided to you." << endl; 
    cout << "Enter 1 for yes, 2 for no, or 3 for a format description: " << endl;
    cin>> ans;
    ifstream infile;
    Library* lAptr = nullptr;


    if(!cin.fail() && ans==3){
        cout << "Format for Fiction books: " << endl;
        cout << "Title: " << endl;
        cout << "Author: "<< endl;
        cout << "Genre: (In all caps)" << endl;
        cout << "MC:(Main character/s name/s) " << endl;
        cout << "Subgenre: (In all caps)"<<  endl;
        cout << "Brief: (brief 1 line summary)"<< endl;
        cout << "Rating:(out of 5)" <<endl;   
        cout << "Number of Pages: "<< endl;

        cout << " " << endl;

        cout << "Format for Non-Fiction books: " << endl;
        cout << "Title: " << endl;
        cout << "Author: "<< endl;
        cout << "Genre: (In all caps)" << endl;
        cout << "Subgenre: (In all caps)"<<  endl;
        cout << "Brief: (brief 1 line summary)"<< endl;
        cout << "Rating:(out of 5)" <<endl;   
        cout << "Number of Pages: "<< endl;

        cout<< "Enter 1 to use your own library or 2 for default library." << endl;
        cin>>ans;
    }

    if(!cin.fail() && ans==1){
        string file;
        cout << "Please enter file name: " << endl;
        cin >> file;
        infile.open(file);
        try{lAptr = new Library(infile);}
        catch(invalid_argument &e){
            cout << e.what() << endl;
        }
        infile.close();
        //infile.open(file);
        cout << "Library Created!" << endl;
    }
    else if(!cin.fail() && ans==2){
        infile.open("lib1.txt");
        try{lAptr = new Library(infile);}
        catch(invalid_argument &e){
            cout << e.what() << endl;
        }
        infile.close();
        //infile.open("lib1.txt");
        cout << "Library Created!" << endl;
    }
    if (lAptr == nullptr) {
        cout << "Library not created!" << endl;
        return 1;
    }

    
    Library& lA = *lAptr;
    cout << "We offer interactive games such as Guess the Subgenre and Scavenger Hunt!" << endl; 
    cout << "And, you may browse various booksets: Non-fiction, Fiction, and your to-be-read list!" << endl;
    cout << "Are you ready? (Y/N)" << endl;
    cin >> go;
    
    while (go == 'Y') {
    cout << "What would you like to do? (Type 1 for games, 2 to browse the library, or 3 to go through your TBR list): " << endl;
    cin>> ans;

    if(!cin.fail()&&ans== 1){
        gamemode one;
        cout<< "Which game would you like? Enter 1 for Guess the Sub-genre, 2 for Scavenger hunt" << endl;
        cin>> ans;
        if(!cin.fail() && ans==1){
            cout << "GenreGuess is starting now!" << endl;
            one.guessgenre(lA);
        }
        else if(!cin.fail() && ans==2){
            cout << "Scavenger hunt is starting now!" << endl;
            one.scavengerhunt(lA);
        }
    }
    else if(ans ==2){
        cout << "Would you like browse our Fiction books(1) or Non-fiction books(2)." << endl;
        cin>> ans;
        if(ans == 1){
            Fiction Fa;
            Fa.browseFiction(lA);
            cout << "Thank you for browsing our Fiction books!" << endl;
            lA.display_tbr();   
        }
        else if(ans==2){
            Nonfiction na;
            na.browseNonfiction(lA);
            cout << "Thank you for browsing our Non-Fiction books!" << endl;
            lA.display_tbr();
        }
    }
    else if (ans == 3) {
        cout << "Let's go through your TBR list now!" << endl;
        lA.display_tbr();
    }

    cout << "Continue going through the MVP library? (Y/N)" << endl;
    cin >> go;
    }

    cout << "Thanks for stopping by the MVP library!" << endl;
    return 0;
}
