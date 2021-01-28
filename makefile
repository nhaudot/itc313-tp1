# Generic Makefile with automatic dependencies management

# Choose your compiler g++/clang++
CXX        = g++
CXXFLAGS   = -std=c++11 # -Wall -Wextra
DEPFLAGS   = -MMD
LDFLAGS    = 
SRCS       = main.cpp date.cpp client.cpp hotel.cpp chambre.cpp booking.cpp
OBJS       = $(SRCS:.cpp=.o)
TARGET     = main
DEPS	   = $(OBJS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS) 

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c  $<

cleano:
	rm -f *.o *.d

cleanall: cleano
	rm -f $(TARGET)

exe: $(TARGET)
	./$(TARGET)

-include $(DEPS)