CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

#OBJS =		main.o
#OBJS =		test/cpp/test1.o

SRC_DIR := .
OBJ_DIR := .
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

LIBS = -lgdi32

TARGET =	main.exe
#TARGET =	test/cpp/test1.exe

#$(OBJS):	$(SRC_FILES)
#	@echo $(SRC_FILES)
#	$(CXX) -o $(OBJS) $(SRC_FILES)

#$(TARGET):	$(OBJS)
#	@echo $(OBJ_FILES)
#	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LIBS)
	
$(TARGET): $(OBJS)
	$(CXX) -o $@ $^ $(LIBS)
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
