//main program for question 5

#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

#include "windlog/windlogType.h"
#include "windlogOutput/outputClass.h"

void readData(Map<int, Map<int, WindlogType>> &windlog, std::string fileNameList, std::string path);        //reads data

void menu(Map<int, Map<int, WindlogType>> &windlog, OutputClass &output, std::string file);       //displays menu

void choice1(OutputClass &output);      //outputs the first choice

void choice2(OutputClass &output);      //outputs the second choice

void choice3(OutputClass &output);      //outputs the third choice

void choice4(OutputClass &output, std::string file);    //outputs the fourth choice

void choice5(Map<int, Map<int, WindlogType>> &windlog, OutputClass &output);       //outputs the fifth choice


/*******************************************************************************************/

int main()
{
    Map<int, Map<int, WindlogType>> windlog;    //where the entirety of the data will be stored

    std::string outFile = "../data/WindTempSolar.csv";

    std::string path = "../data/";      //relative path to the files
    std::string inFileList = path + "met_index.txt";

    readData(windlog, inFileList, path);        //reads the data into windlog

    OutputClass output(windlog);        //crunches the numbers into useful information

    menu(windlog, output, outFile);      //displays the menu

    return(0);
}

/********************************************************************************************/

//Reads data from file
void readData(Map<int, Map<int, WindlogType>> &windlog, std::string fileNameList, std::string path)
{
    std::ifstream fileList(fileNameList);
    if(!fileList)
        exit(-1);       //checks that the file index was loaded correctly

    std::string fileName;       //store the name of the current file we're looking at

    int year;
    int month;
    int vi = 0;     //windlog vector index

    while(getline(fileList, fileName))
    {
        fileName = path + fileName;

        //open file
        std::ifstream inFile(fileName);
        if(!inFile)
            exit(-2);       //checks the current file was loaded
        std::string input;
        int i, sLoc, tLoc, srLoc;

        //Find the collumn location of wind speed
        i=0;
        while(getline(inFile, input, ','))
        {
            if(input == "S")
                sLoc = i-1;     //need to stop at the comma before the data you want
            else if(input == "SR")
                srLoc = i-sLoc-2;     //-2 because 2 things have been read
            else if(input == "Sx")      //"T" can't be found as no ',' follows it, so had to cheat and do "Sx"
            {
                tLoc = i-(sLoc+srLoc)-3+1;       //-3 because 3 things have been read - +1 because we stopped at Sx not T
                break;
            }
            i++;
        }
        inFile.ignore(999, '\n');       //disregard rest of file line

        //read data into structure
        while(getline(inFile, input, ' '))    //date and time are split with  ' '
        {
            Date tempDate = input;
            year = tempDate.getYear();
            if(month != tempDate.getMonth())        //if newmonth the
                vi = 0;
            month = tempDate.getMonth();

            bool dataValid = true;    //check if data is available or not
            windlog[std::move(year)][std::move(month)].date[vi] = input;

            getline(inFile, input, ',');    //time end at a ','
            windlog[std::move(year)][std::move(month)].time[vi] = input;

            for(int j=0; j<sLoc; j++)     //sLoc -1 because WAST has already been read
                inFile.ignore(999, ',');
            getline(inFile, input, ',');
            if(input == "N/A")
                dataValid = false;
            else
                windlog[std::move(year)][std::move(month)].speed[vi] = stof(input);     //converts string to float

            for(int j=0; j<srLoc; j++)     //sLoc -1 because WAST has already been read
                inFile.ignore(999, ',');
            getline(inFile, input, ',');
            if(input == "N/A")
                dataValid = false;
            else
                windlog[std::move(year)][std::move(month)].solarRad[vi] = stof(input);     //converts string to float'

            for(int j=0; j<tLoc; j++)     //compenstating for items already read in line
                inFile.ignore(999, ',');
            getline(inFile, input, '\n');
            if(input == "N/A")
                dataValid = false;
            else
                windlog[std::move(year)][std::move(month)].airTemp[vi] = stof(input);       //converts string to float

            if(dataValid)
                vi++;
        }
        std::cout << "Successfully loaded: " << fileName << std::endl;
        inFile.close();
    }
    fileList.close();
    std::cout << std::endl;
}

//Displays menu
void menu(Map<int, Map<int, WindlogType>> &windlog, OutputClass &output, std::string file)
{
    std::string choice; //by making it a string we can account for all inputs
    do
    {
        std::cout << "Please select an option:\n";
        std::cout << "1: Average wind speed for a given month and year\n";
        std::cout << "2: Average air temperature for each month of a given year\n";
        std::cout << "3: Total solar radiation for each month of a given year\n";
        std::cout << "4: Save all above info for a given year into a CSV file\n";
        std::cout << "5: Highest solar radiation for a given date\n";
        std::cout << "6: Exit the program.\n";

        std::cin >> choice;

        if(choice == "1")
            choice1(output);
        else if(choice == "2")
            choice2(output);
        else if(choice == "3")
            choice3(output);
        else if(choice == "4")
            choice4(output, file);
        else if(choice == "5")
            choice5(windlog, output);
        else if(choice == "6")
            std::cout << "Goddbye!";
        else
            std::cout << "Invalid option, try again\n";

        std::cout << std::endl;

    }while(choice != "6");
}


void choice1(OutputClass &output)
{
    int year, month;
    try
    {
        std::cout << "Year: ";
        std::cin >> year;
        if(year < 1 || year > 9999)
            throw "INVALID INPUT";

        std::cout << "Month: (Numeric) ";
        std::cin >> month;
        std::cout << std::endl;
        if(month > 12 || month < 1)     //Month has to be between 1-12
            throw "INVALID INPUT";

        std::cout << std::fixed << std::showpoint << std::setprecision(1);      //formating
        std::cout << Date::getMonthString(month) << " " << year << ": ";
        if(!output.searchOutput(year*100 + month))  //year*100 + month creates unique int, in order eg. Jul 2014 becomes 201407
                std::cout << "No Data\n";
        else
        {
            std::cout << "\nAverage speed: " << output.getWindAvg()[std::move(year)][std::move(month)] << " Km/h \n";
            std::cout << "Sample stdev: " << output.getWindStdDev()[std::move(year)][std::move(month)] << "\n";
        }
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
        std::cin.clear();
        std::cin.ignore(999, '\n');     //clears cin to prevent infinite loop
        choice1(output);
    }
}



void choice2(OutputClass &output)
{
    int year;
    try
    {
        std::cout << "Year: ";
        std::cin >> year;
        std::cout << std::endl;

        if(std::cin.fail() || year < 1 || year > 9999)        //if year not an interger, OR it's less than 0 OR it's greater that 4 digits
                throw "INVALID INPUT";

        std::cout << std::fixed << std::showpoint << std::setprecision(1);      //formating
        for(int month=1; month<=12; month++)
        {
            std::cout << Date::getMonthString(month) << ": ";
            if(!output.searchOutput(year*100 + month))  //year*100 + month creates unique int, in order eg. Jul 2014 becomes 201407
                    std::cout << "No Data\n";
            else
            {
                std::cout << "Average: " << output.getTempAvg()[std::move(year)][std::move(month)] << " degrees C, ";
                std::cout << "stdev: " << output.getTempStdDev()[std::move(year)][std::move(month)] << "\n";
            }
        }
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
        std::cin.clear();
        std::cin.ignore(999, '\n');     //clears cin to prevent infinite loop
        choice2(output);
    }
}

void choice3(OutputClass &output)
{
    int year;
    try
    {
        std::cout << "Year: ";
        std::cin >> year;
        std::cout << std::endl;

        if(std::cin.fail() || year < 1 || year > 9999)        //if year not an interger, OR it's less than 0 OR it's greater that 4 digits
            throw "INVALID INPUT";

        std::cout << std::fixed << std::showpoint << std::setprecision(1);      //formating
        for(int month=1; month<=12; month++)
        {
            std::cout << Date::getMonthString(month) << ": ";
            if(!output.searchOutput(year*100 + month))  //year*100 + month creates unique int, in order eg. Jul 2014 becomes 201407
                    std::cout << "No Data\n";
            else
                std::cout << output.getSolarTotal()[std::move(year)][std::move(month)] << " kWh/m^2\n";
        }
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
        std::cin.clear();
        std::cin.ignore(999, '\n');     //clears cin to prevent infinite loop
        choice3(output);
    }
}


void choice4(OutputClass &output, std::string file)
{
    int year;
    int counter = 0;
    try
    {
        std::ofstream outFile(file);

        std::cout << "Year: ";
        std::cin >> year;
        std::cout << std::endl;

        if(std::cin.fail() || year < 1 || year > 9999)        //if year not an interger, OR it's less than 0 OR it's greater that 4 digits
            throw "INVALID INPUT";

        std::cout << std::fixed << std::showpoint << std::setprecision(1);      //formating
        outFile << year << "\n";
        for(int month=1; month<=12; month++)
        {
            if(output.searchOutput(year*100 + month))     //checks if there's data
            {
                outFile << Date::getMonthString(month) << ",";
                if(output.getWindStdDev()[std::move(year)][std::move(month)] < 0)
                        outFile << ",";
                else
                    outFile << output.getWindAvg()[std::move(year)][std::move(month)] << "(" << output.getWindStdDev()[std::move(year)][std::move(month)] << "),";
                if(output.getTempStdDev()[std::move(year)][std::move(month)] < 0)
                    outFile << ",";
                else
                    outFile << output.getTempAvg()[std::move(year)][std::move(month)] << "(" << output.getTempStdDev()[std::move(year)][std::move(month)] << ")";
                if(output.getSolarTotal()[std::move(year)][std::move(month)] < 0)
                    outFile << " \n";
                else
                    outFile << output.getSolarTotal()[std::move(year)][std::move(month)] << "\n";
            }
            else
                counter++;
        }
        if(counter == 12)
            std::cout << "No Data\n";

        std::cout << "Successfuly saved: " << file << std::endl;
        outFile.close();
    }
    catch(const char* e)
    {
        std::cout << e << std::endl;
        std::cin.clear();
        std::cin.ignore(999, '\n');     //clears cin to prevent infinite loop
        choice4(output, file);
    }
}

void choice5(Map<int, Map<int, WindlogType>> &windlog, OutputClass &output)
{
    std::string dateString;
    std::cout << "Date (d/m/yyyy): ";
    std::cin >> dateString;
    std::cout << std::endl;

    try     //throws if user enters invalid date format
    {
        Date date(dateString);
        int year = date.getYear();
        int month = date.getMonth();
        output.calculateHighSolar(windlog, date);

        std::cout << std::fixed << std::showpoint << std::setprecision(1);      //formating
        std::cout << "Date: " << dateString << std::endl;
        if(!output.searchOutput(year*100 + month))  //year*100 + month creates unique int, in order eg. Jul 2014 becomes 201407
            std::cout << "No data" << std::endl;
        else
        {
            std::cout <<  "High solar radiation for the day: " << output.getHighSolar() << "W/m2\n\n";
            std::cout << "Time:\n";
            for(int i=0; i<output.getHighSolarTime().getSize(); i++)
                std::cout << output.getHighSolarTime()[i].getTimeString() << std::endl;
        }
    }
    catch(std::invalid_argument& e)
    {
        std::cout << "INVALID INPUT" << std::endl;
        choice5(windlog, output);
    }
}
