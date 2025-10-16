#include <vector>
#include <tuple>
#include <iostream>

class mesh_faces {
    public:
        std::vector<std::vector<double>> face_connections;
        int num_faces;

        void add_face(std::tuple<double, double, double> face){
            face_connections.push_back(face);
            num_faces = face_connections.size();
        };

        void print_points(){
            std::cout << "There are " << num_faces << " points." << std::endl;
            for (std::tuple<double, double, double> faces : face_connections){
                double x, y, z;
                std::tie(x, y, z) = faces;
                std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
            };
        };

        void read_points_file(std::string file_path);
};
