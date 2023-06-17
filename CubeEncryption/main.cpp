#include "cube.h"

#include <iostream>
#include <sstream>
#include <string>

void encrypt(Cube*& cubes, int size, std::string commands)
{
    int amountOfIteration;
  
    std::stringstream ss(commands);/// Read words from the stringstream until a delimiter
    std::string buff;
   

    for (int i = 0; i < size; ++i) {
        std::getline(ss, buff, ':');
        if (buff[0] == 'L') {
            amountOfIteration = buff[1] - 48;
            while (amountOfIteration != 0) {
                cubes[i].L();
                --amountOfIteration;
            }
        }
        else if(buff[0] == 'R') {
            amountOfIteration = buff[1] - 48;
            while(amountOfIteration != 0) {
                cubes[i].R();
                --amountOfIteration;
            }
        }
        else if(buff[0] == 'U') {
            amountOfIteration = buff[1] - 48;
            while(amountOfIteration != 0) {
                cubes[i].U();
                --amountOfIteration;
            }
        }
        else if(buff[0] == 'D') {
            amountOfIteration = buff[1] - 48;
            while(amountOfIteration != 0) {
                cubes[i].D();
                --amountOfIteration;
            }
        }
        else {
            std::cout << "you enterd something wrong\n";
        }
        buff = "";
    }

    
}

void decrypt(Cube*& cubes, int size, std::string& key)
{ 

    int amountOfIteration;
    std::stringstream  ss(key);
    std::string buff;
    

    for (int i = 0; i < size; ++i) {
        std::getline(ss, buff, ':');
        if(buff[0] == 'L'){
            amountOfIteration = buff[1] - 48;
            while (amountOfIteration != 0) {
                cubes[i].R();
                --amountOfIteration;
            }
        }
        else if(buff[0] == 'R') {
            amountOfIteration = buff[1] - 48;
            while(amountOfIteration != 0) {
                cubes[i].L();
                --amountOfIteration;
            }
        }
        else if(buff[0] == 'U') {
            amountOfIteration = buff[1] - 48;
            while(amountOfIteration != 0) {
                cubes[i].D();
                --amountOfIteration;
            }
        }
        else if(buff[0] == 'D') {
            amountOfIteration = buff[1] - 48;
            while(amountOfIteration != 0) {
                cubes[i].U();
                --amountOfIteration;
            }
        }
        else {
            std::cout << "you enterd something wrong\n";
        }
        buff = "";
    }
}


void fulfillingString(std::string& str, int size, int amountOfCubes)
{   
    int maxSize = amountOfCubes*8;
    maxSize = maxSize-size;
	str.insert(size, maxSize, '*');
}

void cubeInsertion(Cube*& cube, std::string str)
{
    int i = 0;
    std::string word;
    int currentIndex = 0;
    std::cout << "your string will be stored in cubes in this order\n"; 
    while (currentIndex < str.length()) {
        // Extract the next 8 characters from the sentence
        
        word = str.substr(currentIndex, 8);
        
        cube[i].insert(word);
        
        // Move the current index forward by 8 characters
        currentIndex += 8;
        std::cout << word << std::endl;
        ++i;
    
    }
}

void commandInsertion(std::string& commands, int amountOfCubs)
{
    std::cout << "insert commands for cubs\n";
    std::cout << "for example: L2:L4:D3:U3\n";
    std::cout << "amount of cubes are: " << amountOfCubs;
    std::cout << std::endl;
    std::getline(std::cin, commands);
}

int main()
{
    std::string str;
    std::getline(std::cin, str);
    
    int size = str.size();
    std::cout << "size of string is: ";
    std::cout << size << std::endl;
    
    int amountOfCubs = size/8;
    if (str.size() % 8 != 0) {
    ++amountOfCubs;
    }
    
    Cube* cubes = new Cube[amountOfCubs];
    
    fulfillingString(str, size, amountOfCubs);

    cubeInsertion(cubes, str);


    std::string commands;
    commandInsertion(commands, amountOfCubs);
    
    std::cout << std::endl;
    std::cout << "cubes before encryption\n";
    for (int i = 0; i < amountOfCubs; ++i) {
        cubes[i].print() ;
    }

    encrypt(cubes, amountOfCubs, commands);

    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "cubes after encryption\n";
    for (int i = 0; i < amountOfCubs; ++i) {
        cubes[i].print();
    }

    decrypt(cubes, amountOfCubs, commands);

    std::cout << std::endl;
    std::cout << std::endl; 
    std::cout << "cubes after decryption\n";
    for (int i = 0; i < amountOfCubs; ++i) {
        cubes[i].print();
    }

}
