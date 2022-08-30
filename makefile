CXX ?= g++
target = sverify

STATIC_LIBS = -lboost_program_options -lboost_filesystem \
			 -lboost_log -lboost_system -lboost_thread -lboost_regex -pthread -lboost_log_setup
# -lboost_regex  
DYNAMIC_LIBS = -lz3
# -lpthread -lcurl 
LD_FLAGS = ${STATIC_LIBS} ${DYNAMIC_LIBS} 

CXX_INCLUDES = -I./include 

sources = $(wildcard src/*.cpp)
objects = $(subst .cpp,.o, $(sources))

.PHONY: all
all: $(target)
# $@ is the target, sverify
# $^ is all the pre-requisites .o files
$(target): $(objects)
	$(CXX) -std=c++11 -g -o $@ $^ $(LD_FLAGS)
%.o: %.cpp
	$(CXX) -std=c++11 -g -o $@ -c $< $(CXX_INCLUDES)


.PHONY: clean
clean:
	@echo "cleaning up..."
	rm -rvf $(target) src/*.o *.log

.PHONY: test 
test:
	@echo "Testing---------------------------------"
	@echo "sources: $(sources)"
	@echo "objects: $(objects)"