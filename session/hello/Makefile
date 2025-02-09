CC=gcc
CCP=g++
CFLAGS=-I. -O3
LFLAGS=-I. -lm
DEPS = api.h
OBJ = hello.o api.o api2.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	$(CCP) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CCP) -o $@ $^ $(CFLAGS)

clean:
	rm *.o