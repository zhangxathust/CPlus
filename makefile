# makefile @see http://blog.csdn.net/liang13664759/article/details/1771246

test : test.o mytime0.o other.o stock.o vector.o vegnews.o stringbad.o
	g++ -o test test.o mytime0.o other.o stock.o vector.o vegnews.o stringbad.o

test.o : test.cpp mytime0.h other.h stock.h vegnews.h stringbad.h
	g++ -c test.cpp

mytime0.o : mytime0.cpp mytime0.h
	g++ -c mytime0.cpp

other.o : other.cpp other.h
	g++ -c other.cpp

stock.o : stock.cpp stock.h
	g++ -c stock.cpp

vector.o : vector.cpp vector.h
	g++ -c vector.cpp

stringbad.o : stringbad.cpp stringbad.h
	g++ -c stringbad.cpp

vegnews.o : vegnews.cpp vegnews.h stringbad.h
	g++ -c vegnews.cpp


clean:
	rm test.o mytime0.o other.o stock.o vector.o test walk.txt stringbad.o vegnews.o
