#include <vector>
#include <tuple>
#include <iostream>

class Face {
    private:
        int owner_cell_id;
        int neighbour_cell_id;
        std::vector<int> point_composition;
    
    public:
        Face(const std::vector<int>& points){
            point_composition = points;
            owner_cell_id = -1;
            neighbour_cell_id = -1;
        };

        void set_owner_cell_id(int owner_id){
            owner_cell_id = owner_id;
        };

        void set_neighbour_cell_id(int nbr_id){
            neighbour_cell_id = nbr_id;
        };
        
        void print() const {
            std::cout << "( ";
                for (int index : point_composition) {
                    std::cout << index << " ";
                }
                std::cout << ")" << std::endl;
            }
        
        std::vector<int> get_point_composition() const {return point_composition;}

};

class FaceCreator {
    private:
        int num_faces;
        std::vector<Face> face_objects;

    public:

        Face get_face(int face_id){return face_objects[face_id];};

        void add_face(Face face){
            face_objects.push_back(face);
            num_faces = face_objects.size();
        };

        void print_faces() {
            std::cout << "There are " << get_num_faces() << " faces:" << std::endl;
            for(Face i: face_objects){
                i.print();
            };
        }

        int get_num_faces() {return num_faces;}

        void read_faces_file(std::string file_path);
};