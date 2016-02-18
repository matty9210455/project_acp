####### COMPILER SETTINGS: DO NOT CHANGE!!! ####### 

CXX = g++
MPICXX = mpic++ 
CXXFLAGS = -O3 -march=native -Wall -Wextra -std=c++11 -I$(INCLUDE_DIR)
CXXFLAGS_OMP = -fopenmp -openmp

#####################################################


############### HEADER FILE SETTINGS ###############

# PUT HERE THE FOLDER WITH YOUR HEADER FILES, IF ANY
# FOR EXAMPLE:
# INCLUDE_DIR = include
INCLUDE_DIR = Include

# PUT HERE THE PATH TO YOUR HEADER FILES TO CORRECTLY RECOMPILE AT ANY CHANGE
# FOR EXAMPLE:
# DEPS = $(INCLUDE_DIR)/*.h*
DEPS = $(INCLUDE_DIR)/*.h*

#####################################################

############## SOURCE FILE SETTINGS ###############

# PUT HERE THE FOLDER WITH YOUR SOURCe FILES
# FOR EXAMPLE:
# SRC = src
SRC = Src

# FOR EVERY VERSION OF THE PROGRAM, PUT HERE THE LIST OF SOURCE FILES TO BE COMPILED
# FOR EXAMPLE
# SERIAL_SRC = $(SRC)/main_st.cpp
# OMP_SRC = $(SRC)/main_omp.cpp
# MPI_SRC = $(SRC)/main_mpi.cpp

OMP_SRC = $(SRC)/main.cpp $(SRC)/read.cpp $(SRC)/write_update.cpp



#####################################################

########### MAKE RULES: DO NOT CHANGE!!! ############

all: omp

	
omp: $(OMP_SRC) $(DEPS)
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_OMP) $(OMP_SRC) -o $@
	
	
clean:
	rm -f omp* *~
	
#####################################################