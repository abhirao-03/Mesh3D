#include <vector>
#include <tuple>
#include <iostream>

class MeshCells {
    private:
        std::vector<std::vector<int>> cell_connections;
        int num_cells;

    public:
        void add_cell(std::vector<int> cell){
            cell_connections.push_back(cell);
            num_cells = cell_connections.size();
        };

        void print_cells() {            
            for (const auto cell : cell_connections) {
                std::cout << "( ";
                for (int point_index : cell) {
                    std::cout << point_index << " ";
                }
                std::cout << ")" << std::endl;
            }
        }

        int& get_num_cells() {return num_cells;}

        void read_cells_file(std::string file_path);

};
