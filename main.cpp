#include "headers.hpp"

int myRank;
int nbTasks;

int main(int argc, char *argv[])
{
	cout.precision(2);

    // 1. Initialize MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);
    MPI_Comm_size(MPI_COMM_WORLD, &nbTasks);

	Problem p;

	//writeData(p, "benchmark/example5.txt");

    int n = 18;                             // taille de la matrice
    Tests(p, 3, n);
    //writeData(p, "benchmark/exemple6.txt");
    //readData(p, "benchmark/example2.txt");

    // TestBLAS(p);

    int m = 18, jj = 1, maxiter = 100;
    double tol = 1e-18;
    Matrix Vm;
    Vector LmbdApp;

    TestERAM(p, LmbdApp, Vm, m, jj, tol, maxiter);
    

    // 3. Finilize MPI
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();

	return 0;
}