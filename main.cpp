#include "userinfo.hpp"
#include "userincomeinfo.hpp"
#include "userexpenseinfo.hpp"
#include "zipcoderanking.hpp"
#include <iostream>
using namespace std;

int main()
{
    //Initalizing user info
    UserInfo ui;
    
    //Initalizing user income info
    UserIncomeInfo uii;
    
    //Initializing user expense info
    UserExpenseInfo uei;
    
    //Initializing zip code ranking
    ZipCodeRanking zcr;
    zcr.readFile();
    zcr.printFile();
    zcr.addDistFromJob(uii.getJobZip());
    zcr.setFactors();
    zcr.addRankingToVect();
    zcr.getTopFiveZips();

    cin.get();
    cin.get();
    return 0;
}
