// a class is a user-defined data type that could have both variables and methods ( functions )
// inside of it , its like a structure
#include <iostream>

// A class is like a blueprint for creating objects. It groups related data and functions together.
class clsManga {
   private:
    // These variables are private, meaning they cannot be accessed directly from outside the class.
    std::string title; // these are data members of the class because they hold data :D
    std::string author;
    short chapters;
    bool completed;

   public:
    // This function assigns values to the private variables.
    void setMangaInfo(std::string t, std::string a, short c, bool comp) { // and something like this is called a function member because well , its a function 
        title = t;
        author = a;
        chapters = c;
        completed = comp;
    }

    // This function displays the stored information about the manga.
    void printMangaInfo() {
        std::cout << title << " by " << author << " has " << chapters << " chapters. "
                  << (completed ? "It is completed." : "It is ongoing.") << std::endl;
    }
};

int main() {
    // We create an object (an instance) of the class. Think of it as an actual manga entry.

    // Creating manga object for "Erased"
    clsManga Erased;
    Erased.setMangaInfo("Erased", "Kei Sanbe", 44, true);
    Erased.printMangaInfo();

    // Creating another manga object for "That Time I Got Reincarnated as a Slime"
    clsManga Slime;
    Slime.setMangaInfo("That Time I Got Reincarnated as a Slime", "Fuse", 100, false);  // Ongoing
    Slime.printMangaInfo();

    return 0;
}
