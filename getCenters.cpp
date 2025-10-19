#include "mesh.cpp"

std::vector<double> Mesh3D::get_cell_center(int cell_id){
    Cell curr_cell = mesh_cells.get_cell(cell_id);
    // curr_cell.print();

    std::vector<int> face_composition = curr_cell.get_face_composition();
    std::set<std::vector<double>> all_points;

    double x_sum = 0.0;
    double y_sum = 0.0;
    double z_sum = 0.0;

    for (int face_id : face_composition){
        Face curr_face = mesh_faces.get_face(face_id);
        // curr_face.print();
        std::vector<int> point_composition = curr_face.get_point_composition();
        
        for (int point_id : point_composition){
            // std::cout << point_id << std::endl;
            std::vector<double> curr_point = mesh_points.get_point(point_id);

            // for (double i : curr_point){
            //     std::cout << i << " ";
            // }

            if (all_points.find(curr_point) == all_points.end()){
                x_sum += curr_point[0];
                y_sum += curr_point[1];
                z_sum += curr_point[2];
                all_points.insert(curr_point);
            };
        };
    };

    double num_unique_points = all_points.size();
    
    std::vector<double> final_centroid = {x_sum/num_unique_points, y_sum/num_unique_points, z_sum/num_unique_points};
    
    return final_centroid;
};