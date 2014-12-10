TARGET = fly

SRC_FILES = \
	Driver.cpp \
	Time.cpp \
	Map.cpp \
	City.cpp\
	Date.cpp

OBJ_FILES = \
	Driver.o \
	Time.o \
	Map.o \
	City.o\
	Date.o

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	g++ -Wall $(OBJ_FILES) -o $(TARGET).exe

Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp

Time.o: Time.cpp
	g++ -Wall -c Time.cpp

Date.o: Date.cpp
	g++ -Wall -c Date.cpp

Map.o: Map.cpp
	g++ -Wall -c Map.cpp

City.o: City.cpp
	g++ -Wall -c City.cpp
clean:
	rm *~ *# *.o *.exe $(TARGET).exe
