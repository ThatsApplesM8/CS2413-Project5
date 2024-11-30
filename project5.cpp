#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    //read the name of the file ./a.out < filename.txt
    string input;   // create a string to store the input
    getline(cin, input);    // get the input from the user, which is the whole line of the file
    
    unordered_map<string, int> myToken; // generated a map to store the tokens and their frequencies
    size_t pos = 0; // create a variable to store the position of the token
    size_t end = input.find(' ');   // store the token where the upcoming space is located in the string



    //get each token and store them in the unordered_map (or map) increment
    //its frequencies. You MAY be able to do myTokens[aToken]++. Work on this.
    while(end != string::npos) {    // while the end of the token is not the end of the string
        string aToken = input.substr(pos, end - pos);   // grab the whole string substring from where the position is to the end each iterated time - the position.
        myToken[aToken]++;      // implemented commented above for incrementationm myTokens[aToken]++
        pos = end + 1;  // update the new position to where the end was + 1
        end = input.find(' ', pos); // repeat the end now to find the next space
    }
    myToken[input.substr(pos)]++;   // increment the last token of the key being the last input substring from the last position to the end of the string

    //close the file (filename.txt)
    //sort the myTokens in the decreasing order of VALUE which is frequencies
    //print the KEYS in myTokens (which has been sorted)separated by a space.

    map<int, map<string, int>, greater<int>> sortedMap; // create a map to store the sorted tokens in descending order of frequency

    for(const auto& pair : myToken) {   // iterate through the myToken map
        sortedMap[pair.second][pair.first] = pair.second;   // store the sorted tokens in the sortedMap map
    }

    for(const auto& pair : sortedMap) {   // iterate through the sortedMap map to output the sorted key
        for(const auto& pair2 : pair.second) {
            std::cout << pair2.first << " ";
        }
    }

    cout << " ";    // print a space after the sorted tokens for the last key

    //after you printed the KEYS Do this
    std::cout << endl;
    std::cout << "**********" << endl;

    // for the inputs, continue the same process again, but through the sortedMap to cout the descending order.
    size_t pos2 = 0;        // create a variable to store the position of the token
    size_t end2 = input.find(' ');  // grab the index of the next space in the string

    while(end2 != string::npos) {
        int index = 0;  // create an index to store the position of the token

        string aToken = input.substr(pos2, end2 - pos2);    // grab the substring of the token from the position to the end of the string
        
        for(const auto& pair : sortedMap) { // nested loop to iterate through the sortedMap map
            for(const auto& pair2 : pair.second) {      // go through the second map of the sortedMap map
                if(pair2.first == aToken) {    // if the token is equal to the token in the sortedMap map
                    std::cout << index + 1 << " ";  // print the index + 1
                }
                index++;    // increment the index
            }
        }
        pos2 = end2 + 1;    // update the position to the end of the token + 1
        end2 = input.find(' ', pos2);   // find the next space in the string
    }

    // continue the same process as above, but for the last token
    int index2 = 0;

    string aToken = input.substr(pos2, end2 - pos2);
    
    for(const auto& pair : sortedMap) {
        for(const auto& pair2 : pair.second) {
            if(pair2.first == aToken) {
                std::cout << index2 + 1 << " ";
            }
            index2++;
        }
    }

    //Now open the filename.text file again for reading
    //Read token by token as you have done this before
    //each time you get a token, find its position in the myTokens (sorted
    //data structure and print the position followed by space

    std::cout << endl;

    return 0;
    
}

/* LLM & Github Documentation
    Prompt: "Generate an overview of unordered_map and map in C++" 
    Rationale: Using a new data structure concept in C++, I am unfamilar with how the unordered map inclusion is being used for the project. I asked Copilot to generate an overview of key concepts related to the 
    unordered_map and map in C++ to better understand how to implement the data structure in the project. Using Copilot information, I was able to gain sense of how to implement the unordered_map in the project and
    use towards how my code program should be structured, stored, and organized into my program from the given input files. 
    Incremental Development: The generated overview provided by Copilot helped me gain new insights on the unordered map, utilizing key methods and functions like .first, .second, and .find into my project.

    Prompt: "Describe size_t and its usage in C++"
    Rationale: ChatGPT generated the usage of size_t into the unorder_map program. I asked ChatGPT a problem dealing with storing managements of string and integers into the map. 
    ChatGPT resulted in the line code of size_t pos = 0; and size_t end = input.find(' ');. I was unfamiliar with the size_t data type and its usage in C++, resulting on the prompt for CoPilot to explain the reasonings (i.e., memory adaptation for integer storages
    for map and string).
    Incrememntal Development: The prompt and solution enabled me to understand the usage of size_t in C++ and how it is used to store the position of the token and the end of the token in the string. 
    The prompt showed me newer ideas on how store efficiencies in the program and how to store the position of the token in the string. It also gave me a better understanding on how size_t are being utilized and implemented amongst the unordered_map, sortedMap
    and the string input.

    Prompt: "Generate a solution to output the last token in the string"
    Rationale: I aimed to ask CoPilot towards this question due to a problem where for both my tokens from the unordered_map and sortedMap, I was unable to output the last token in the string. The solution showed me to generate 2 solutions 
    from the output. For the unordered_map, it was able to be implemented by using myToken[input.substr(pos)]++;. For the sortedMap, it was able to be implemented by using the nested loop to iterate through the sortedMap map and output the last token.
    Incremental Development: The solution provided by CoPilot helped me understand how to output the last token in the string for both the unordered_map and sortedMap. 

*/

/*  Specific Tests/Debugging
    Throughout the programming process, the program went very smoothly with majority clean and non-error code. The program was able to output the sorted tokens in its according descendingb order of frequency.
    I checked outputted statements for each accordinging to the expected file input and output. 
    The expected output was greaty achieved, however a problem aros by spacing issues in the output, specifically the dning part of the output where there is no space when the expected output should have a space.
    I simply implemented a cout << " "; to fix the spacing issue, resulting with the expected output.

*/