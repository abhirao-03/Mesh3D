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
        
        std::vector<double> get_cell_center(int cell_id){
        
            Cell curr_cell = mesh_cells.get_cell(cell_id);
            
            // curr_cell.print();

            std::vector<int> face_composition = curr_cell.get_face_composition();
            std::set<std::vector<double>> all_points;

            double x_sum = 0.0;
            double y_sum = 0.0;
            double z_sum = 0.0;

            for (int face_id : face_composition){
                Face curr_face = mesh_faces.get_face(face_id);

                // curr_face.print();

                std::vector<int> point_composition = curr_face.get_point_composition();
                
                for (int point_id : point_composition){
                    // std::cout << point_id << std::endl;
                    std::vector<double> curr_point = mesh_points.get_point(point_id);

                    // for (double i : curr_point){
                    //     std::cout << i << " ";
                    // }

                    if (all_points.find(curr_point) == all_points.end()){
                        x_sum += curr_point[0];
                        y_sum += curr_point[1];
                        z_sum += curr_point[2];
                        all_points.insert(curr_point);
                    };
                };
            };
            double num_unique_points = all_points.size();
            std::vector<double> final_centroid = {x_sum/num_unique_points, y_sum/num_unique_points, z_sum/num_unique_points};
            return final_centroid;
        };
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