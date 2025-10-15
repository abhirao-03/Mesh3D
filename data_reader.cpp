#include <fstream>
#include <iostream>
#include <sstream>

int main(){
    std::ifstream inFile;
    std::string file_path;
    std::string points;
    std::string entire_passage;

    // ask the user for the path of the file.
    std::cout << "path of file: ";
    std::cin >> file_path;

    // open the file and read it line by line and append into entire_passage
        inFile.open(file_path);
            if (inFile.is_open()) {
                    while (std::getline(inFile, points)) {
                        entire_passage += points;
                    }
                    inFile.close();
            }
    
    std::cout << entire_passage << std::endl; // sanity check printing


    // this essentially makes the string into a constant stream of info like std::cin
    std::istringstream string_stream(entire_passage);
    
    // grab the first integer and store it.
    int num_points;
    string_stream >> num_points;
    std::cout << num_points << '\n' << std::endl; // sanity check the num_points by printing.

    // establish the pattern for the points:
    double x, y, z;
    char openPar, closePar;
    
    string_stream >> openPar >> x >> y >> z >> closePar;

    std::cout << "x is:" << x << "y is:" << y << "z is:" << z << std::endl;

    return 0;
};