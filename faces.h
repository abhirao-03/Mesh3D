#include <vector>
#include <tuple>
#include <iostream>

class mesh_faces {
    public:
        std::vector<std::vector<int>> face_connections;
        int num_faces;

        void add_face(std::vector<int> face){
            face_connections.push_back(face);
            num_faces = face_connections.size();
        };

        void print_faces(){
            std::cout << "There are " << num_faces << " faces." << std::endl;
            for (std::vector<int> faces : face_connections){
                for (auto i : faces){
                    std::cout << i << " ";
                };
            };
        };

        void read_faces_file(std::string file_path);
};
