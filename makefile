all : point_reader face_reader

point_reader : point_reader.cpp points.h
	g++ point_reader.cpp -o read_points.o

face_reader : face_reader.cpp faces.h
	g++ face_reader.cpp -o read_faces.o

clean : 
	rm *.o