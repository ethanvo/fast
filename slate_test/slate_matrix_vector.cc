// slate_matrix_vector.cc
// Multiply 1000 x 1000 matrix by 1000 element vector
#include <slate/slate.hh>
#include <blas.hh>
#include <mpi.h>
#include <stdio.h>

// Forward function declarations
template <typename scalar_type>
void lu_example( int64_t n, int64_t nrhs, int64_t nb, int64_t p, int64_t q );

template <typename matrix_type>
void random_matrix( matrix_type& A );

int main( int argc, char** argv )
{
    // Initialize MPI, require MPI_THREAD_MULTIPLE support
    int err=0, mpi_provided=0;
    err = MPI_Init_thread( &argc, &argv, MPI_THREAD_MULTIPLE, &mpi_provided );
    assert( err == 0 && mpi_provided == MPI_THREAD_MULTIPLE );
    
    // Call the LU example
    int64_t n=5000, nrhs=1, nb=256, p=2, q=2;
    lu_example< double >( n, nrhs, nb, p, q );

    err = MPI_Finalize();
    assert( err == 0 );
}
