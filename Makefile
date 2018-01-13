CXX = g++ -std=c++11

all: ina219.o


ina219.o:
	$(CXX) Adafruit_INA219.cpp -lwiringPi -c

clean:
	rm *.o *.out
