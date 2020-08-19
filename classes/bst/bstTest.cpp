#include <iostream>
#include <fstream>

#include "bst.h"
#include "../date/date.h"

void testInt(void);
void testDate(void);
void testDate2ElectricBoogaloo(void);

std::ostream& operator<<(std::ostream& out, const Date& d);

int main()
{
    testInt();
    //testDate();
    //testDate2ElectricBoogaloo();
    return(0);
}


std::ostream& operator<<(std::ostream&, const Date& d)
{
    return(std::cout << d.getDateString());
}

void printKey(int key)
{
    std::cout << key << ", ";
}

void printKey(Date key)
{
    std::cout << key << ", ";
}




void testInt(void)
{
    std::cout << "\n******** TESTING INTEGER BINARY SEARCH TREE FUNCTIONS ********\n\n";

    std::ifstream inFile("testData/intTestData.txt");
    if(!inFile)
        exit(-1);
    std::string input;

    BST<int> testTree;

    while(getline(inFile, input, ','))
    {
        testTree.addLeaf(stoi(input));
    }

    std::cout << "Tree 1:\nIn order traversal: ";
    testTree.processInOrder(printKey);
    std::cout << std::endl << std::endl;

    std::cout << "Pre order traversal: ";
    testTree.processPreOrder(printKey);
    std::cout << std::endl << std::endl;

    std::cout << "Post order traversal: ";
    testTree.processPostOrder(printKey);
    std::cout << std::endl << std::endl;

    int srch1 = 2;
    int srch2 = 7;

    std::cout << srch1;
    if(testTree.searchKey(srch1))
        std::cout << " found in tree\n";
    else
        std::cout << " not found in tree\n";
    std::cout << std::endl;

    std::cout << srch2;
    if(testTree.searchKey(srch2))
        std::cout << " found in tree\n";
    else
        std::cout << " not found in tree\n";
    std::cout << std::endl;

    BST<int> testTree2;
    testTree2 = testTree;

    testTree2.deleteNode(2);
    testTree2.deleteNode(50);
    testTree2.deleteNode(100);
    testTree2.deleteNode(87);

    std::cout << "Deleted 2, 50, 87 & 100 from tree 2 after copy, If different, deep copy successful\n";
    std::cout << "Tree 1: ";
    testTree.processInOrder(printKey);
    std::cout << std::endl;

    std::cout << "Tree 2: ";
    testTree2.processInOrder(printKey);

    std::cout << std::endl;
}


void testDate(void)
{
    std::cout << "\n******** TESTING DATE BINARY SEARCH TREE FUNCTIONS ********\n\n";


    std::ifstream inFile("testData/dateTestData.txt");
    if(!inFile)
        exit(-1);
    std::string input;

    BST<Date> testTree;

    while(getline(inFile, input, ','))
    {
        testTree.addLeaf(input);
    }

    std::cout << "Tree 1: ";
    testTree.processInOrder(printKey);
    std::cout << std::endl;

    BST<Date> testTree2;
    testTree2 = testTree;
    std::cout << std::endl;

    Date deleteDate("02/07/1997");
    Date deleteDate2("15/06/2020");
    testTree2.deleteNode(deleteDate);
    testTree2.deleteNode(deleteDate2);


    std::cout << "Deleted 02/07/1997 & 15/06/2020 from tree 2 after copy, If different, deep copy successful\n";
    std::cout << "Tree 1: ";
    testTree.processInOrder(printKey);
    std::cout << std::endl;

    std::cout << "Tree 2: ";
    testTree2.processInOrder(printKey);

    std::cout << std::endl;
}


/*
void testDate2ElectricBoogaloo(void)
{
    std::cout << "\n******** TESTING DATE BINARY SEARCH TREE FUNCTIONS - using assignment 1 data ********\n\n";


    std::ifstream inFile("testData/MetData_Mar01-2014-Mar01-2015-ALL.csv");
    if(!inFile)
        exit(-1);
    std::string input;

    BST<Date> testTree;

    inFile.ignore(9999, '\n');      //get rid of first line (header);
    while(getline(inFile, input, ' '))
    {
        testTree.addLeaf(input);
        inFile.ignore(9999, '\n');
    }

    std::cout << "Tree 1: ";
    testTree.printInOrder();
    std::cout << std::endl;

    BST<Date> testTree2;
    testTree2 = testTree;
    std::cout << std::endl;

    Date deleteDate("02/07/1997");
    Date deleteDate2("15/06/2020");
    testTree2.deleteNode(deleteDate);
    testTree2.deleteNode(deleteDate2);


    std::cout << "Deleted 02/07/1997 & 15/06/2020 from tree 2 after copy, If different, deep copy successful\n";
    std::cout << "Tree 1: ";
    testTree.printInOrder();

    std::cout << "Tree 2: ";
    testTree2.printInOrder();

    std::cout << std::endl;
}*/
