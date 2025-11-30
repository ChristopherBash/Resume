// experimentaltextsearch2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <limits> // Needed for tolower

using namespace std;

// Function to split keywords (unchanged, but necessary)
vector<string> split_keywords(const string& keywords_input) {
    vector<string> keywords;
    stringstream ss(keywords_input);
    string keyword;

    while (ss >> keyword) {
        keywords.push_back(keyword);
    }
    return keywords;
}

int main()
{
    string filename;
    string keywords_input;
    string repeatAnswer;
    bool repeat_search = false;

    // The entire core search logic is placed inside a do-while loop
    do {
        // --- 1. Reset variables for the new search ---
        repeat_search = false; // Reset the loop flag

        // --- 2. User Input ---
        cout << "\n=======================================" << endl;
        cout << "please enter the file path for the text file: " << endl;
        // Use getline() for paths, as they may contain spaces
        getline(cin, filename);

        cout << "please input keyword(s) to be searched (separated by spaces):" << endl;
        getline(cin, keywords_input);

        vector<string> keywords = split_keywords(keywords_input);

        if (keywords.empty()) {
            cout << "Error: no keyword entered. Restarting prompt..." << endl;
            repeat_search = true; // Stay in the loop to ask for input again
            continue;
        }

        // --- 3. File Handling and Search ---
        // Note: The ifstream object must be created/re-opened inside the loop!
        ifstream input_file(filename);

        if (!input_file.is_open()) {
            cout << "Error: Could not open file " << filename << ". Please check file path." << endl;

            // Set repeat_search to true to stay in the loop
            repeat_search = true;

            // Immediately clear the buffer before continuing to the next loop iteration
            // This is crucial because continue skips the cin.ignore() at the end
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Skip the rest of the search logic and jump to the do-while condition
            continue;
        }

        string line;
        int line_count = 0;
        int matches_found = 0;

        cout << "\n--- Search Results ---" << endl;

        // Read file line by line
        while (getline(input_file, line)) {
            line_count++;

            // Search for any keyword in the current line
            for (const string& keyword : keywords) {
                if (line.find(keyword) != string::npos) {

                    // Match found 
                    cout << "[line " << line_count << " found '" << keyword << "']:\n";
                    cout << "    " << line << "\n" << endl;
                    matches_found++;
                    break; // Move to the next line in the file
                }
            }
        }

        // --- 4. Summary ---
        input_file.close();

        cout << "\n--- Search Summary ---" << endl;
        if (matches_found == 0) {
            cout << "No matches found for your query." << endl;
        }
        else {
            cout << "Search found a total of " << matches_found << " matches." << endl;
        }

        // --- 5. Repetition Prompt ---
    ask_repeat: // Label for goto in case of file open error

        cout << "\nWould you like to repeat the search with different input? (Yes/No): ";

        // Use cin to read the answer
        if (cin >> repeatAnswer) {

            // Convert input to lowercase for reliable checking
            transform(repeatAnswer.begin(), repeatAnswer.end(), repeatAnswer.begin(),
                [](unsigned char c) { return std::tolower(c); });

            if (repeatAnswer == "yes" || repeatAnswer == "y") {
                repeat_search = true;
            }
            // else: repeat_search remains false, loop will exit
        }

        // Crucial: Clear the input buffer after using cin >> 
        // to prevent getline() from reading a leftover newline character in the next loop iteration.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (repeat_search); // Continue loop if repeat_search is true

    cout << "\nExiting program. Goodbye!" << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
