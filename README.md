# Exercise01
# Ariel Houri & Yonatan Semidubersky

the classification k-nearest neighbors algorithm (k-NN),
return a class membership.
An object is classified by a plurality vote of its neighbors,
with the object being assigned to the class most common among its k nearest neighbors. (wikipedia)

In this assignment, we implemented Classifier KNN for Iris,
given unclassified iris and k (number),
we evaluate his type.

# Instruction:
The data must be arranged in this formation in the project's directory:
- classified.csv will be the data of irises
- Unclassified.csv will be the irises to classify.
- The output will be in: euclidean_output.csv, manhattan_output.csv, chebyshev_output.csv 
(according to the metric).
- The program must ber executed from Main.cpp
# The Algorithm:
- The main class is in charge of setting the data, writing and reading from files.
- The flower class store data on specific flower.
- The ClassifierKNN is in charge of arranging the data,
and process input for finding the algorithm.
- IrisAndDistance is an object to store iris and his distance from the unclassified iris.
Also, it has a function that implement "quick-select" for the KNN.