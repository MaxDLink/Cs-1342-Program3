
#include "Program3.h"

using namespace std;

int main() {
    //2-D VECTORS FOR PLAYERINFO AND PLAYERTIME VECTORS
    vector<vector<string>> playerInfo; //stores each players last name, first name, and Country

    vector<vector<double>> playerTimes; //stores each players downhill, slalom, and calculated total time

    vector<double> downhillTimes; //for storing downhill times to put in playerTimes later

    string line;
    string header = "LastName,FirstName,Country,Time";
    int runCount{0}; //checks how many times while has run for situational console printing
    double timeDownhillNumber{0};

    //vars for holding best times of each category. zero placeholder value to start each for condition check
    double downhillBestTime{0};
    double slalomBestTime{0};
    double totalBestTime{0};
    string winnerNameDownHill; //records the names of the winner of the downhill
    string winnerNameSlalom; //records the name of the winner of the slalom
    string winnerNameCombined; //records the name of the winner of both events combined

    downhillReadIn(playerInfo, downhillTimes, line, header, runCount,
                   timeDownhillNumber); //reads in downhill file contents into playerInfo vector

    slalomReadIn(playerTimes, downhillTimes, line, header, runCount,
                 timeDownhillNumber); //reads in slalom file contents into playerTimes vector

    findWinners(playerInfo, playerTimes, winnerNameDownHill, winnerNameSlalom, winnerNameCombined, downhillBestTime,
                slalomBestTime, totalBestTime); //finds winners of downhill, slalom, and combined competitions

    printToConsole(winnerNameDownHill,
                   winnerNameSlalom, winnerNameCombined, downhillBestTime, slalomBestTime,
                   totalBestTime); //call print to console function to print winners

    createResultsCsv(playerInfo, playerTimes); //calls createResults function to create result.csv file


    return 0;

//TODO: split into functions, comment code;

}
