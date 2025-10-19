#include <fstream>
#include <iostream>
#include <sstream>
#include "headers/cells.h"

void CellCreator::read_cells_file(std::string file_path){
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
    int num_cells;
    char throw_par;
    string_stream >> num_cells >> throw_par;
    
    int num_faces_in_cell;
    int cell_id = 0;
    while (string_stream >> num_faces_in_cell >> throw_par){
            std::vector<int> face_points;
            int face;

            for (int i = 0; i < num_faces_in_cell; i++){
                string_stream >> face;
                face_points.push_back(face);
            };

            string_stream >> throw_par;
            Cell new_cell(cell_id, face_points);
            add_cell(new_cell);
    };

};


// int main(){
//     CellCreator my_cells;
//     my_cells.read_cells_file("data/cells.txt");
//     my_cells.print_cells();
//     return 0;
// }