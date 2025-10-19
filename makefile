all : point_reader face_reader cell_reader

Mesh3D : main.cpp mesh.cpp headers/cells.h headers/points.h headers/faces.h dataReaders/cell_reader.cpp dataReaders/point_reader.cpp dataReaders/face_reader.cpp 
	g++ main.cpp mesh.cpp headers/*.h dataReaders/*.cpp -o Mesh3D.o

cell_reader : dataReaders/cell_reader.cpp headers/cells.h
	g++ dataReaders/cell_reader.cpp -o read_cells.o

point_reader : dataReaders/point_reader.cpp headers/points.h
	g++ dataReaders/point_reader.cpp -o read_points.o

face_reader : dataReaders/face_reader.cpp headers/faces.h
	g++ dataReaders/face_reader.cpp -o read_faces.o

clean : 
	rm *.o