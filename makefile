TARGET = fly

SRC_FILES = \
	Driver.cpp \
	Time.cpp \
	#Flight.cpp

OBJ_FILES = \
	Driver.o \
	Time.o \
	#Flight.o

all: $(TARGET)

$TARGET: $(OBJ_FILES) -o $(TARGET).exe

Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp

Time.o: Time.cpp
	g++ -Wall -c Time.cpp

Flight.o: Flight.cpp
	g++ -Wall -c Flight.cpp

clean:
	rm *~ *# *.o *.exe $(TARGET).exe