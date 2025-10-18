#include <vector>
#include <tuple>
#include <iostream>
class PointsCreator {
    private:
        std::vector<std::vector<double>> point_positions;
        int num_points;
    
    public:
        void add_point(std::vector<double> point){
            point_positions.push_back(point);
            num_points = point_positions.size();
        };

        void print_points(){
            std::cout << "There are " << num_points << " points." << std::endl;
            for (std::vector<double> point : point_positions){
                double x = point[0];
                double y = point[1];
                double z = point[2];
                std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
            };
        };

        int& get_num_points() {return num_points;};

        void read_points_file(std::string file_path);
};