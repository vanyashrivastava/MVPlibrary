#include "library.h"
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

Library::Library(){

}
Library::Library(std::istream& ifile){
    read_lib(ifile);
}
Library::~Library(){
    for(size_t i =0; i< bookset.size(); i++){
        delete bookset[i];
    }
    bookset.clear();
}

void Library::read_lib(std::istream& ifile){

    string Title, Author, Genre, Subgenre, Clue, mainChar, clean;
    double Rating;
    int Pages;
    getline(ifile, Title);
    if(ifile.fail()){
        throw invalid_argument("Couldn't read info, file might be in the wrong format.");
    }
    while(!ifile.fail()&& !ifile.eof()){
        getline(ifile,Author);
        if(ifile.fail()){
            throw invalid_argument("Couldn't read info, file might be in the wrong format.");
        }
        getline(ifile,Genre);
        if(ifile.fail()){
            throw invalid_argument("Couldn't read info, file might be in the wrong format.");
        }
        if(Genre=="FICTION"){
            getline(ifile,mainChar);
            if(ifile.fail()){
                throw invalid_argument("Couldn't read info, file might be in the wrong format.");
            }
        }
        getline(ifile,Subgenre);
        if(ifile.fail()){
            throw invalid_argument("Couldn't read info, file might be in the wrong format.");
        }
        getline(ifile,Clue);
        if(ifile.fail()){
            throw invalid_argument("Couldn't read info, file might be in the wrong format.");
        }
        ifile>>Rating;
        if(ifile.fail()){
            throw invalid_argument("Couldn't read info, file might be in the wrong format.");
        }
        ifile>>Pages;
        if(ifile.fail()){
            throw invalid_argument("Couldn't read info, file might be in the wrong format.");
        }
        if(Genre== "FICTION"){
            Fiction *tempbook = new Fiction(Title, Author, Genre, mainChar,Subgenre, Clue, Rating, Pages);  
            //tempbook->printinfo();
            bookset.push_back(tempbook); 
        }
        else if (Genre == "NON-FICTION"){
            Nonfiction *tempbook= new Nonfiction(Title, Author, Genre, Subgenre, Clue, Rating, Pages);
            //tempbook->printinfo();
            bookset.push_back(tempbook);
        }
        getline(ifile, clean);
        getline(ifile, Title);
    }

}

void const Library:: display_tbr(){
    if(TBRlist.empty()){
        cout<< "TBR is empty :( Play one of our games or browse the library to find more books to read!" << endl;
        return;
    }

    else{
        cout << "TBR list: " << endl;
        for(size_t i =0; i < TBRlist.size(); i++){
            TBRlist[i]->printinfo();
        }
    }

}

