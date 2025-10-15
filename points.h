#include <vector>

class mesh_points {
    private:
        int num_points;
        std::vector<std::tuple<double, double, double>> point_positions;
    public:
        void add_point(std::tuple<double, double, double> point){
            point_positions.push_back(point);
        }

};