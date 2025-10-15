#include <fstream>
#include <iostream>
#include <sstream>
#include "points.h"

void mesh_points::read_points_file(std::string file_path){
    std::ifstream inFile;
    std::string points;
    std::string entire_passage;

    // // ask the user for the path of the file.
    // std::cout << "path of file: ";
    // std::cin >> file_path;

    // open the file and read it line by line and append into entire_passage
        inFile.open(file_path);
            if (inFile.is_open()) {
                    while (std::getline(inFile, points)) {
                        entire_passage += points;
                    }
                    inFile.close();
            }
    
    // std::cout << entire_passage << std::endl; // sanity check printing

    // this essentially makes the string into a constant stream of info like std::cin
    std::istringstream string_stream(entire_passage);
    
    // grab the first integer and store it.
    int num_points;
    char throw_par;
    string_stream >> num_points >> throw_par;
    //std::cout << num_points << '\n' << std::endl; // sanity check the num_points by printing.

    // create variables for the x y z values of the points.
    // we assign values to clear them from the memory register to make sure the pattern works.
    double x = 1.0;
    double y = 3.0;
    double z = 2.0;

    char openPar, closePar;
    
    while (string_stream >> openPar >> x >> y >> z >> closePar){
        // sanity checking pattern printing for points.
        // std::cout << "x is: " << x << " y is: " << y << " z is: " << z << std::endl;
        add_point(std::make_tuple(x, y, z));
    }
};


int main(){
    mesh_points my_points;
    my_points.read_points_file("data/points.txt");
    my_points.print_points();
    return 0;
}