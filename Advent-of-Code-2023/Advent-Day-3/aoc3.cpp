
/*
    * Given a file with 140 lines, each being 140 characters, I need to find a way to parse out any numbers that are
    * adjacent to any symbol that isn't a period(.) Adjacency should also consider diagonals.
    * 
    * Here's the example:
        467..114..
        ...*......
        ..35..633.
        ......#...
        617#......
        .....+.58.
        ..592.....
        ......755.
        ...$.*....
        .664.598..
    * I have multiple problems I need to solve my way through. First: I need to be able to parse numbers out of the strings.
    * Second, I need to find those numbers in the inputs, find their co-ords, and determine if anything near them are symbols.
    * Idea: I create a collection of every symbol and it's co-ords. 
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Point {
    public:
        int x;
        int y;

        Point(int xcord, int ycord) {
            this->x = xcord;
            this->y = ycord;
        }
};

int main() {
    std::ifstream file("input.txt");

    vector<string> grid;
    vector<Point> symbols;

    if(file.is_open()) {
        string line;

        while(getline(file, line)) {
            grid.push_back(line);

        }
    }
}