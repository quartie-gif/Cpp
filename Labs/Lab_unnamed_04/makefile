
EXEC=main
ALLSRC=*.cpp
CXXFLAGS=-std=c++20 -Wall -g 
# mozna dodac powyzej  --pednatic

$(EXEC): $(ALLSRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(EXEC) *.o
