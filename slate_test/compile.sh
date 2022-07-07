mpicxx -fopenmp -DSLATE_NO_CUDA -DSLATE_NO_HIP -I${SLATE_ROOT}/include -c slate_matrix_vector.cc

mpicxx -fopenmp -o slate_matrix_vector slate_matrix_vector.o -L${SLATE_ROOT}/lib -Wl,-rpath,${SLATE_ROOT}/lib

