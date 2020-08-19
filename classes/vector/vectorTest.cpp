//vectorTest.cpp - test program for Vector
//Author Connor Nicholson - 28 Apr 20

#include <iostream>
#include "vector.h"

//display function used by other functions
void print(Vector<int> &arr)
{
    for(int i=0; i<arr.getSize(); i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
    std::cout << "Current array size is: " << arr.getSize() << std::endl;
    std::cout << "array capacity is: " << arr.getCapacity() << std::endl;
}

void print(Vector<char> &arr)
{
    for(int i=0; i<arr.getSize(); i++)
        std::cout << arr[i] << ", ";
    std::cout << std::endl;
    std::cout << "Current array size is: " << arr.getSize() << std::endl;
    std::cout << "array capacity is: " << arr.getCapacity() << std::endl;
}

void testConstruct()
{
    std::cout << "*** Test constructor ***" << std::endl;
    Vector<int> testArr;
    print(testArr);
}

void testConstructSize()
{
    std::cout << "*** Test constructor with predetermined size ***" << std::endl;
    Vector<int> testArr1(27);
    print(testArr1);

    Vector<int> testArr2(123);
    print(testArr2);

}

void testPushInt()
{
    std::cout << "*** Test push with integers ***" << std::endl;
    Vector<int> testArr;
    int input, index;
    do
    {
        std::cin >> input;
        testArr.push(input);
    }while(input != -1);
    print(testArr);
    print(testArr);

    std::cout << "new int: " << std::endl;
    std::cin >> input;
    std::cout << "Where do you want it? " << std::endl;
    std::cin >> index;
    //testArr.push(input, index);
    print(testArr);
    testArr[index] = input;
    print(testArr);
}

void testPushChar()
{
    std::cout << "*** Test push with characters ***" << std::endl;
    Vector<char> testArr;
    char input;
    do
    {
        std::cin >> input;
        testArr.push(input);
    }while(input != 'q');

    print(testArr);
}

void testSqrBracket()
{
    std::cout << "*** Test [] operator ***" << std::endl;
    Vector<int> testArr;

    for(int i=0; i<10; i++)
        testArr[i] = i*3;

    for(int i=0; i<10; i++)
        std::cout << testArr[i] << ", ";

}

void testGetSize()
{
    std::cout << "*** Test getSize() ***" << std::endl;
    Vector<int> testArr;
    int input;
    do
    {
        std::cin >> input;
        testArr.push(input);
    }while(input != -1);
    std::cout << "getSize() produces: " << testArr.getSize() << std::endl;

    print(testArr);
}

void testGetCapacity()
{
    std::cout << "*** Test getCapacity() ***" << std::endl;
    Vector<int> testArr;
    int input;
    do
    {
        std::cin >> input;
        testArr.push(input);
    }while(input != -1);
    std::cout << "getCapacity() produces: " << testArr.getCapacity() << std::endl;

    print(testArr);
}

void testCopy()
{
    std::cout << "*** Test copy constructor ***" << std::endl;

    Vector<int> vec1;
    vec1[0] = 1;
    vec1[1] = 2;
    vec1[2] = 3;

    Vector<int> vec2 = vec1;
    std::cout << vec1[0] << vec1[1] << vec1[2] << std::endl;
    vec2[1] = 8;
    std::cout << vec1[0] << vec1[1] << vec1[2] << std::endl;
    std::cout << vec2[0] << vec2[1] << vec2[2] << std::endl;
}



int main()
{
    testConstruct();
    //testConstructSize();
    //testPushInt();
    //testPushChar();
    //testSqrBracket();
    //testGetSize();
    //testGetCapacity();
    testCopy();

    return(0);
}
