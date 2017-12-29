#include "File.h"
#include "Text.h"
#include "Image.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
/**
 * Name: David Dataram
 * Project #2/HW#9
 * Class: CS212 Lab MW 7:30-8:20
 * Reason for lateness - I came down with the flu this entire week. I was unable to leave my bed until today.
 * I wanted to submit the project as soon as possible
 */ 
void output(std::vector<File*> v);
std::vector<File*> sortVector(std::vector<File*> v, std::string s);
char menu();
int main(){
    // Variables to store various elements in app
    char c[500];
    // Stores the response
    char response;
    std::string s1, tempName;
    int tempRow, tempCol, tempCDepth;
    // Stores vector and temp vector for sorting purposes
    std::vector<File*> files, temp;
    std::ifstream file;
    file.open("file.txt");
    if(!file){
        std::cerr << "No file\n";
        return 0; 
    }
    int i = 0;
    std::string s[5];
    // continue app if user does not enter 7
    while(response != '7'){
        // store menu option in variable to use in switch statement 
        response = menu();
        switch(response){
            case '1':
                while(getline(file,s1)){
                        if(s1.empty())
                            continue;
                        s[i] = s1;
                        i++;
                        if(s[0].compare("txt") == 0 && i == 3){
                            
                            File* f = new Text(s[1], stoi(s[2]));
                            files.push_back(f);
                            i = 0;
                        }
                        if(s[0] == "gif" && i == 4){
                            std::string token1 = s[2].substr(0, s[2].find("X")); 
                            std::string token2 = s[2].substr(s[2].find("X") + 1); 
                            int col = stoi(token1);
                            int row = stoi(token2);
                            int cDepth = stoi(s[3]);
                            File* f = new Image(s[1], col,row, cDepth);
                            files.push_back(f);
                            i = 0; 
                        }
                }
                std::cout << "Read Successful!\n";
                break;
            case '2':
                std::cout << "Please type the name of the file.\n";
                std::cin >> tempName;
                std::cout << "Please type the Row of pixels for the file.\n";
                std::cin >> tempRow;
                std::cout << "Please type the Col of pixels for the file.\n";
                std::cin >> tempCol;
                std::cout << "Please type the color depth for the file.\n";
                std::cin >> tempCDepth;
                files.push_back(new Image(tempName, tempRow,tempCol, tempCDepth));
                std::cout << "Read Added!\n";
                break;
            case '3':
                std::cout << "Please type the name of the file.\n";
                std::cin >> tempName;
                std::cout << "Please type the amount of characters for the file.\n";
                std::cin >> tempRow;
                files.push_back(new Text(tempName,tempRow));
                std::cout << "Read Added!\n";
                break;
            case '4':
                output(files);
                break;
            case '5':
                temp = sortVector(files, "gif");
                output(temp);
                break;
            case '6':
                temp = sortVector(files, "txt");
                output(temp);
                break;
            case '7':
                std::cout << "Terminating Program!\n";
                return 0;
                break;
            default:
                std::cout <<"No option found" << std::endl;
                break;
        }
    }
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
    static std::vector<File*> v1;
    if(v.size() == 0){
        return v1;
    }
    if(v.front()->getType() == s){
        v1.push_back(v.front());
    }
    v.erase(v.begin());
     return sortVector(v, s);
}

char menu(){
    char ans;
    std::cout << "Press 1 to read from files.txt" << std::endl
        << "Press 2 to create an image file" << std::endl
        << "Press 3 to create an text file" << std::endl
        << "Press 4 to print all files" << std::endl
        << "Press 5 to print Image files" << std::endl
        << "Press 6 to print Text files" << std::endl
        << "Press 7 to exit the program" << std::endl;
    std::cin >> ans;
    return ans;
}