CXX = `root-config --cxx`
CXXFLAGS = `root-config --cflags` -fPIC -g -Wall
ROOTLIBS = `root-config --glibs` -lMathMore
SHARED = -shared
SRCS = TexStreamer.cxx TexStreamer.cpp
HDRS = TexStreamerDict.h TexStreamer.hh 
PROGRAM = TexStreamer.so

all: $(PROGRAM)

TexStreamer.cxx: $(HDRS) TexStreamerDict.h
	@echo "Generating dictionary ..."
	#@rootcint -f $@ -c -p $^
	@rootcling -f TexStreamer.cxx -rml TexStreamer.so -rmf TexStreamer.rootmap TexStreamer.hh TexStreamerDict.h 

$(PROGRAM): $(SRCS)
	@echo "Building $(PROGRAM) ..."
	@rm -f $(PROGRAM)
	@$(CXX) $(CXXFLAGS) $(SHARED) -o $@ $^ $(ROOTLIBS)
	@echo "done"
#options:
clean:; @rm -rf core *.so *.rootmap *.cxx *.pcm
