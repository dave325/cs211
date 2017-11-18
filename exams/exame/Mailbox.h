#ifndef MAILBOX_H
#define MAILBOX_H

#include "Package.h"
#include string
using namespace std;
class Mailbox{
public:
    void addPackage(Package p);
    Package[] allPackage();
    friend Mailbox& operator+(const Mailbox& m1, const Mailbox& m2);
    Package[] fromPerson(string name, int& numPackages);
    void clean();
    bool operator==(const Mailbox& m1, const Mailbox& m2);
    bool operator!-(const Mailbox& m1, const Mailbox& m2);
    string getOwner();
private:
    int capacity;
    int size;
    Package* p;
    string owner;
};

#endif