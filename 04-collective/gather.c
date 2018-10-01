#include<mpi.h>
#include<stdio.h>

int main(){
    int rank;
    // Init
    MPI_Init(NULL, NULL);
    // Dapatkan ID rank
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    int penampung[6];
    //...Your code here...
    if(rank == 0){
        int data[2] = {2,3};
        MPI_Gather(data, 2, MPI_INT,penampung,2, 
            MPI_INT, 0, MPI_COMM_WORLD);
        printf("Rank 0 : ");
        int i=0;
        for(i=0;i<6;i++){
            printf("%d ", penampung[i]);
        }
        printf("\n");
    }
    else if(rank == 1){
        int data[2] = {4,5};
        MPI_Gather(data, 2, MPI_INT,penampung,2, 
            MPI_INT, 0, MPI_COMM_WORLD);
    }
    else if(rank == 2){
        int data[2] = {6,7};
        MPI_Gather(data, 2, MPI_INT,penampung,2, 
            MPI_INT, 0, MPI_COMM_WORLD);
    }


    // Finalize
    MPI_Finalize();
}