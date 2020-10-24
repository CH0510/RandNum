main:main.o  RandNum.o 
	g++ main.o RandNum.o -o main
main.o:main.cpp RandNum.h
	g++ -c main.cpp -o main.o
RandNum.o:RandNum.cpp RandNum.h
	g++ -c RandNum.cpp -o RandNum.o
.PHONY:clean
clean:
	rm -rf *.o main *.txt
