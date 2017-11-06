thread: thread.o 
	g++ -o thread thread.o -pthread -l rt

thread.o : thread.cpp 
	g++ -c thread.cpp -std=c++11 
