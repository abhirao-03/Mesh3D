#include <cmath>
#include "mesh.h"

double calc_area_triangle(std::vector<double> vec_1, std::vector<double> vec_2){
    double comp1 = vec_1[1]*vec_2[2] - vec_1[2]*vec_2[1];
    double comp2 = vec_1[2]*vec_2[0] - vec_1[0]*vec_2[2];
    double comp3 = vec_1[0]*vec_2[2] - vec_1[1]*vec_2[0];

    double mag_squared = std::pow(comp1, 2) + std::pow(comp2, 2) + std::pow(comp3, 2);
    double mag = std::pow(mag_squared, (1.0/2.0));

    return (1.0/2.0) * mag;
};

Mesh3D::Mesh3D(std::string points_fp, std::string faces_fp, std::string cells_fp){
    mesh_points.read_points_file(points_fp);
    mesh_faces.read_faces_file(faces_fp);
    mesh_cells.read_cells_file(cells_fp);
};

void Mesh3D::print_all_points(){
    mesh_points.print_points();
};

void Mesh3D::print_all_faces(){
    mesh_faces.print_faces();
};

void Mesh3D::print_all_cells(){
    mesh_cells.print_cells();
};

double Mesh3D::get_face_area(int cell_id, int face_id){
    Cell curr_cell = mesh_cells.get_cell(cell_id);
    int face_idx = curr_cell.get_face_composition()[face_id];
    Face curr_face = mesh_faces.get_face(face_idx);
    std::vector<int> curr_points = curr_face.get_point_composition();
    std::vector<std::vector<double>> inner_vectors;
    std::vector<double> face_center = get_face_center(cell_id, face_id);
    
    for (int p_idx : curr_points){
        double x_in_diff = mesh_points.get_point(p_idx)[0] - face_center[0];
        double y_in_diff = mesh_points.get_point(p_idx)[1] - face_center[1];
        double z_in_diff = mesh_points.get_point(p_idx)[2] - face_center[2];
        inner_vectors.push_back({x_in_diff, y_in_diff, z_in_diff});        
    };

    double area = 0;

    for (int v_idx = 1; v_idx < inner_vectors.size(); v_idx++){
        area += calc_area_triangle(inner_vectors[v_idx - 1], inner_vectors[v_idx]);
    };

    return area;

};

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
        std::vector<int> point_composition = curr_face.get_point_composition();
        
        // curr_face.print();

        for (int point_id : point_composition){
            std::vector<double> curr_point = mesh_points.get_point(point_id);
            
            // std::cout << point_id << std::endl;

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

std::vector<double> Mesh3D::get_face_center(int cell_id, int face_id){
    Cell curr_cell = mesh_cells.get_cell(cell_id);
    std::vector<int> face_comp = curr_cell.get_face_composition();

    // if (face_id >= face_comp.size()){
    //     std::cout << "face_id is out of index. please specify a new face_id" << std::endl;
    //     face_id = face_comp.size();
    // }

    Face curr_face = mesh_faces.get_face(face_id);
    
    std::vector<int> curr_points = curr_face.get_point_composition();

    double x_sum = 0.0;
    double y_sum = 0.0;
    double z_sum = 0.0;

    for (int i_point : curr_points){
        x_sum += mesh_points.get_point(i_point)[0];
        y_sum += mesh_points.get_point(i_point)[1];
        z_sum += mesh_points.get_point(i_point)[2];
    }

    int num_points = curr_points.size();

    return {x_sum/num_points, y_sum/num_points, z_sum/num_points};

};
