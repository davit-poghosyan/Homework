#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include <vector>
#include <string>

class Cube
{
public:
    std::vector<std::vector<std::vector<char>>> cube;
    
    Cube()
    {
        cube.resize(2, std::vector<std::vector<char>>(2, std::vector<char>(2)));
    }
    void insert(std::string str) 
    {
        //cube[0].resize(2, std::vector<char>(2));
        cube[0][0][0] = str[0];
        cube[0][0][1] = str[1];
        cube[0][1][0] = str[2];
        cube[0][1][1] = str[3];
        //cube[1].resize(2, std::vector<char>(2));
        cube[1][0][0] = str[4];
        cube[1][0][1] = str[5];
        cube[1][1][0] = str[6];
        cube[1][1][1] = str[7];
    }

    void print()
    {
        std::cout << cube[0][0][0];
        std::cout << cube[0][0][1];
        std::cout << cube[0][1][0];
        std::cout << cube[0][1][1];
        std::cout << cube[1][0][0];
        std::cout << cube[1][0][1];
        std::cout << cube[1][1][0];
        std::cout << cube[1][1][1];
    }

    void L() 
    {
        char tmp = cube[0][0][0];
        char tmp1 = cube[1][0][0];
        cube[0][0][0] = cube[0][0][1];
        cube[1][0][0] = tmp;
        tmp = cube[1][0][1];
        cube[1][0][1] = tmp1;
        cube[0][0][1] = tmp;

        tmp = cube[0][1][0];
        tmp1 = cube[1][1][0];
        cube[0][1][0] = cube[0][1][1];
        cube[1][1][0] = tmp;
        tmp = cube[1][1][1];
        cube[1][1][1] = tmp1;
        cube[0][1][1] = tmp;
        }

    void R()
    {
        char tmp = cube[0][0][1];
        char tmp1 = cube[1][0][1];
        cube[0][0][1] = cube[0][0][0];
        cube[1][0][1] = tmp;
        tmp = cube[1][0][0];
        cube[1][0][0] = tmp1;
        cube[0][0][0] = tmp;

        tmp = cube[0][1][1];
        tmp1 = cube[1][1][1];
        cube[0][1][1] = cube[0][1][0];
        cube[1][1][1] = tmp;
        tmp = cube[1][1][0];
        cube[1][1][0] = tmp1;
        cube [0][1][0] = tmp;
    }

    void U()
    {
        char tmp = cube[0][0][0];
        char tmp1 = cube[1][0][0];
        cube[0][0][0] = cube[0][1][0];
        cube[1][0][0] = tmp;
        tmp = cube[1][1][0];
        cube[1][1][0] = tmp1;
        cube[0][1][0] = tmp;

        tmp = cube[0][0][1];
        tmp1 = cube[1][0][1];
        cube[0][0][1] = cube[0][1][1];
        cube[1][0][1] = tmp;
        tmp = cube[1][1][1];
        cube[1][1][1] = tmp1;
        cube[0][1][1] = tmp;
        }
    void D()
    {
        char tmp = cube[0][0][0];
        char tmp1 = cube[0][1][0];
        cube[0][0][0] = cube[1][0][0];
        cube[0][1][0] = tmp;
        tmp = cube[1][1][0];
        cube[1][1][0] = tmp1;
        cube[1][0][0] = tmp;

        tmp = cube[0][0][1];
        tmp1 = cube[0][1][1];
        cube[0][0][1] = cube[1][0][1];
        cube[0][1][1] = tmp;
        tmp = cube[1][1][1];
        cube[1][1][1] = tmp1;
        cube[1][0][1] = tmp;
    }
};


#endif

