//this file is meant to read in data and store them in variables.
//this data can then be passed into the Mesh3D class to create a mesh object.
#include <fstream>
#include <iostream>

int main(){
    std::ifstream inFile;
    std::string file_path;
    std::string points;
    std::string entire_passage;


    std::cout << "path of file: ";
    std::cin >> file_path;
    inFile.open(file_path);

if (inFile.is_open()) {
        while (std::getline(inFile, points)) {
            entire_passage += points;
        }
        inFile.close();
}
        std::cout << entire_passage << std::endl;
    return 0;
};