#include <mesh.h>

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


    std::vector<double> face_center_0 = test_mesh.get_face_center(0, 0);

    std::cout << "( ";
        for (double index : face_center_0) {
            std::cout << index << " ";
        }
        std::cout << ")" << std::endl;


    return 0;
}