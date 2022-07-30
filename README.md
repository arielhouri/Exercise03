# Exercise01
### by Ariel Houri & Yonatan Semidubersky

>The classification k-nearest neighbors algorithm (k-NN),
return a class membership.
An object is classified by a plurality vote of its neighbors,
with the object being assigned to the class most common among its k nearest neighbors. [wikipedia](https://en.wikipedia.org/wiki/K-nearest_neighbors_algorithm)

In this assignment, we implemented KNN Classifier for irises.
Given a set of data for an unclassified iris and a natural number k,
we determine his type using the KNN algorithm.

## Instruction:
The data must be arranged in this formation in the project's directory:
- classified.csv will contain the data of classified irises (The data and then the type of the iris).
- Unclassified.csv will contain the irises that we need to classify (only their data).
- The output will be in the following files: euclidean_output.csv, manhattan_output.csv, chebyshev_output.csv 
(according to the metric that was used in the algorithm). These files don't have to be cleared before starting the 
  algorithm (THey are cleared automatically).
- The program will be executed from the Main.cpp file.
## The Algorithm:
- The Main class is in charge of setting up the data, writing and reading from files.
- The Iris class stores data of specific flower.
- The ClassifierKNN class is in charge of arranging the data,
and process the input for the algorithm.
- IrisAndDistance is an object that stores an iris and his distance from the unclassified iris.
Also, it has a "quick-select" function for the KNN algorithm.