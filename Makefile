CPPFILES = main systeminfo
FILES = $(addsuffix .cpp, $(CPPFILES) )
OBJS  = $(addsuffix .o, $(CPPFILES) )

CXX 		= clang++
CXXFLAGS = -std=c++11 -O0 -g

compile: $(FILES)
	$(MAKE) $(OBJS)
	$(CXX) -std=c++11 -o sysinfo $(CXXFLAGS)  $(OBJS)

clean:
	rm -rf sysinfo $(OBJS)
