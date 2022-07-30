//
// Created by Ariel Houri and yonatan on 7/22/2022.
//

#include "Main.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include "ClassifierKnn.hpp"


int main(int argc, char *argv[]) {
    int k = stoi(argv[argc - 1]); // The amount of elements that the classifier will use.
    // Opening the files for writing:
    fstream file1out;
    file1out.open("euclidean_output.csv", fstream::out | ofstream::trunc);
    fstream file2out;
    file2out.open("chebyshev_output.csv", fstream::out | ofstream::trunc);
    fstream file3out;
    file3out.open("manhattan_output.csv", fstream::out | ofstream::trunc);
    // Opening the file "unclassified.csv" for reading.
    fstream fin2;
    fin2.open("unclassified.csv", fstream::in); // Opens the unclassified-irises file.
    vector<Iris> flowers = Main::setup();
    if (k > flowers.size() || k <= 0) {
        cout << "Invalid value of k" << endl;
        cout << "There aren't enough irises in the database for this value of k." << endl;
        return 0;
    }
    string line;
    string word;
    while(getline(fin2, line)) {
        Iris i = Main::getIris(line); // The Iris that we need to classify.
        ClassifierKnn toClass(flowers,i,k);
        file1out << toClass.classifierEuclidean() << endl; // Creates the Euclidean-output file.
        file2out << toClass.classifierChebyshev() << endl; // Creates the Chebyshev-output file.
        file3out << toClass.classifierManhattan() << endl; // Creates the Manhattan-output file.
    }
    // Closing the input and output file streams:
    fin2.close();
    file3out.close();
    file1out.close();
    file2out.close();
}


vector<Iris> Main::setup() {
    fstream fin;
    fin.open("classified.csv", fstream::in); // Opens the classified-data file.
    string type; // The type of the flower.
    double topLength; // The length of the top leafs.
    double topWidth; // The width of the top leafs.
    double bottomLength; // The length of the bottom leafs.
    double bottomWidth; // The width of the bottom leafs.
    vector<Iris> flowers;
    string line;
    string word;
    while(getline(fin, line)){
        stringstream str(line);
        for(int i = 0; i < 5; i++) {
            getline(str, word, ',');
            switch (i + 1) {
                case 5:
                    type = word;
                    break;
                case 1:
                    bottomWidth = stod(word);
                    break;
                case 2:
                    bottomLength = stod(word);
                    break;
                case 3:
                    topWidth = stod(word);
                    break;
                case 4:
                    topLength = stod(word);
                    break;
                default:
                    break;
            }
        }
        Iris i(type, topLength, topWidth, bottomLength, bottomWidth);
        flowers.push_back(i);
    }
    fin.close();
    return flowers;
}

// A function that gets a string and takes the data from it, and converts in into an Iris object.
// The string has to bee in the following form: bottomwidth,bottomlength,topwidth,topLength
// The data is seperated by a comma, and the type of the new Iris will be: "Unclassified".
Iris Main::getIris(string& line) {
    stringstream str(line);
    double topLength; // The length of the top leafs.
    double topWidth; // The width of the top leafs.
    double bottomLength; // The length of the bottom leafs.
    double bottomWidth; // The width of the bottom leafs.
    string word;
    for(int i = 0; i < 4; i++) { // Gather the data about the flower from a sting.
        getline(str, word, ',');
        switch (i + 1) {
            case 1:
                bottomWidth = stod(word);
                break;
            case 2:
                bottomLength = stod(word);
                break;
            case 3:
                topWidth = stod(word);
                break;
            case 4:
                topLength = stod(word);
                break;
            default:
                break;
        }
    }
    // The creation of the Iris that we need to classify.
    Iris ir("Unclassified", topLength, topWidth, bottomLength, bottomWidth);
    return ir;
}
