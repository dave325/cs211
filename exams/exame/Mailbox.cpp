#include "Package.h"
#include "Mailbox.h"
#include string

using namespace std;

Mailbox::Mailbox(size){
    size = size;
    capacity = size +1;
    p = new Packages[capacity];
}
void Mailbox::addPackage(Package p){
    if(size == 0){
        grow();
    }
    p[size] = p;
    size++;
}

Mailbox& operator+(const Mailbox& m1, const Mailbox& m2){
    int size = m1.getSize() + m2.getSize();
    Mailbox m(size);
    for(int i = 0; i < size; i += 2){
        m.getPackages()[i] = m1.getPackages()[i];
        m.getPackages()[i+1] = m2.getPackages()[i];
    }
    return m;
}

Package[] Mailbox::fromPerson(string name, int& numPackages){
    Package pFrom[size];
    int j = 0;
    for(int i = 0; i < size(); i++){
        if(p[i].from == name){
            p[j] = p[i]; 
            j++;
        }
    }
    numPackages = j;
    return pFrom;
}

bool Mailbox::operator==(const Mailbox& m1, const Mailbox& m2){
    if(m1.getSize() == m2.getSize()){
        for(int i = 0; i < m1.size(); i++){
            if(m1.getPackages()[i] != m2.getPackages()[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

