CXX = g++ -std=c++11

all: getpower


getpower:
	$(CXX) getpower.cpp ../Adafruit_INA219.o -lwiringPi -o getpower

clean:
	rm -f *.o *.out getpower
