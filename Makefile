main : main.o
	g++ build/main.o -o build/main -std=c++14 -fpermissive
main.o: src/include/Binary.h src/include/Typefigure.h src/include/Seel.h src/main.cpp src/include/Buffer.h src/include/Reflection.h
	g++ -c src/main.cpp -o build/main.o -std=c++14 -fpermissive