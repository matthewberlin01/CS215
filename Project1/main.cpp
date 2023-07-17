#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string getFileName(){
    string fileName;

    getline(cin, fileName);
    return fileName;
}

bool isAlpha(char input){
    bool alpha = false;
    if(isalpha(input)){
        alpha = true;
    }
    return alpha;
}

bool isLower(char input){
    bool lower = false;
    if(isAlpha(input)){
        if(tolower(input) == input){
            lower = true;
        }
    }
    return lower;
}

bool isVowel(char input){
    bool vowel = false;

    if((tolower(input) == 'a') || (tolower(input) == 'e') || (tolower(input) == 'i') || (tolower(input) == 'o')  || (tolower(input) == 'u')){
        vowel = true;
    }
    return vowel;
}

bool isDigit(char input){
    bool digit = false;

    if(isdigit(input)){
        digit = true;
    }
    return digit;
}

void printReport(const string& input, bool valid){
    if(valid){
        cout << "The variable name - " << input << " - is valid." << endl;
    }
    else{
        cout << "The variable name - " << input << " - is invalid." << endl;
    }

}

void getCount(string& inputText,  int& vowels, int& consonants, int& digits, int& specials){
    string inputFileName;
    string lastText;

    for(char i : inputText){
        if(isAlpha(i)){
            if(isVowel(i)){
                vowels++;
            }
            else{
                consonants++;
            }
        }
        else if(isDigit(i)){
            digits++;
        }
        else{
            specials++;
        }
    }
}

bool TestValidity(string inputText ,int vowels, int consonants, int digits, int specials){
    bool valid = false;
    if((vowels > 0 || consonants > 0) && (digits == 0) && (specials == 0)){
        valid = true;
    }
    if(!(isLower(inputText.at(0)))){
        valid = false;
    }
    return valid;
}

int main() {
    string inputFileName;
    string inputText;
    string lastText;
    bool valid;
    int vowels = 0;
    int consonants = 0;
    int digits = 0;
    int specials = 0;
    ifstream inFile;
    inputFileName = getFileName();

    inFile.open(inputFileName);

    if(!inFile){
        cout << "Could not open file " << inputFileName << endl;
        exit(1);
    }
    while(!inFile.eof()){
        inFile >> inputText;
        getCount(inputText, vowels, consonants, digits, specials);
        valid = TestValidity(inputText, vowels, consonants, digits, specials);
        if(inputText != lastText) {
            printReport(inputText, valid);
        }
        vowels = 0;
        consonants = 0;
        digits = 0;
        specials = 0;
        lastText = inputText;
    }
    inFile.close();
    return 0;
}

