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
        int data[5] = {1,2,3,4,5};
        int hasil=0;
        MPI_Send(&data, 5, MPI_INT, 1, 1, MPI_COMM_WORLD);
        MPI_Recv(&hasil, 1, MPI_INT, MPI_ANY_SOURCE, 2, 
            MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Rank %d Hasil akhir %d\n", rank, hasil);
    }
    // Else, jika saya ID rank 1
    else if(rank == 1){
        int data_terima[5];
        MPI_Recv(&data_terima, 5, MPI_INT, MPI_ANY_SOURCE, 1, 
            MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        int i=0, sum=0;
        for(i=0;i<5;i++){
            sum = sum + data_terima[i];
            printf("Rank %d Terima data %d \n", rank, data_terima[i]);
        }
        MPI_Send(&sum, 1, MPI_INT, 0, 2, MPI_COMM_WORLD);
        //printf("Rank %d Terima data %d \n", rank, data_terima[i]);
        
    }
    MPI_Finalize();
}