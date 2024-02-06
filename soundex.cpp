/*
 * TODO: remove and replace this file header comment
 * This is a .cpp file you will edit and turn in.
 * Remove starter comments and add your own
 * comments on each function and on complex code sections.
 */
#include <cctype>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "console.h"
#include "strlib.h"
#include "filelib.h"
#include "simpio.h"
#include "vector.h"
#include "SimpleTest.h"
#include "soundex.h"
using namespace std;

/* This function is intended to return a string which
 * includes only the letter characters from the original
 * (all non-letter characters are excluded)
 *
 * WARNING: The provided code is buggy!
 *
 * Add student test cases to identify which inputs to this function
 * are incorrectly handled. Then, remove this comment and
 * replace it with a description of the bug you fixed.
 */
string lettersOnly(string s) {
    string result = charToString(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (isalpha(s[i])) {
            result += s[i];
        }
    }
    return result;
}

string changeTonumbers(string name){
    string result;
    transform(name.begin(),name.end(),name.begin(),::toupper);
    result+=name[0];
    for(int i=1;i<name.length();i++){
        if(name[i]=='A'||name[i]=='E'||name[i]=='I'||name[i]=='O'||name[i]=='U'||name[i]=='H'||name[i]=='W'||name[i]=='Y'){
            result+='0';
        }
        else if(name[i]=='B'||name[i]=='F'||name[i]=='P'||name[i]=='V'){
            result+='1';
        }
        else if(name[i]=='C'||name[i]=='J'||name[i]=='G'||name[i]=='K'||name[i]=='Q'||name[i]=='X'||name[i]=='S'||name[i]=='Z'){
            result+='2';
        }
        else if(name[i]=='D'||name[i]=='T'){
            result+='3';
        }
        else if(name[i]=='L'){
            result+='4';
        }
        else if(name[i]=='M'||name[i]=='N'){
            result+='5';
        }
        else if(name[i]=='R'){
            result+='6';
        }
    }
    return result;
}


string remove_equal(string name){
    string result;
    for(int i=0;i<name.length();i++){
        if(name[i]!=name[i+1]){
            result=result+name[i];
            }
        }
    return result;
}

string complement_zero(string name) {
    int cnt = 0;
    string result;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] != ' ') {
            result += name[i];
            cnt++;
        }
    }
    while (cnt < 4) {
        result += '0';
        cnt++;
    }
    return result;
}

string remove_zero(string name) {
    string result;
    for (int i = 0; i < name.length(); i++) {
        if (name[i] != '0') {
            result += name[i];
        }
    }
    return result;
}

string remove_add(string name){
    string result;
    for(int i=0;i<4;i++){
        result+=name[i];
    }
    return result;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
string soundex(string s) {
    /* TODO: Fill in this function. */
    string letter_name=lettersOnly(s);
    string name=(remove_equal(remove_zero(changeTonumbers(letter_name))));
    if(name.length()<4){
        name=complement_zero(name);
    }
    else{
        name=remove_add(name);
    }
    return name;
}


/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
void soundexSearch(string filepath) {
    // This provided code opens the specified file
    // and reads the lines into a vector of strings
    ifstream in;
    Vector<string> allNames;

    if (openFile(in, filepath)) {
        allNames = readLines(in);
    }
    cout << "Read file " << filepath << ", "
         << allNames.size() << " names found." << endl;

    // The names read from file are now stored in Vector allNames

    /* TODO: Fill in the remainder of this function. */
}


/* * * * * * Test Cases * * * * * */

// TODO: add your STUDENT_TEST test cases here!

STUDENT_TEST("Testing functions lettersonly"){
    EXPECT_EQUAL(lettersOnly("Joe$4+=-:;`{]/<. Biden"), "JoeBiden");
}

STUDENT_TEST("Testing functions changeTonumbers"){
    EXPECT_EQUAL(changeTonumbers(remove_zero("Curie")),"C0600");
}

STUDENT_TEST("Testing functions remove_equal"){
    EXPECT_EQUAL(remove_equal("3344"),"34");
}

STUDENT_TEST("Testing functions remove_zero"){
    EXPECT_EQUAL(remove_zero("303404"),"3344");
}

STUDENT_TEST("Testing functions complement_zero"){
    EXPECT_EQUAL(complement_zero("C6"),"C600");
}

STUDENT_TEST("Testing functions remove_add"){
    EXPECT_EQUAL(remove_add("C4993f"),"C499");
}
/* Please not add/modify/remove the PROVIDED_TEST entries below.
 * Place your student tests cases above the provided tests.
 */

PROVIDED_TEST("Test exclude of punctuation, digits, and spaces") {
    string s = "O'Hara";
    string result = lettersOnly(s);
    EXPECT_EQUAL(result, "OHara");
    s = "Planet9";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "Planet");
    s = "tl dr";
    result = lettersOnly(s);
    EXPECT_EQUAL(result, "tldr");
}

PROVIDED_TEST("Sample inputs from handout") {
    EXPECT_EQUAL(soundex("Curie"), "C600");
    EXPECT_EQUAL(soundex("O'Conner"), "O256");
}

PROVIDED_TEST("hanrahan is in lowercase") {
    EXPECT_EQUAL(soundex("hanrahan"), "H565");
}

PROVIDED_TEST("DRELL is in uppercase") {
    EXPECT_EQUAL(soundex("DRELL"), "D640");
}

PROVIDED_TEST("Liu has to be padded with zeros") {
    EXPECT_EQUAL(soundex("Liu"), "L000");
}

PROVIDED_TEST("Tessier-Lavigne has a hyphen") {
    EXPECT_EQUAL(soundex("Tessier-Lavigne"), "T264");
}

PROVIDED_TEST("Au consists of only vowels") {
    EXPECT_EQUAL(soundex("Au"), "A000");
}

PROVIDED_TEST("Egilsdottir is long and starts with a vowel") {
    EXPECT_EQUAL(soundex("Egilsdottir"), "E242");
}

PROVIDED_TEST("Jackson has three adjcaent duplicate codes") {
    EXPECT_EQUAL(soundex("Jackson"), "J250");
}

PROVIDED_TEST("Schwarz begins with a pair of duplicate codes") {
    EXPECT_EQUAL(soundex("Schwarz"), "S620");
}

PROVIDED_TEST("Van Niekerk has a space between repeated n's") {
    EXPECT_EQUAL(soundex("Van Niekerk"), "V526");
}

PROVIDED_TEST("Wharton begins with Wh") {
    EXPECT_EQUAL(soundex("Wharton"), "W635");
}

PROVIDED_TEST("Ashcraft is not a special case") {
    // Some versions of Soundex make special case for consecutive codes split by hw
    // We do not make this special case, just treat same as codes split by vowel
    EXPECT_EQUAL(soundex("Ashcraft"), "A226");
}
