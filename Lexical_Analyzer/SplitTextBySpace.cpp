#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream input("SplitText.txt");
    string word;

    //Check if the file is succesfully opened 
    if(!input){
        cerr << "Error opening file" << endl;
        return 1;
    }

    //Read the file word by word, seperated by spaces
    while(input >> word){
        cout << word << '\n';
    }

    input.close(); //Close the file
    return 0;
}