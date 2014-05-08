CXXFLAGS =	-O0 -g -Wall -fmessage-length=0

# Tienen que reemplazar SistemaLaboral.cpp y Temporada.cpp por 
# las implementaciones correspondientes a su TP para que este
# Makefile compile
SOURCES = tp3.cpp SistemaLaboral.cpp Temporada.cpp Driver.cpp
OBJS = $(SOURCES:.cpp=.o)

LIBS =

TARGET =	tp3

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
