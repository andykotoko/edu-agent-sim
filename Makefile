CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

INCLUDE = -I.

SRC = NameGenerator.cpp student.cpp teacher.cpp simulation.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = edu_agent_sim

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)
