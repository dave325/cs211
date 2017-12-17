#include "File.h"
#include "Text.h"
#include "Image.h"
#include <iostream>
#include <vector>
#include <string>
void output(std::vector<File*> v);
std::vector<File*> sortVector(std::vector<File*> v, std::string s);
int main(){
    File** f = new File*[3];
    std::vector<File*> v;
    f[0] = new Text("David's Document", 6);
    f[1] = new Text("David's Document 1", 6);
    f[2] = new Image("David's Image", 10, 12,5);
    v.push_back(f[0]);
    v.push_back(f[1]);
    v.push_back(f[2]);
    output(v);
    std::cout << "After sort\n";
    std::vector<File*> v1 = sortVector(v, "txt");
    std::cout << v1.size();
    output(v1);
    return 0;
}
void output(std::vector<File*> v){
    if(v.empty())
        return;
    v.front()->displayProperties();
    v.erase(v.begin());
    output(v);
}

std::vector<File*> sortVector(std::vector<File*> v, std::string s){
    if(v.empty())
        return v;
    if(v.back()->getType() != s){
        v.erase(v.end());
    }
    return sortVector(v, s);
}