####### COMPILER SETTINGS: DO NOT CHANGE!!! ####### 

CXX = g++
MPICXX = mpic++ 
CXXFLAGS = -O3 -march=native -Wall -Wextra -std=c++11 -I$(INCLUDE_DIR)


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



MPI_SRC = $(SRC)/main.cpp $(SRC)/read.cpp $(SRC)/write_update.cpp $(SRC)/update.cpp 

#####################################################

########### MAKE RULES: DO NOT CHANGE!!! ############

all: mpi

	
mpi: $(MPI_SRC) $(DEPS)
	$(MPICXX) $(CXXFLAGS) $(MPI_SRC) -o $@
	
clean:
	rm -f mpi* *~
	
#####################################################