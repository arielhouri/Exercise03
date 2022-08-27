# Exercise03
### by Ariel Houri & Yonatan Semidubersky

In this assignment we implemented a server and a Client programs and combined them with the Classifier that we created in the 
first assignment. The server has a CLI and can classify data using the KNN algorithm with to given data and 3 
different metrics. The server supports any king of objects and data that has 10 or less features (which are 
arguments from type Double). As mentioned earlier, the server has a CLI and supports the following operations:
1. Uploading data (classified and unclassified objects) to the server.
2. Print the current values that are used in the KNN algorithm (the value of K and the metric).
3. Classify the data. 
4. Print the classified objects' types to the screen.
5. Save the classified objects' types to a file on the client's computer.
6. Print the [confusion matrix](https://en.wikipedia.org/wiki/Confusion_matrix) of the classifier.
7. Exit the program.


## Running Instruction: - Need to be updated.
This program is separated into two parts, The Server and the Client. You need to run them separately and simultaneously.
1. Compile the code using the following command: `g++ -std=c++11 *.cpp`
2. Run the Server, The server does not get any arguments.
3. Run the Client. You need to send two arguments, The first is the address of the file that contains the Irises' data that need to be classified and the second is the address of the file that you want to output to be in.
4. The output of the program will be in the given file (That was given in the arguments of the Client).
5. After the Client disconnects from the Server, the Server waits for a new Client. In order to run a new Client on the same Server, You need to Run the Client (with the two arguments, like in step no. 3) again.
- If an error occurs while working with the sockets, an error message will be printed into the console.
## The Algorithm: - Need to be updated.
The classification precces itself and how it works is written in the [last assignment](https://github.com/arielhouri/Exercise01#readme). In this section we will explain only how the Server and the Client work and the relationship between them.
When the Server initializes, it creates its database (from a file named `classified.csv`) and then creates a socket and starts listening. Once the Client program starts running and the connection with the Server is established, The Client gets the data about the unclassified-classifiableObjectsVector from the given address and sends the data to the Server and waits. Then, the Server processes the data and classifies the classifiableObjectsVector using the classifier that we made in the last assignment. After the Irises are classified, the server sends the types of the Irises back to the Client. Then, the Client prints the types to the given address. After the Client disconnects, the Server waits for another Client to connect.

### note anout implemntion 
- In order to support reading from files, writing to file and standard input and output, we send two messages from the server each time.
The first one is instruction and the other is the message.
$exit$ - stops the communication.
$print$ - print the message.
$print&Num$ - printing the message and reciving a number from the client.
$print&upload$ - printing the message and upload a file (the client recive path from the user and send the data).
$print&string$ - printing the message and sending string from user.
$print&download$ - printing the message to download to file (given path from the user).
### notes: - Need to be updated.
- The sizes of the buffers for the transferred data is `4096 bytes`.
- The port that is being used in the program is `56789`. (If you stop the code and want to re-run you have to wait a 
  few moments so the data of the port and socket will be cleared by the kernel).
- The Communication Protocol that we used is [`TCP`](https://he.wikipedia.org/wiki/Transmission_Control_Protocol).
- The value that we chose for the KNN-classifier is `k=7` (because it's efficient and also good enough statistical estimate that KNN is based of).
