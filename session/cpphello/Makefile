CC=gcc
CCP=g++
CFLAGS=-I. 
LFLAGS=-I. 
DEPS = api.h
OBJ = hello.o

%.o: %.cpp $(DEPS)
	$(CCP) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CCP) -o $@ $^ $(CFLAGS)

clean:
	rm *.o