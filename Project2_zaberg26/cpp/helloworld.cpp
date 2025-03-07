/*
 * Basic program for C++
 * User inputs a string
 * Program prints a random string char by 
 * Randomizes char, letter by letter, until it reaches the original string
 */

 #include <iostream>
 #include <string>
 #include <stdlib.h>
 #include <random>
 #include <thread>
 #include <chrono>


 char randomChar() {
    return 'a' + rand() % 26;
 }

 // I would comment more but this is pretty self explanatory
 // really simple program
 int main() {
    // initialize string
    std::string s;
    std::cout << "Enter a string: ";
    // set string to user input
    std::getline(std::cin, s);

    // set cur to s
    std::string cur;
    //initialize vars for loop
    char randchar;
    int count;

    // loop chars in s
    for (char c : s) {
        count = 0;
        while (randchar != c) {
            count += 1;
            // looks cooler if it sleeps
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            randchar = randomChar();
            // rand char can never be a space of capital letter
            // because I just want it to be cool looking
            // I decied to just set it to c if it takes more than 15 loops
            // so that way you can use any characters you want but its still
            // really simple
            if (count == 15) {
                randchar = c;
            }
            std::cout << cur + randchar << std::endl;
        }
        cur += randchar;
    }
    return 0;
 }