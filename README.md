# Exercise03
### by Ariel Houri & Yonatan Semidubersky

In this assignment we implemented a server and a Client programs and combined them with the Classifier that we created in the 
first assignment. The server is based of "Classifier KNN" algorithm:
<div id="header" align="center">
  <img src="http://res.cloudinary.com/dyd911kmh/image/upload/f_auto,q_auto:best/v1531424125/KNN_final_a1mrv9.png" width="500"/>
  <div><b>Classifier KNN</b></div>
</div>
The server has a Command-Line Interface and can classify data using the KNN algorithm with to given data and 3 
different metrics. The server supports any king of objects and data that has 10 or less features (which are 
arguments from type Double). As mentioned earlier, the server contains a CLI and supports the following operations:
<div id="header" align="center">
  <img src="https://user-images.githubusercontent.com/109608321/188070467-ca79c692-66de-48b5-9e98-dde1e6f1919e.png" width="500"/>
  <div><b>menu</b></div>
</div>
1. Uploading data (train and test files) to the server./n
2. Print the current values that are used for the KNN algorithm (the value of K and the metric) and change them.
3. Classify the data.
4. Print the classified objects' types to the screen.
5. Save the classified objects' types in a file on the client's computer.
6. Print the [confusion matrix](https://en.wikipedia.org/wiki/Confusion_matrix) of the classifier according to  the given data.
7. Exit the program.
<div id="header" align="center">
  <img src="https://user-images.githubusercontent.com/109608321/188070477-124147f3-f3fa-4380-baf9-4cab8e0e3690.png" width="500"/>
  <div><b>Confusion Matrix</b></div>
</div>


## Running Instruction:
This program is separated into two parts, The Server and the clients. You need to run them separately and simultaneously (we also support multithreading so few clients can run concurrently).
1. Compile the code using the following command: `g++ CLassifier/*.cpp Client/*.cpp Commands/*.cpp IOs/*.cpp Server/*.cpp Threads/*.cpp -std=c++11`. You can also compile every folder separately with the following command: `g++ `folder`/*.cpp -std=c++11`.
2. Run the Server, The server does not get any arguments.
3. Within `60 seconds (timeout)`,Run the client. The client does not get any arguments as well.
  - You can run the client program as much as you want because the server supports more than one client at a time. the server does have a timeout, after 1 minute (60 seconds) from the last time that a client connected to the server, the server won't accept and serve new clients.
4. Then, as a client, you can use the server with your console. The list of available functions are shawn in the console and were mentioned above.
5. After you finished using the server, in order to disconnect, you should choose option number 7 (also shawn in the console). If you pick a number that isn't on the list, 9 for example, the connection will be closed automatically (like if you were to pick the number 7).
- If an error occurs while working with the sockets, an error message will be printed into the **server's** console or into the **client's** console, depends on where the error occured.
## The Algorithm: 
The classification process itself and how it works is written in the [last assignment](https://github.com/arielhouri/Exercise01#readme). In this section we will explain only how the Server and the Client work and the relationship between them.
When the Server initializes, it creates its database (from a file named `classified.csv` given to the server as a "train") and then creates a socket and starts listening. Once the Client program starts running and the connection with the Server is established, The Client gets the data about the unclassified-classifiableObjectsVector from the given address and sends the data to the Server and waits. Then, the Server processes the data and classifies the classifiableObjectsVector using the classifier that we made in the last assignment. After the Irises are classified, the server sends the types of the Irises back to the Client. Then, the Client prints the types to the given address. After the Client disconnects, the Server waits for another Client to connect.

## Sending and Receiving data:
In order to support reading from files, writing to file and standard input and output, we send two messages from the server each time.
The first one is instruction and the other is the message.
* `$exit$` - stops the communication.
* `$print$` - print the message.
* `$print&Num$` - printing the message and receiving a number from the client.
* `$print&upload$` - printing the message and upload a file (the client receive path from the user and send the data).
* `$print&string$` - printing the message and sending string from user.
* `$download$` - download the message to file (given path from the user).
### notes:
- The size of the server's buffer for the transferred data is `8192 bytes`.
- The size of the client's buffer for the transferred data is `4096 bytes`.
- The port that is being used in the program is `40023`. (If you stop the code and want to re-start you have to wait a 
  few moments so the data of the port and socket will be cleared by the kernel, otherwise, the error: `Error binding socket` will be printed to the server's console).
- The Communication Protocol that we used is [`TCP`](https://he.wikipedia.org/wiki/Transmission_Control_Protocol).
- The timeout time of the server is `60 seconds`. The timer resets everytime a new client connects to the server.
- We builded the server using a uniqe threads structure in order to support the features above (timeout for stop listening to new clients but still running the already existing clients).
