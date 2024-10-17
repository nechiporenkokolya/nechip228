#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h> 

using namespace std;

const string RESET = "\033[0m";
const string GREEN = "\033[32m";
const string RED = "\033[31m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";

char getRandomDecoration() {
    int random = rand() % 10;
    if (random < 7) {
        return '*';
    }
    else {
        char decorations[] = { '@', '$', '%', '#' };
        return decorations[rand() % 4];
    }
}

void printLevel(const vector<vector<char>>& tree, int levels, int colorCycle) {
    string colors[] = { RED, YELLOW, BLUE };
    for (int i = 0; i < tree.size(); ++i) {
        for (int j = 0; j < tree[i].size(); ++j) {
            char ch = tree[i][j];
            if (ch == '*' || ch == ' ') {
                cout << GREEN << ch << RESET;
            }
            else {
                cout << colors[(colorCycle + rand() % 3) % 3] << ch << RESET;
            }
        }
        cout << endl;
    }
}

vector<vector<char>> generateTree(int levels) {
    int maxWidth = 2 * levels + 1;
    vector<vector<char>> tree;

    for (int level = 1; level <= levels; ++level) {
        int height = level + 1;
        for (int row = 1; row <= height; ++row) {
            vector<char> currentRow(maxWidth, ' ');
            int stars = 2 * row - 1;
            int spaces = (maxWidth - stars) / 2;

            for (int i = 0; i < stars; ++i) {
                currentRow[spaces + i] = getRandomDecoration();
            }
            tree.push_back(currentRow);
        }
    }

    int trunkHeight = 3;
    int trunkWidth = 2;
    int trunkSpaces = (maxWidth - trunkWidth) / 2;
    for (int i = 0; i < trunkHeight; ++i) {
        vector<char> trunkRow(maxWidth, ' ');
        for (int j = 0; j < trunkWidth; ++j) {
            trunkRow[trunkSpaces + j] = '*';
        }
        tree.push_back(trunkRow);
    }

    return tree;
}

void saveTreeToFile(const vector<vector<char>>& tree) {
    ofstream file("cristmas_tree.txt");
    for (const auto& row : tree) {
        for (char ch : row) {
            file << ch;
        }
        file << endl;
    }
    file.close();
    cout << "ялинку збережено у файл 'cristmas_tree.txt'" << endl;
}

int main() {
    srand(time(0));

    setlocale(LC_ALL, "ukr");
    system("chcp 65001");

    int levels;
    cout << "¬вед≥ть к≥льк≥сть р≥вн≥в дл€ €линки: ";
    cin >> levels;

    vector<vector<char>> tree = generateTree(levels);

    saveTreeToFile(tree);


    int cycle = 0;
    while (true) {
        printLevel(tree, levels, cycle);
        cycle++;
        Sleep(500);
        cout << "\033[H\033[J";
    }

    return 0;
}