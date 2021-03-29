#include "romanos.hpp"

#include <iostream>

using namespace std;

int RomanToInt(char const * roman){
    int decimal = 0;

    int countIP = 0 , countIN = 0;

    int countXP = 0, countXN = 0;

    int countCP = 0, countCN = 0;

    int countV = 0;

    int countL = 0;

    int countD = 0;

    int countM = 0;



    for( int i = 0 ; roman[i] != '\0' ; i++){       
        if(roman[i] == 'M'){
            if(countIP != 0 || countV != 0 || countXP != 0 || countL != 0 || countD != 0 || countM == 3)
                return 0;
            else{
                decimal += 1000;
                countM++;
            }

        
        }else if(roman[i] == 'D'){
            if(countIP != 0 || countV != 0 || countCP != 0 || countXP != 0 || countL != 0 || countD != 0)
                return 0;
            else{
                decimal += 500;
                countD++;
            }

        }else if(roman[i] == 'C'){
            if(roman[i+1] == 'D' || roman[i+1] == 'M'){
                if(countCN == 1){
                    return 0;
                }else{
                    countCN++;
                    decimal -= 100;
                }
            }else{
                if(countCP == 3 || countXP != 0){
                    return 0;
                }else{
                    countCP++;
                    decimal += 100;
                }
            }

        }else if(roman[i] == 'L'){
            if(countIP != 0 || countXP != 0 || countV != 0 || countL != 0)
                return 0;
            else{
                decimal += 50;
                countL++;
            }

        }else if(roman[i] == 'X'){
            if(roman[i+1] == 'L' || roman[i+1] == 'C'){
                if(countXN == 1){
                    return 0;
                }else{
                    countCP--;
                    countXN++;
                    decimal -= 10;
                }
            }else{
                if(countXP == 3){
                    return 0;
                }else{
                    countXP++;
                    decimal += 10;
                }
            }

        }else if(roman[i] == 'V'){
            if(countIP != 0 || countV != 0)
                return 0;
            else{
                countV++;
                decimal += 5;
            }

        }else if(roman[i] == 'I'){
            if(roman[i+1] == 'V' || roman[i+1] == 'X' ){
                if(countIN == 1){
                    return 0;
                }else{
                    decimal -= 1;
                    countIN++;
                }
            }else{
                if(countIP == 3){
                    return 0;
                }else{
                    decimal += 1;
                    countIP++;
                }
            }

        }else{
            return 0;
        } 
    }

    return decimal;
};