all:
	g++ main.cpp cameraADT.cpp PolygonADT.cpp -lGLU -lGL -lglut
	./a.out