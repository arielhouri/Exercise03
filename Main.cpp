//
// Created by ariel on 7/22/2022.
//

#include "Main.h"
#include <fstream>
#include <string>

vector<Iris> setup(fstream fstream);

int main(int argc, char *argv[]) {
    int k = stoi(argv[argc - 1]); // The amount of elements that the classifier will use.
    fstream fin;
    fin.open("classified.csv", ios::in); // Opens the data-file.
    vector<Iris> flowers = Main::setup(fin);


}


vector<Iris> Main::setup(fstream fin) {
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
            switch (i) {
                case 0:
                    type = word;
                    break;
                case 1:
                    bottomWidth = stoi(word);
                    break;
                case 2:
                    bottomLength = stoi(word);
                    break;
                case 3:
                    topWidth = stoi(word);
                    break;
                case 4:
                    topLength = stoi(word);
                    break;
                default:
                    break;
                }
        }
        Iris i(type, topLength, topWidth, bottomLength, bottomWidth);
        flowers.push_back(i);
    }
}
