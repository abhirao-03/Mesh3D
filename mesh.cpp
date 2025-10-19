#include <iostream>
#include <fstream>
#include <set>
#include "headers/cells.h"
#include "headers/points.h"
#include "headers/faces.h"

class Mesh3D {
    private:
        PointsCreator mesh_points;
        FaceCreator   mesh_faces;
        CellCreator   mesh_cells;

    public:
        Mesh3D(std::string points_fp, std::string faces_fp, std::string cells_fp){
            mesh_points.read_points_file(points_fp);
            mesh_faces.read_faces_file(faces_fp);
            mesh_cells.read_cells_file(cells_fp);
        }

        void print_all_points(){
            mesh_points.print_points();
        };

        void print_all_faces(){
            mesh_faces.print_faces();
        };

        void print_all_cells(){
            mesh_cells.print_cells();
        };
        
        std::vector<double> get_cell_center(int cell_id);
};


int main(){
    Mesh3D test_mesh("data/points.txt", "data/faces.txt", "data/cells.txt");
    // test_mesh.print_all_cells();
    // test_mesh.print_all_faces();
    // test_mesh.print_all_points();

    std::vector<double> cell_center_0 = test_mesh.get_cell_center(0);

    std::cout << "( ";
        for (double index : cell_center_0) {
            std::cout << index << " ";
        }
        std::cout << ")" << std::endl;

    return 0;
}