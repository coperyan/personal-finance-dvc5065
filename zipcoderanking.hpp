

#ifndef zipcoderanking_hpp
#define zipcoderanking_hpp

#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

struct ZipCodeData
{
    string areaName;
    string zipCode;
    float lat;
    float lng;
    float medianRent;
    float distFromJob;
    float distRank;
    float rentRank;
    float totalScore;
    int overallRank;
};

class ZipCodeRanking
{
public:
    ZipCodeRanking()
    {
        printIntro();
    }
    void printIntro();
    void readFile();
    void printFile();
    void addDistFromJob(string);
    double haversine(double, double, double, double);
    void addRankingToVect();
    void setFactors();
    void getTopFiveZips();
private:
    vector<ZipCodeData> zipVect;
    double distanceFactor;
    double rentFactor;
};

#endif /* zipcoderanking_hpp */
