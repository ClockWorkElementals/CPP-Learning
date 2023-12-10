
/*
    Input game with Shrodinger's Cat elements to it
    Each line starts with Game ID:
    Rest of file is # ColorName, or # ColorName; where semi-colons indicate the start of a new round
    If at any point, a Game round contains 12 Red, 13 Green, or 14 Blue, that Game becomes invalid.

    OOP Approach
        Class: BagGame
            int id
            int highestRed
            int higestBlue
            int highestGreen
            calculated bool IsValidGame

    I know that the start of each new line is a game object. My goal is to parse those lines as fast as possible to determine validity.
    Do I necessarily care for round markers? No, not for part 1 at least.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

const int RED = 12;
const int GREEN = 13;
const int BLUE = 14;

const int START_POS_ID_SINGLE_DIGIT = 7;
const int START_POS_ID_DOUBLE_DIGIT = 8;
const int START_POS_ID_TRIPLE_DIGIT = 9;

class BagGame {
    public:
        int id;
        int highestRed = 0;
        int highestGreen = 0;
        int highestBlue = 0;
        bool isValidGame = true;

        BagGame(int id) {
            this->id = id;
        }

        void addRed(int red) {
            highestRed = std::max(highestRed, red);
            if (highestRed > RED) {
                isValidGame = false;
            }
        }

        void addGreen(int green) {
            highestGreen = std::max(highestGreen, green);
            if (highestGreen > GREEN) {
                isValidGame = false;
            }
        }

        void addBlue(int blue) {
            highestBlue = std::max(highestBlue, blue);
            if (highestBlue > BLUE) {
                isValidGame = false;
            }
        }

        void addColor(string color, int num) {
            if (color == "red") {
                addRed(num);
            } else if (color == "green") {
                addGreen(num);
            } else if (color == "blue") {
                addBlue(num);
            }
        }

        void parseRound(string round) {
            highestRed = 0;
            highestGreen = 0;
            highestBlue = 0;

            //Split round into substrings 
            string numberSubString;
            string colorSubString;

            for (int i = 0; i < round.length(); i++) {
                if(isdigit(round[i])) {
                    numberSubString.push_back(round[i]);
                }
                else if (isalpha(round[i])) {
                    colorSubString.push_back(round[i]);
                }
                else if (round[i] == ',' || round[i] == ';') {
                    addColor(colorSubString, stoi(numberSubString));

                    if(!isValidGame) {
                        return;
                    }
                    
                    //Resetting substrings
                    numberSubString = "";
                    colorSubString = "";
                }
                else if (i == round.length() - 1) {
                    colorSubString.push_back(round[i]);
                    addColor(colorSubString, stoi(numberSubString));
                }
            }
        }

        void parseLine(string line) {
            string subLine;
            
            //Parsing out the GAME #: part of the line
            if (id < 10) {
                subLine = line.substr(START_POS_ID_SINGLE_DIGIT);
            } else if (id < 100) {
                subLine = line.substr(START_POS_ID_DOUBLE_DIGIT);
            } else {
                subLine = line.substr(START_POS_ID_TRIPLE_DIGIT);
            }

            //Creating substrings that split the line based on , or ;
            string subString;
            for (int i = 0; i < subLine.length(); i++) {
                subString.push_back(subLine[i]);
                if (subLine[i] == ';') {
                    parseRound(subString);
                    
                    if(!isValidGame) {
                        return;
                    }

                    //Resetting subString
                    subString = "";
                }
            }
        }
};

class BagGameMinColors {
    public:
        int id;
        int highestRed = 0;
        int highestGreen = 0;
        int highestBlue = 0;

        BagGameMinColors(int id) {
            this->id = id;
        }

        void addRed(int red) {
            highestRed = std::max(highestRed, red);
        }

        void addGreen(int green) {
            highestGreen = std::max(highestGreen, green);
        }

        void addBlue(int blue) {
            highestBlue = std::max(highestBlue, blue);
        }

        int powerOfColors() {
            return highestRed * highestGreen * highestBlue;
        }

        void addColor(string color, int num) {
            if (color == "red") {
                addRed(num);
            } else if (color == "green") {
                addGreen(num);
            } else if (color == "blue") {
                addBlue(num);
            }
        }

        void parseRound(string round) {

            string numberSubString;
            string colorSubString;

            for (int i = 0; i < round.length(); i++) {
                if(isdigit(round[i])) {
                    numberSubString.push_back(round[i]);
                }
                else if (isalpha(round[i])) {
                    colorSubString.push_back(round[i]);
                }
                else if (round[i] == ',' || round[i] == ';') {
                    addColor(colorSubString, stoi(numberSubString));
                    
                    //Resetting substrings
                    numberSubString = "";
                    colorSubString = "";
                }
            }
        }

        void parseLine(string line) {
            string subLine;
            
            //Parsing out the GAME #: part of the line
            if (id < 10) {
                subLine = line.substr(START_POS_ID_SINGLE_DIGIT);
            } else if (id < 100) {
                subLine = line.substr(START_POS_ID_DOUBLE_DIGIT);
            } else {
                subLine = line.substr(START_POS_ID_TRIPLE_DIGIT);
            }

            //Creating substrings that split the line based on , or ;
            string subString;
            for (int i = 0; i < subLine.length(); i++) {
                subString.push_back(subLine[i]);
                if (subLine[i] == ';') {
                    parseRound(subString);
                    
                    //Resetting subString
                    subString = "";
                }
            }
        }
};


int main() {
    std::ifstream file("input.txt");
    
    //Sum of all valid game IDs
    int validIds = 0;
    int powerOfColors = 0;

    if (file.is_open()) {
        //Line always starts with "Game #:"
        string line;

        while (getline(file, line)) {
            // Grabbing game ID
            string idString;
            
            //start at 5 to skip "Game " and go until :
            for (int i = 5; i < line.length(); i++) {
                if (line[i] == ':') {
                    break;
                }
                idString.push_back(line[i]);
            }

            //Convert idString to int and create new BagGame
            int id = stoi(idString);
            BagGame game(id);
            game.parseLine(line);

            if (game.isValidGame) {
                validIds += id;
                cout << "Game " << id << " is valid" << endl;
            }

            //Part 2
            BagGameMinColors gameMinColors(id);
            gameMinColors.parseLine(line);
            powerOfColors += gameMinColors.powerOfColors();

        }

        //Printing out the sum of all valid game IDs
        cout << validIds << endl;
        cout << powerOfColors << endl;
    }
}