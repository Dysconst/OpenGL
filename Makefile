CXX=g++
DBG=gdb
LDFLAGS=-lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl
BUILDNAME=program
BUILDDIR=./build/
CXXFLAGS=-I./includes -o $(BUILDDIR)$(BUILDNAME)
SRCDIR=./src

.PHONY: clean debug release


clean:
	rm $(BUILDDIR)/*

debug:
	$(CXX) -g $(SRCDIR)/*.c* $(CXXFLAGS) $(LDFLAGS)
	chmod +x $(BUILDDIR)$(BUILDNAME)
	$(DBG) $(BUILDDIR)$(BUILDNAME)

release:
	$(CXX) -O2 $(SRCDIR)/* $(CXXFLAGS) $(LDFLAGS)
	chmod +x $(BUILDDIR)$(BUILDNAME)
	$(BUILDDIR)$(BUILDNAME)
