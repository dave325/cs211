#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>

using namespace std;
class Package {
public:
                Package(); // Creates an instance of this Package where it is sent from nobody to nobody with no contents
                Package(string f, string t); // Sets the from and to values to the parameters, but the contents get set to the
                                                         // empty array
                Package(string f, string t, string c);  // Sets the values in the class to those passed by the parameters.
                int getFrom() const {return from;}
                float getTo() const {return to;}
                string getContents() const {return contents;}
                void setContents(const string& str) { contents = str; }
private:
                string from;
                string to;
                string contents;
};

#endif;