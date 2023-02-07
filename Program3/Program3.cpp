//
// Created by Max Link on 2/28/22.
//

#include "Program3.h"

void downhillReadIn(vector<vector<string>> &playerInfo, vector<double> &downhillTimes, string line, string header,
                    int runCount, double &timeDownhillNumber) {

    //open file downHill file
    ifstream downhill;
    //cout << "opening downhill.csv" << endl;
    downhill.open("../downhill.csv");

    int fileOpenCheck = 0; //check for if file opens correctly
    if (!downhill.is_open()) {
        cout << "Error. could not open Downhill.csv" << endl;
        //return 1; //changes zero to 1 for failed opening
    }

//reading in downhill file line by line
    while (getline(downhill,
                   line)) {//reads each line. reads in whole file until you cannot stream characters from buffer
        if (line.find(header) != string::npos) {
            line.erase(); //erases header from string
        }

        //modify line before istringstream. take out headers.
        istringstream lineSS(line);   //links lineSS to line contents

        string firstName, lastName, country, timeDownhillString; //string vars for lineSS feed in
        //moving file contents from lineSS to downHill vars using comma as delimiter
        getline(lineSS, lastName, ',');
        getline(lineSS, firstName, ',');
        getline(lineSS, country, ',');
        getline(lineSS, timeDownhillString, ','); //records time Downhill as a string
        //cout << "timeDownhillString: " << timeDownhillString << endl;

        //cout << "down hill time: " << timeDownhillString << endl;

        if (runCount > 0) {//only runs for second loop and onward to prevent printing blank header values
//            cout << "Last Name: " << lastName << " " << "First Name: " << firstName << " " << "Country: " << country
//                 << endl;
            vector<string> row; //local row var eliminated after every if execution
            //fill row up with lastName, firstName, country contents
            row.push_back(lastName);
            row.push_back(firstName);
            row.push_back(country);

            playerInfo.push_back(row); //puts string contents that are in row into playerInfo vector

            timeDownhillNumber += stod(
                    timeDownhillString); //converts timeDownhill to a number & concatenates to timeDownhillNumber for total time calculation later
//            cout << "timeDownHillString: " << timeDownhillString << " timeDownHillNumber: " << timeDownhillNumber
//                 << endl;
            //storing converted times into one-dimensional times vector
            downhillTimes.push_back(stod(timeDownhillString));
        }
        runCount++;
    }


    downhill.close(); //closes the file downhill.csv

    //return fileOpenCheck; //returns fileOpenCheck to let user know if file successfully opened (0) or failed to open(1)
}

void slalomReadIn(vector<vector<double>> &playerTimes, vector<double> &downhillTimes, string line, string header,
                  int runCount, double &timeDownhillNumber) {

    ifstream slalom;

    //cout << "opening slalom.csv" << endl;
    slalom.open("../slalom.csv");

    if (!slalom.is_open()) {
        cout << "Error. could not open slalom.csv" << endl;
        //return 1;
    }


    runCount = 0; //resets runCount to zero for slalom file read in. checks how many times while has run for situational console printing
    double timeSlalomNumber{0};
    int downhillTimesIndex{0}; //var to keep track of downhillTimes vector's index count when adding it to playerTimes
    while (getline(slalom,
                   line)) {//reads each line. reads in whole file until you cannot stream characters from buffer
        if (line.find(header) != string::npos) {
            line.erase(); //erases header from string
        }

        //modify line before istringstream. take out headers.
        istringstream lineSS(line);   //links lineSS to line contents

        string firstName, lastName, country, timeSlalomString; //string vars for lineSS feed in
        //moving file contents from lineSS to downHill vars using comma as delimiter
        getline(lineSS, lastName, ',');
        getline(lineSS, firstName, ',');
        getline(lineSS, country, ',');
        getline(lineSS, timeSlalomString, ','); //records time Downhill as a string
        //cout << "timeDownhillString: " << timeDownhillString << endl;

        //cout << "down hill time: " << timeDownhillString << endl;

        if (runCount > 0) {//only runs for second loop and onward to prevent printing blank header values
//            cout << "Last Name: " << lastName << " " << "First Name: " << firstName << " " << "Country: " << country
//                 << endl;

            timeSlalomNumber = stod(
                    timeSlalomString); //converts timeSlalomString to a number & concatenates to timeDownhillNumber for total time calculation later

            vector<double> row; //local row var eliminated after every if execution
            //fill row up with lastName, firstName, country contents
            row.push_back(downhillTimes.at(downhillTimesIndex)); //puts downhillTimes times into playerTimes
            row.push_back(timeSlalomNumber); //puts timeSlalomNumber into playerTimes as a double
            row.push_back((downhillTimes.at(downhillTimesIndex)) +
                          timeSlalomNumber); //adds downhillTimes from downhillTimes vector to timeSlalomNumber to get total time
            playerTimes.push_back(row); //puts double contents that are in row into playerInfo vector
            downhillTimesIndex++; //increment downhillTimesIndex to increase index of downhillTimes on next loop
        }
        runCount++;
    }


    slalom.close(); //closes the slalom file

}

void findWinners(vector<vector<string>> &playerInfo, vector<vector<double>> &playerTimes, string &winnerNameDownHill,
                 string &winnerNameSlalom, string &winnerNameCombined, double &downhillBestTime, double &slalomBestTime,
                 double &totalBestTime) {

    // cout << "the playerTimes is: " << playerTimes[0][0] << endl;
    for (int i = 0; i < playerTimes.size(); i++) //nested for loop for 2-D vectors picking winners
    {
        for (int j = 0; j < playerTimes.at(i).size(); j++) //0, 1, 2, 3, 4, 5
        {
            if (j == 0) {//if j is equal to every other even number
                //cout << "The first if is running!" << endl;
                if (downhillBestTime == 0 || downhillBestTime > playerTimes.at(i).at(j)) {
                    //cout << "HELLO" << endl;
                    //cout << "The downhill time is: " << playerTimes[i][j] << endl;
                    downhillBestTime = playerTimes.at(i).at(j);
                    winnerNameDownHill = playerInfo.at(i).at(j + 1) + " " + playerInfo.at(i).at(j);
                    //winnerNameDownHill += " " + playerInfo.at(i).at(j+1);
                    //cout << "winnerNameDownHill is: " << winnerNameDownHill << endl;
                }
            } else if (j == 1) {//if j is equal to every odd number
                //cout << "The second if is running!" << endl;
                if (slalomBestTime == 0 || slalomBestTime > playerTimes.at(i).at(j)) {
                    slalomBestTime = playerTimes.at(i).at(j);
                    winnerNameSlalom = playerInfo.at(i).at(j - 1) + " " + playerInfo.at(i).at(j);
                }
            } else {
                //cout << "The else is running" << endl;
                if (totalBestTime == 0 || totalBestTime > playerTimes.at(i).at(j)) {
                    totalBestTime = playerTimes.at(i).at(j);
                    winnerNameCombined = playerInfo.at(i).at(j - 2) + " " + playerInfo.at(i).at(j - 1);
                }
            }
        }

    }
}

void printToConsole(string &winnerNameDownHill,
                    string &winnerNameSlalom, string &winnerNameCombined, double &downhillBestTime, double &slalomBestTime,
                    double &totalBestTime) {
    //announce the winners
    //cout << "player name here: " << playerInfo.at(1).at(1) << " " << playerInfo.at(0).at(0) << endl;
    cout << "Reading in Files..." << "\n" << "Calculating Scores..." << "\n\n" << "Announcing the Winners!"
         << endl;
    cout << "Downhill: " << winnerNameDownHill << " with a time of " << downhillBestTime << " seconds" << endl;
    cout << "Slalom:   " << winnerNameSlalom << " with a time of " << slalomBestTime << " seconds" << endl;
    cout << "Combined: " << winnerNameCombined << " with a time of " << totalBestTime << " seconds" << endl;
}

void createResultsCsv(vector<vector<string>> &playerInfo, vector<vector<double>> &playerTimes) {
    //writing results to results.csv file
    //create results.csv file
    ofstream resultsFS;
    resultsFS.open("results.csv");

    if(!resultsFS.is_open()){//check if results.csv opens
        cout << "results.csv failed to open" << endl;
    }

    //write both playerInfo and playerTimes vector contents to results.csv file
    resultsFS << "LastName,FirstName,Country,Downhill,Slalom,Total" << endl; //header

    for (int i = 0; i < playerInfo.size(); i++) //nested for loop for 2-D vectors
    {
        if(i > 0)
            resultsFS << endl;
        for (int j = 0; j < playerInfo.at(i).size(); j++)
        {
            resultsFS << playerInfo.at(i).at(j) << ",";
        }
        for (int j = 0; j < playerInfo.at(i).size(); j++)
        {
            resultsFS << playerTimes.at(i).at(j);
            if(j < playerTimes.size()-3){ //if (j < 2)
                resultsFS << ",";
            }
        }
    }

    resultsFS.close(); //closes resultsFS file

    //return 0;
}