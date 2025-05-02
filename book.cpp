#include <iostream>
#include <vector>
#include <cstdlib>
#include "library.h"
#include <string>
using namespace std;

Book::Book (){/*def ctor*/}
Book::Book(string t, string a, string g, string s, string c, double r, int p) {
        title = t;
        author = a;
        genre = g;
        subgenre = s;
        clue = c;
        rating = r;
        pagenum = p;
}
Book::~Book(){}
Fiction::Fiction(){}
Fiction::Fiction(std::string t, std::string a, std::string g, std::string mc, std::string s, std::string c, double r, int p):
Book(t,a,g,s,c,r,p)
{
     MainChar=mc;  
}

Nonfiction::Nonfiction(){}
Nonfiction::Nonfiction(std::string t, std::string a, std::string g, std::string s, std::string c, double r, int p): 
Book(t,a,g,s,c,r,p)
{

}

void Fiction::printinfo(){
        cout << "Title: " << title<< endl;
        cout << "Author: "<< author<< endl;
        cout << "Genre: "<< genre<< endl;
        cout << "Main Character/s: " << MainChar << endl;
        cout << "Subgenre: "<< subgenre<< endl;
        cout << "Brief: "<< clue<< endl;
        cout << "Rating: "<< rating<< endl;   
        cout << "Pages: "<< pagenum<< endl;
}

void Book::printinfo(){
        cout << "Title: " << title<< endl;
        cout << "Author: "<< author<< endl;
        cout << "Genre: "<< genre<< endl;
        cout << "Subgenre: "<< subgenre<< endl;
        cout << "Brief: "<< clue<< endl;
        cout << "Rating: "<< rating<< endl;   
        cout << "Pages: "<< pagenum<< endl;
}
void Fiction:: browseFiction(Library& currlib){
        int cnt=0;
        int ans;
        for (size_t i =0; i < currlib.bookset.size(); i++){
                //cout << " In loop" << endl;
                if(currlib.bookset[i]->genre== "FICTION"){
                        cout << "Book #" << cnt++ << endl;
                        currlib.bookset[i]->printinfo();
                        Fictionlist.push_back(currlib.bookset[i]);
                }
        }
        cout << " Would you like to add any of these books to your TBR list? Enter 1 for yes and 2 for no" << endl;
        cin>> ans;
        if(ans==1){
                while(true){
                        cout << "Please enter the number of the book you want to add, it is right above the title. Enter -1 to leave 'Browse'." << endl;
                        cin >>ans;
                        if(ans==-1){
                                Fictionlist.clear();
                                return;
                        }
                        currlib.TBRlist.push_back(Fictionlist[ans]);
                        cout << "Added" << endl;
                }
        }
        Fictionlist.clear();
}
void Nonfiction:: browseNonfiction(Library& currlib){
        cout << " In browser" << endl;
        int cnt=0;
        int ans;
        for (size_t i =0; i < currlib.bookset.size(); i++){
                //cout << " In loop" << endl;
                if(currlib.bookset[i]->genre== "NON-FICTION"){
                        cout << "Book #" << cnt++ << endl;
                        currlib.bookset[i]->printinfo();
                        Nonfictionlist.push_back(currlib.bookset[i]);

                }
        }
        cout << " Would you like to add any of these books to your TBR list? Enter 1 for yes and 2 for no" << endl;
        cin>> ans;
        if(ans==1){
                while(true){
                        cout << "Please enter the number of the book you want to add, it is right above the title. Enter -1 to leave 'Browse'." << endl;
                        cin >>ans;
                        if(ans==-1){
                                Nonfictionlist.clear();
                                return;
                        }
                        currlib.TBRlist.push_back(Nonfictionlist[ans]);
                        cout << "Added" << endl;
                }
        }
        Nonfictionlist.clear();
}

