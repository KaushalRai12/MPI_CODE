#include <mpi.h> // Include the MPI library for parallel computing
#include <stdio.h> // Include the standard input/output library
#include <string.h> // Include the string library for string manipulation

int main(int argc, char** argv) {
    const int MAX_STRING = 100; // Define the maximum length of the greeting string
    char greeting[MAX_STRING]; // Declare a character array to store the greeting
    int comm_sz; // Declare a variable to store the number of processes
    int my_rank; // Declare a variable to store the rank of the current process

    MPI_Init(&argc, &argv); // Initialize the MPI environment
    MPI_Comm_size(MPI_COMM_WORLD, &comm_sz); // Get the total number of processes
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank); // Get the rank of the current process

    if (my_rank != 0) { // If the current process is not the root process
        sprintf(greeting, "Greetings from process %d of %d!", my_rank, comm_sz); // Create a greeting message with the process rank and total number of processes
        MPI_Send(greeting, strlen(greeting)+1, MPI_CHAR, 0, 0, MPI_COMM_WORLD); // Send the greeting message to the root process
    } else { // If the current process is the root process
        printf("Greetings from process %d of %d!\n", my_rank, comm_sz); // Print a greeting message from the root process
        for (int q = 1; q < comm_sz; q++) { // Iterate over all the other processes
            MPI_Recv(greeting, MAX_STRING, MPI_CHAR, q, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE); // Receive the greeting message from each process
            printf("%s\n", greeting); // Print the received greeting message
        }
    }

    MPI_Finalize(); // Finalize the MPI environment
    return 0; // Exit the program
}
