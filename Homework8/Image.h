#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include "File.h"
class Image : public File{
    private:
        std::string name;
        std::string type;
        int size;
        int pixel_row;
        int pixel_col;
        int color_depth;
    public:  
        Image();
        Image(std::string n, int pRow, int pCol, int cDepth);
        virtual std::string getName();
        virtual std::string getType();
        virtual int getSize();
        int getPixelCol();
        int getPixelRow();
        int getColorDepth();
        void displayProperties();
};

#endif

