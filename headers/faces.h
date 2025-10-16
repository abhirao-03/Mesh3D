#include <vector>
#include <tuple>
#include <iostream>

class MeshFaces {
    private:
        std::vector<std::vector<int>> face_connections;
        int num_faces;

    public:
        void add_face(std::vector<int> face){
            face_connections.push_back(face);
            num_faces = face_connections.size();
        };

        void print_faces() {
            std::cout << "There are " << num_faces << " faces:" << std::endl;
            
            for (const auto face : face_connections) {
                std::cout << "( ";
                for (int point_index : face) {
                    std::cout << point_index << " ";
                }
                std::cout << ")" << std::endl;
            }
        }

        int& get_num_faces() {return num_faces;}

        void read_faces_file(std::string file_path);
};
