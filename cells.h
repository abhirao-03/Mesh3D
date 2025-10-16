#include <vector>
#include <tuple>
#include <iostream>

class mesh_cells {
    public:
        std::vector<std::vector<int>> cell_connections;
        int num_cells;

        void add_cell(std::vector<int> cell){
            cell_connections.push_back(cell);
            num_cells = cell_connections.size();
        };

        void print_cells() {
            std::cout << "There are " << num_cells << " cells:" << std::endl;
            
            for (const auto cell : cell_connections) {
                std::cout << "( ";
                for (int point_index : cell) {
                    std::cout << point_index << " ";
                }
                std::cout << ")" << std::endl;
            }
        }

        void read_cells_file(std::string file_path);
};
