shapefinder: shapefinder.o imageInput.o
	g++ -Wall -g shapefinder.o imageInput.o `pkg-config --libs opencv` -o shapefinder

shapefinder.o: shapefinder.cpp
	g++ -c shapefinder.cpp
	
imageInput.o: imageInput.cpp imageInput.h
	g++ -c imageInput.cpp
	
clean:
	rm shapefinder shapefinder.o imageInput.o binary.png gray.png