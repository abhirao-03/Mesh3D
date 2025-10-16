#include <vector>
#include <tuple>
#include <iostream>
class mesh_points {
    public:
        std::vector<std::tuple<double, double, double>> point_positions;
        int num_points;

        void add_point(std::tuple<double, double, double> point){
            point_positions.push_back(point);
            num_points = point_positions.size();
        };

        void print_points(){
            std::cout << "There are " << num_points << " points." << std::endl;
            for (std::tuple<double, double, double> point : point_positions){
                double x, y, z;
                std::tie(x, y, z) = point;
                std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
            };
        };

        void read_points_file(std::string file_path);
};