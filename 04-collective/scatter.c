#include<mpi.h>
#include<stdio.h>

int main(){
    int rank;
    // Init
    MPI_Init(NULL, NULL);
    // Dapatkan ID rank
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    //...Your code here...
    int u[16] = {12,4,6,1,9,34,56,23,12,25,9,3,8,3,9,10};
    int data[4];
    int root_rank = 0;
    MPI_Scatter(u, 4, MPI_INT, data, 4, MPI_INT, 
        root_rank, MPI_COMM_WORLD  );
    printf("Rank %d ", rank);
    int i =0;
    for(i=0;i<4;i++){
        printf("%d ", data[i]);
    }
    printf("\n");
    // Finalize
    MPI_Finalize();
}