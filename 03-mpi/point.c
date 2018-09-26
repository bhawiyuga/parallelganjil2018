#include<mpi.h>
#include<stdio.h>

int main(){
    int rank;
    // Init
    MPI_Init(NULL, NULL);
    // Dapatkan ID rank
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    // Jika saya adalah ID rank 0
    if(rank == 0){
        int data = 10;
        MPI_Send(&data, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        printf("Rank %d mengirim data %d \n", rank, data);
    }
    // Else, jika saya ID rank 1
    else if(rank == 1){
        int data_terima = -1;
        MPI_Recv(&data_terima, 1, MPI_INT, MPI_ANY_SOURCE, 1, 
            MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        print("Rank %d Terima data %d \n", rank, data_terima);
    }
    MPI_Finalize();
}