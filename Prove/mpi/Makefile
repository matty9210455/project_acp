####### COMPILER SETTINGS: DO NOT CHANGE!!! ####### 

CXX = g++
MPICXX = mpic++ 
CXXFLAGS = -O3 -march=native -Wall -Wextra -std=c++11 -I$(INCLUDE_DIR)
CXXFLAGS_OMP = -fopenmp -openmp

#####################################################

MPI_SRC = mpi.cpp

#####################################################

########### MAKE RULES: DO NOT CHANGE!!! ############

all: pr

	
pr: $(MPI_SRC) $(DEPS)
	$(MPICXX) $(CXXFLAGS) $(MPI_SRC) -o $@
	
clean:
	rm -f pr* *~
	
#####################################################