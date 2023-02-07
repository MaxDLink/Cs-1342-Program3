//
// Created by Max Link on 2/28/22.
//

#ifndef PROGRAM3_PROGRAM3_H
#define PROGRAM3_PROGRAM3_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void downhillReadIn(vector<vector<string>> &playerInfo, vector<double> &downhillTimes, string line, string header,
                    int runCount, double &timeDownhillNumber);

void slalomReadIn(vector<vector<double>> &playerTimes, vector<double> &downhillTimes, string line, string header,
                  int runCount, double &timeDownhillNumber);

void findWinners(vector<vector<string>> &playerInfo, vector<vector<double>> &playerTimes, string &winnerNameDownHill,
                 string &winnerNameSlalom, string &winnerNameCombined, double &downhillBestTime, double &slalomBestTime,
                 double &totalBestTime);

void printToConsole(string &winnerNameDownHill,
                    string &winnerNameSlalom, string &winnerNameCombined, double &downhillBestTime, double &slalomBestTime,
                    double &totalBestTime);

void createResultsCsv(vector<vector<string>> &playerInfo, vector<vector<double>> &playerTimes);


#endif //PROGRAM3_PROGRAM3_H
