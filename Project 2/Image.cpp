#include "Image.h"
#include <iostream>


Image::Image(){
    name = "";
    type = "gif";
    size = getSize();
    pixel_row = 0;
    pixel_col = 0;
    color_depth = 0;
}

Image::Image(std::string n, int pRow, int pCol, int cDepth){
    name = n;
    type = "gif";
    pixel_row = pRow;
    pixel_col = pCol;
    color_depth = cDepth;
    size = getSize();
}


std::string Image::getName(){
    return name;
}
std::string Image::getType(){
    return type;
}

int Image::getSize(){
    size = (pixel_row * pixel_col * color_depth)/8;
    return size;
}

int Image::getPixelCol(){
    return pixel_col;
}

int Image::getPixelRow(){
    return pixel_row;
}

int Image::getColorDepth(){
    return color_depth;
}

void Image::displayProperties(){
    std::cout << "Name: " << name << std::endl <<
    "Type: " << type << std::endl << 
     "Size: " << size << std::endl << 
     "Dimensions: " << pixel_row << "X" << pixel_row << std::endl <<
     "Color Depth: " << color_depth << std::endl;
}