CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		test33.o

LIBS = -lgdi32

TARGET =	test33.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
