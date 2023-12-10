// Given a file with a list of strings that contain letters and 2 numbers:
//  1. Find the individual numbers in each string
//  2. Convert the numbers to integers based on the order they appear in the string ("1abc2" -> 12)
//  3. Add the numbers of all strings together
//  4. Print the sum of all numbers

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

/// @brief Determines if a string can be parsed as an int
/// @param str The string to parse
/// @return True if an int can be parsed from the string, false otherwise
bool isValidInt(const std::string &str)
{
    try
    {
        std::stoi(str);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

/// @brief Uses a map to filter strings for word-forms of numbers, then returns those numbers.
/// @param str A string to filter for numbers
/// @return The parshed number if one was found or -1 if none
int isValidWord(const std::string &str)
{
    std::unordered_map<std::string, int> wordToNumberMap = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

    std::string lowercaseStr;
    for (char c : str)
    {
        lowercaseStr += tolower(c);
    }

    for (const auto &entry : wordToNumberMap)
    {
        if (lowercaseStr.find(entry.first) != string::npos)
        {
            return entry.second;
        }
    }
    return -1;
}

/// @brief Takes a string, and if the string contains the word of a number, return that number,
/// @param word String to parse
/// @return Character of the number
char wordToNumberToChar(const string &word)
{
    int wordToNum = isValidWord(word);
    if (wordToNum >= 0)
    {
        string numString = to_string(wordToNum);
        char num = numString[0];
        return num;
    }
    return '!';
}

int main()
{
    int calibration = 0;

    // Grabbing input from current directory
    std::ifstream file("input.txt");

    if (file.is_open())
    {
        // Grabbing current line
        string line;
        // Parsing current line
        while (getline(file, line))
        {
            string value;
            string word;

            for (char c : line)
            {
                string charString(1, c);
                if (isValidInt(charString))
                {
                    value.push_back(c);
                }
                else
                {
                    word.push_back(c);
                    char num = wordToNumberToChar(word);
                    if (num != '!')
                    {
                        value.push_back(num);
                        word.clear();
                        word.push_back(c);
                    }
                }
            }

            // Make a new string of the first and last values
            string values;
            values.push_back(value[0]);
            values.push_back(value[value.length() - 1]);

            // Add the new string to the calibration
            int parsed = stoi(values);
            calibration += parsed;
        }
        file.close();
    }
    else
    {
        cout << "Failed to open file! Please try again.";
        return 1;
    }

    cout << "Final Calibration: " << calibration << endl;
    return 0;
}