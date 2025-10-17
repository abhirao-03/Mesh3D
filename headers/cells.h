#include <vector>
#include <tuple>
#include <iostream>

class Cell {
    private:
        int cell_id;
        double cell_volume;
        std::vector<int> face_composition;
        std::tuple<double, double, double> cell_center;
    
    public:
        Cell(int id, std::vector<int> face){
            cell_id = id;
            face_composition = face;
            cell_volume = -1;
            cell_center = std::make_tuple(-1, -1, -1);

        }

        void set_cell_id(int new_id){cell_id = new_id;};    
        void set_cell_volume(double new_vol){cell_volume = new_vol;};
        void set_cell_center(std::tuple<double, double, double> new_center){cell_center = new_center;};
        void set_faces(std::vector<int> new_faces){face_composition = new_faces;};
        void print() const {
            std::cout << "( ";
                for (int index : face_composition) {
                    std::cout << index << " ";
                }
                std::cout << ")" << std::endl;
            }
};

class CellCreator {
    private:
        int num_cells;
        std::vector<Cell> cell_objects;

    public:
        void add_cell(Cell cell){
            cell_objects.push_back(cell);
            num_cells = cell_objects.size();
        };

        void print_cells() {
            std::cout << "There are " << get_num_cells() << " cells:" << std::endl;
            for(Cell c: cell_objects){
                c.print();
            };
        }

        int& get_num_cells() {return num_cells;}

        void read_cells_file(std::string file_path);
};