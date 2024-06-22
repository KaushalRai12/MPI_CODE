# MPI Point-to-Point Communication

This README provides an overview of MPI point-to-point communication and how messages can be passed between threads using MPI.

## What is MPI?

MPI (Message Passing Interface) is a standard library specification for message passing between parallel processes. It is commonly used in high-performance computing to enable communication and coordination between multiple processes running on different nodes.

## Point-to-Point Communication

MPI provides several functions for point-to-point communication, allowing messages to be sent and received between specific processes. The two main functions for point-to-point communication are `MPI_Send` and `MPI_Recv`.

### MPI_Send

The `MPI_Send` function is used to send a message from one process to another. It takes the following parameters:

- `buf`: A pointer to the data to be sent.
- `count`: The number of elements to send.
- `datatype`: The datatype of the elements being sent.
- `dest`: The rank of the destination process.
- `tag`: An optional tag to identify the message.

### MPI_Recv

The `MPI_Recv` function is used to receive a message sent by another process. It takes the following parameters:

- `buf`: A pointer to the buffer where the received data will be stored.
- `count`: The maximum number of elements to receive.
- `datatype`: The datatype of the elements being received.
- `source`: The rank of the source process.
- `tag`: An optional tag to filter incoming messages.

## Passing Messages between Threads

To pass a message from one thread to another using MPI, you need to specify the source and destination ranks in the `MPI_Send` and `MPI_Recv` functions. Each thread should have a unique rank within the MPI communicator.

For example, to send a message from thread 0 to thread 1, you can use the following code:
