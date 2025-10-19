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
        Mesh3D(std::string points_fp, std::string faces_fp, std::string cells_fp);

        void print_all_points();
        void print_all_faces();
        void print_all_cells();

        double get_cell_volume(int cell_id);
        double get_face_area(int cell_id, int face_id);

        std::vector<double> get_cell_center(int cell_id);
        std::vector<double> get_face_center(int cell_id, int face_id);
};