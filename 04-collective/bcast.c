#include<mpi.h>
#include<stdio.h>

int main(){
    int rank;
    // Init
    MPI_Init(NULL, NULL);
    // Dapatkan ID rank
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    int root_rank = 0;

    if(rank == 0){
        int data[5] = {4,5,6,7,8};
        MPI_Bcast(data, 5, MPI_INT, root_rank, MPI_COMM_WORLD );
    }
    else{
        int terima[5];
        MPI_Bcast(terima, 5, MPI_INT, root_rank, MPI_COMM_WORLD );
        int sum = 0;
        int i=0;
        for(i=0;i<5;i++){
            sum = sum + terima[i];
        }
        printf("Rank %d hasil %d\n", rank, sum);
    }

    // Finalize
    MPI_Finalize();
}