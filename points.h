#include <vector>

class mesh_points {
    private:
        int num_points;
        std::vector<std::tuple<double, double, double>> point_positions;
    public:
        void add_point(std::tuple<double, double, double> point){
            point_positions.push_back(point);
        };

        void set_num_points(int n){
            num_points = n;
        };

        void print_points(){
            for (std::tuple<double, double, double> point : point_positions){
                double x, y, z = point;
                std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
            };
        };
};