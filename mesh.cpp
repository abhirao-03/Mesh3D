#include <iostream>
#include <fstream>
#include "headers/cells.h"
#include "headers/points.h"
#include "headers/faces.h"

class Mesh3D {
    private:
        MeshPoints mesh_points;
        MeshCells  mesh_cells;
        MeshFaces  mesh_faces;
    

    public:
        int print_num_points(){
            std::cout << "There are " << mesh_points.get_num_points() << " points." << std::endl; 
        };

        int print_num_faces(){
            std::cout << "There are " << mesh_faces.get_num_faces() << " faces." << std::endl;
        };

        int print_num_cells(){
            std::cout << "There are " << mesh_cells.get_num_cells() << " cells." << std::endl;
        };
        
        std::vector<double> get_face_center(int cell_id, int face_id){

        };
};