all: shapefinder.o imageInput.o contour.o
	g++ -Wall -g shapefinder.o imageInput.o contour.o `pkg-config --libs opencv` -o shapefinder

shapefinder.o: shapefinder.cpp
	g++ -Wall -g -c shapefinder.cpp
	
imageInput.o: imageInput.cpp imageInput.h
	g++ -Wall -g -c imageInput.cpp
	
contour.o: contour.cpp contour.h
	g++ -Wall -g -c contour.cpp
	
clean:
	rm shapefinder shapefinder.o imageInput.o contour.o
	rm *.png