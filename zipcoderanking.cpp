

#include "zipcoderanking.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

bool sortDist(const ZipCodeData &zd1, const ZipCodeData &zd2)
{
    return zd1.distFromJob < zd2.distFromJob;
}

bool sortRent(const ZipCodeData &zd1, const ZipCodeData &zd2)
{
    return zd1.medianRent < zd2.medianRent;
}

bool sortTotalScore(const ZipCodeData &zd1, const ZipCodeData &zd2)
{
    return zd1.totalScore < zd2.totalScore;
}

void ZipCodeRanking::printIntro()
{
    cout << "----------HOUSING FINDER----------" << endl;
}

void ZipCodeRanking::readFile()
{
    ifstream fin;
    fin.open("/Users/rcope/Desktop/testproj/testproj/testproj/bayareazips.txt");
    vector<string> row;
    string line, word, temp;
    ZipCodeData iterZipVect;

    if(!fin.is_open())
    {
        cout << "Error opening file.." << endl;
    }
    else
    {
        while(fin)
        {
            string s;
            if(!getline(fin, s))
            {
                break;
            }

            istringstream ss(s);
            vector <string> record;
            while(ss)
            {
                string s;
                if(!getline(ss, s, ','))
                {
                    break;
                }
                record.push_back(s);
            }
            iterZipVect.areaName = record[0];
            iterZipVect.zipCode = record[1];
            iterZipVect.lat = stof(record[2]);
            iterZipVect.lng = stof(record[3]);
            iterZipVect.medianRent = stod(record[4]);
            iterZipVect.distFromJob = 0.00;
            iterZipVect.distRank = 0;
            iterZipVect.rentRank = 0;
            iterZipVect.totalScore = 0.00;
            iterZipVect.overallRank = 0;
            zipVect.push_back(iterZipVect);
        }
    }

    fin.close();

}

void ZipCodeRanking::printFile()
{
    for (int i = 0; i < zipVect.size(); i++)
    {
        //cout << "Zip:" << zipVect[i].zipCode << " Name: " << zipVect[i].areaName << endl;
    }
}

double ZipCodeRanking::haversine(double lat1, double lng1, double lat2, double lng2)
{
    //Distance
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLng = (lng2 - lng1) * M_PI / 180.0;

    //Convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    //Apply formula
    double a = pow(sin(dLat/2),2) + pow(sin(dLng/2),2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));

    return (rad * c) / 1.609;
}

void ZipCodeRanking::addDistFromJob(string userJobZip)
{
    float jobLat, jobLng;
    double iterDist;

    //Initalizing variables
    jobLat = 0.0000;
    jobLng = 0.0000;

    cout << "Looking for lat long of user zip.." << endl;

    for(int i = 0; i < zipVect.size(); i++)
    {
        if(zipVect[i].zipCode == userJobZip)
        {
            jobLat = zipVect[i].lat;
            jobLng = zipVect[i].lng;
            break;
        }
    }

    cout << "Starting distance rankings.." << endl;

    for(int i = 0; i < zipVect.size(); i++)
    {
        iterDist = haversine(jobLat, jobLng, zipVect[i].lat, zipVect[i].lng);
        zipVect[i].distFromJob = iterDist;
        //cout << "Zip: " << zipVect[i].zipCode << " is " << iterDist << " from job zip " << userJobZip << "." << endl;
    }
}

void ZipCodeRanking::setFactors()
{
    double iterEntry, iterEntry2;
    cout << "Please enter the desired factor for distance (proximity to your job) vs rent prices (value must be less than 1, enter as x.xx " << endl;
    cin >> iterEntry;
    iterEntry2 = 1.00 - iterEntry;
    cout << "Distance factor is: " << iterEntry << ", rent factor: " << iterEntry2 << endl;
    distanceFactor = iterEntry;
    rentFactor = iterEntry2;
}
void ZipCodeRanking::addRankingToVect()
{

    //Sorting vector by distance from job (ascending)
    sort(zipVect.begin(), zipVect.end(), sortDist);

    //Looping over vector and assigning ranks for distance
    for(int i = 0; i < zipVect.size(); i++)
    {
        zipVect[i].distRank = i + 1;
        //cout << "Zip: " << zipVect[i].zipCode << " dist: " << zipVect[i].distFromJob << endl;
    }

    //Sorting vector by rent ascending
    sort(zipVect.begin(), zipVect.end(), sortRent);

    //Looping over vector and assigning ranks for rent
    for(int i = 0; i < zipVect.size(); i++)
    {
        zipVect[i].rentRank = i + 1;
        //cout << "Zip: " << zipVect[i].zipCode << " rent: " << zipVect[i].medianRent << endl;
    }

    //Looping over vector and assigning total score (using factors and ranks)
    for(int i = 0; i < zipVect.size(); i++)
    {
        zipVect[i].totalScore = ((zipVect[i].distRank * (1 - distanceFactor)) + (zipVect[i].rentRank * (1 - rentFactor))/2);
    }

    //Sorting based on total score
    sort(zipVect.begin(), zipVect.end(), sortTotalScore);

    //Looping over one last time and assigning overall rank
    for(int i = 0; i < zipVect.size(); i++)
    {
        zipVect[i].overallRank = i+1;
    }
}

void ZipCodeRanking::getTopFiveZips()
{
    cout << "Top 5 Zip Codes: " << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << "Zip #" << i + 1 << ": " << zipVect[i].zipCode << ", Name: " << zipVect[i].areaName << ", Distance from Job: " << zipVect[i].distFromJob << " miles, Median Rent: $" << zipVect[i].medianRent << endl;
    }
}
