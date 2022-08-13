# Exercise02
### by Ariel Houri & Yonatan Semidubersky

In this assignment we implemented two programs and combined them with the Classifier that we created in the first exercise. The first program that we created is a Client program, and the second is a Server program.
The Client is in charge of gathering the data about the unclassified irises from a given path and sending it to the Server (Using TCP). After the Client gets the classified data back from the Server, it needs to save it to a given path.
The Server's task is to get the data from the Client (using TCP that we implemented in the Server's code), classify it (using the classifier that we implemented in the first assignment with a Euclidean metric) and send it back to the user.


## Instruction:
This program is separated into two parts, The Server and the Client. You need two run them separately and simultaneously.
1. Compile the code using the following command: `g++ -std=c++11 *.cpp`
2. Run the Server, The server does not get any arguments.
3. Run the Client. You need to send two arguments, The first is the address of the file that contains the Irises' data that need to be classified and the second is the address of the file that you want to output to be in.
4. The output of the program will be in the given file (That was given in the arguments of the Client).
- If an error occurs while working with the sockets, an error massage will be printed into the console.
## The Algorithm:
The classification itself  and how it works is written in the [last assignment](https://github.com/arielhouri/Exercise01#readme). In this section we will explain only how the Server and the Client work and the relationship between them.
When the Server initializes, it creates its database (from a file named `classified.csv`) and then creates a socket and starts listening. Once the Client program starts running and the connection with the Server is established, The Client gets the data about the unclassified-flowers from the given address and sends the data to the Server and waits. Then, the Server processes the data and classifies the flowers using the classifier that we made in the last assignment. After the Irises are classified, the server sends the types of the Irises back to the Client. Then, the Client prints the types to the given address. 
### notes:
- The sizes of the buffers for the transferred data is `4096 bytes`.
- The port that the server used for its socket is `56789`.
- The Communication Protocol that we used is [`TCP`](https://he.wikipedia.org/wiki/Transmission_Control_Protocol).
- The value that we chose for the classifier is `k=5`.
- The ....
