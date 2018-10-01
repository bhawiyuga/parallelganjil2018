#include<mpi.h>
#include<stdio.h>
#include <stdlib.h>

int main(){
    // Inisiasi random

    int rank;
    // Init
    MPI_Init(NULL, NULL);
    // Dapatkan ID rank
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    //...Your code here...
    int root_rank = 0;
    long t=time(0);
    srand(t);
    int angka_random = rand()%20;
    int hasil_akhir = 0;

    MPI_Reduce(&angka_random, &hasil_akhir, 1, MPI_INT,
        MPI_SUM, root_rank, MPI_COMM_WORLD);
    
    printf("Rank %d mengirimkan angka %d %lu\n", rank, angka_random, t);

    if(rank == root_rank){
        printf("Hasilnya adalah %d \n", hasil_akhir);
    }
    

    // Finalize
    MPI_Finalize();
}