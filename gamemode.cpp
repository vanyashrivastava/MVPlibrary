#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <string>
#include "library.h"

using namespace std;

//vector<Book> bookset;
// vector <Book> TBRlist;
int points = 0;


void gamemode::guessgenre(Library& currlib) 
{
    cout << "Welcome to the game where you must guess the genre of the book." << endl;
    cout << "We will give you the book title, author, subgenre, and clue to help you!" << endl;
    cout << "There are 3 rounds. You have 4 chances. Enter E to exit early." << endl;

    int guesses = 0;
    string input;
    string answer;
    
    for (int i = 0; i < 3; i++) {
        int j =0;
        cout << "Round: " << i+1 << endl;
        int rdm = rand() % currlib.bookset.size();
        
        Book *current= currlib.bookset[rdm];
        string info[4]={current->title, current->author, current->genre, current->clue};
        string label[4] = { "Book Title: ", "Book Author: ", "Book Main Genre: ", "Book Clue: " };
        cout << label[j];
        cout << info[j++]<< endl;
        
        answer = current->subgenre;
        cout << "Guess the subgenre. PLEASE TYPE YOUR ANSWERS IN ALL CAPS" << endl;
        cout << "Your options are FANTASY, PERSON, TRAGEDY, ADVENTURE, EVENT, THRILLER, or EDUCATION." << endl;
        bool correct = false;
        bool leave = false;
        while (guesses <= 3) {
            cin>> input;
            if(input=="E"){
                leave=true;
                break;
            }
            if (input == answer) {
                cout << "Well done! " << input << " is correct!" << endl;
                correct = true;
                break;
            }
            else {
                if (guesses < 3) {
                    cout << "Guess again!" << endl;
                    cout << "Wrong! Here's a clue: " << endl;
                    cout << label[j] << endl;
                    cout << info[j++]<< endl; 
                }
                
                cout << "You have used: " << ++guesses << " guesses" << endl;
            }
        }
        if(correct==false){
            cout << "The correct subgenre was " << answer << endl;
        }

        else if (correct == true) {
            points++;
        }
        if(leave){break;}

        char tbr;
        cout << "Did you like this book? If so, add it to your 'To be read' List. (Y/N)" << endl;
        cin >> tbr;

        if (tbr == 'Y') {
            currlib.TBRlist.push_back(current);
            cout << "Added!" << endl;
        }

        guesses = 0;
     }

    cout << "You had " << points << " points" << endl;
    cout <<"Exiting..." <<endl;
}

void gamemode:: scavengerhunt(Library& currlib) {
    cout << "Welcome to the scavenger hunt!" << endl;
    cout << "You will be given clues to find the next book!" << endl;

    int numbooks = 3;

    cout << "You have to guess " << numbooks << " books to receive your prize!" << endl;

    for (int i = 0; i < numbooks; i++) {
        cout << "This is round " << i+1 << endl;
        int random = rand() % currlib.bookset.size();
        Book *current= currlib.bookset[random];

        cout << "Here's your clue: " << current->clue << endl;
        cout << "Enter the TITLE of the matching book:" << endl;

        string guess;
        getline(cin >> ws, guess);

        if (guess == current->title) {
            cout << "Great job!" << endl;
        }

        else {
            cout << "The correct answer was " << current->title << endl;
        }
    }

    cout << "Scavenger complete! You have received a 20% discount on your next book!" << endl;

}

