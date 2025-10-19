#include <fstream>
#include <iostream>
#include <sstream>
#include "../headers/faces.h"

void FaceCreator::read_faces_file(std::string file_path){
    std::ifstream inFile;
    std::string points;
    std::string entire_passage;

    inFile.open(file_path);

    if (inFile.is_open()) {
            while (std::getline(inFile, points)) {
                entire_passage += points;
            }
            inFile.close();
    };
    
    std::istringstream string_stream(entire_passage);
    
    // grab the first integer and store it.
    int num_faces;
    char throw_par;
    string_stream >> num_faces >> throw_par;
    
    int num_points_in_face;

    while (string_stream >> num_points_in_face >> throw_par){
            std::vector<int> face_points;
            int point;

            for (int i = 0; i < num_points_in_face; i++){
                string_stream >> point;
                face_points.push_back(point);
            };

            string_stream >> throw_par;
            Face new_face(face_points);
            add_face(new_face);
    };

};

// int main(){
//     FaceCreator my_faces;
//     my_faces.read_faces_file("data/faces.txt");
//     my_faces.print_faces();
//     return 0;
// }