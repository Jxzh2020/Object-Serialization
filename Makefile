main : main.o
	g++ build/main.o -o build/main
main.o: src/main.cpp src/include/Buffer.h src/include/Binary.h
	g++ -c src/main.cpp -o build/main.o