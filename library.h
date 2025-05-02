#include <iostream>
#include <vector>
#include <string>

class Book{
    public:
    std::string title, author, genre, subgenre, clue;
    double rating;
    int pagenum;
    virtual void printinfo();
    Book();
    virtual ~Book();
    Book(std::string t, std::string a, std::string g, std::string s, std::string c, double r, int p);
    friend class Library;
};
class Library{
    public:
    Library();
    Library(std::istream& ifile);
    ~Library();
    std::vector <Book*> TBRlist;
    std::vector <Book*> bookset;
    void read_lib(std::istream& ifile);
    void const display_tbr();
    friend class gamemode;

};
class Fiction: public Book{
    
    public:
    Fiction();
    Fiction(std::string t, std::string a, std::string g, std::string mc, std::string s, std::string c, double r, int p);
    
    void printinfo();
    void browseFiction(Library& currlib);

    std::vector <Book*> Fictionlist;
    std::string MainChar; 
};

class Nonfiction: public Book{
    public:
    Nonfiction();
    Nonfiction(std::string t, std::string a, std::string g, std::string s, std::string c, double r, int p);
    
    void browseNonfiction(Library& currlib);
    
    std::vector <Book*> Nonfictionlist;
};



class gamemode {
    public:
    void guessgenre(Library& currlib);
    void scavengerhunt(Library& currlib);

    private:
        std:: string answer;
};
