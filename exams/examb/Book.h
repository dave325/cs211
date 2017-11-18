#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;
// Stores information about a book
class Book {
            public:
                        // Solicits the information stored in the class from the user
                        Book();

                        // Sets the class information to values passed as parameters
                        Book(string t, string a, int i);

                        // Accessor Fucntion for title
                        const string getTitle() const;

                        // Accessor Function for author
                        const string getAuthor()const ;

                        // Accessor Function for isbn number
                        const int getISBN() const;
                       
            private:
                        string title;
                        string author;
                        int isbn;
};
#endif