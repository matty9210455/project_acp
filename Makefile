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
INCLUDE_DIR = include

# PUT HERE THE PATH TO YOUR HEADER FILES TO CORRECTLY RECOMPILE AT ANY CHANGE
# FOR EXAMPLE:
# DEPS = $(INCLUDE_DIR)/*.h*
DEPS = $(INCLUDE_DIR)/*.h*

#####################################################

############## SOURCE FILE SETTINGS ###############

# PUT HERE THE FOLDER WITH YOUR SOURCe FILES
# FOR EXAMPLE:
# SRC = src
SRC = src

# FOR EVERY VERSION OF THE PROGRAM, PUT HERE THE LIST OF SOURCE FILES TO BE COMPILED
# FOR EXAMPLE
# SERIAL_SRC = $(SRC)/main_st.cpp
# OMP_SRC = $(SRC)/main_omp.cpp
# MPI_SRC = $(SRC)/main_mpi.cpp

SERIAL_SRC = 

OMP_SRC = 

MPI_SRC = 

#####################################################

########### MAKE RULES: DO NOT CHANGE!!! ############

all: acprecsys_st acprecsys_omp acprecsys_mpi

acprecsys_st: $(SERIAL_SRC) $(DEPS)
	$(CXX) $(CXXFLAGS) $(SERIAL_SRC) -o $@
	
acprecsys_omp: $(OMP_SRC) $(DEPS)
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_OMP) $(OMP_SRC) -o $@
	
acprecsys_mpi: $(MPI_SRC) $(DEPS)
	$(MPICXX) $(CXXFLAGS) $(MPI_SRC) -o $@
	
clean:
	rm -f acprecsys* *~
	
#####################################################