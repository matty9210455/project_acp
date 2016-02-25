####### COMPILER SETTINGS: DO NOT CHANGE!!! ####### 

CXX = g++
CXXFLAGS = -O3 -march=native -Wall -Wextra -std=c++11 -I$(INCLUDE_DIR)
CXXFLAGS_OMP = -fopenmp -openmp





OMP_SRC = prove.cpp


#####################################################

########### MAKE RULES: DO NOT CHANGE!!! ############




	
prova: $(OMP_SRC) $(DEPS)
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_OMP) $(OMP_SRC) -o $@
	

	
clean:
	rm -f prova* *~
	
#####################################################