#include<stdio.h>
#include<mpi.h>

int main(){
    // Variabel untuk menampung id rank dan jumlah rank
    int rank, size;
    // Inisiasi MPI
    MPI_Init(NULL, NULL);
    // Get ID rank
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    // Get jumlah rank
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    // Print hasilnya
    printf("ID rank %d dari %d rank\n", rank, size);
    // Akhiri MPI
    MPI_Finalize();
}