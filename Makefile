main : main.o
	g++ build/main.o -o build/main -std=c++14
main.o: src/main.cpp src/include/Buffer.h src/include/Binary.h src/include/Typefigure.h src/include/Seel.h
	g++ -c src/main.cpp -o build/main.o -std=c++14