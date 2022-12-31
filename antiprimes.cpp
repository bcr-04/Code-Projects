#include <iostream>
#include <string>
#include <vector>
using namespace std;
//https://www.mygreatlearning.com/blog/vectors-in-c/

int findFactors(int i){
    int currentFactors = 2; // 1, i
    for(int j = 2; j < i; j++){
        if(i % j == 0){
            currentFactors++;
        }
    }
    return currentFactors;
}

bool existsInVector(vector<int> vect, int num){
    for(int i = 0; i < vect.size(); i++){
        if(vect.at(i) == num){
            return true;
        }
    }
    return false;
}

int findInVector(vector<int> vect, int num){
    for(int i = 0; i < vect.size(); i++){
        if(vect.at(i) == num){
            return i;
        }
    }
    return -1;
}

string vectorToString(vector<int> vect, string separator){
    string returnString = "";
    for(int i = 0; i < vect.size() - 1; i++){
        returnString += to_string(vect.at(i)) + separator;
    }
    return returnString + to_string(vect.at(vect.size() - 1));
}


vector<int> giveFactors(int num){
    vector<int> returnVector;
    for(int i = 1; i <= num; i++){
        if(num % i == 0){
            returnVector.push_back(i);
        }
    }
    return returnVector;
}

int floorLog(int num, int divis){
    int ct = 0;
    while(num % divis == 0){
        ct++;
        num /= divis;
    }
    return ct;
}

string getPrimeFactors(int num){
    vector<int> factorList = giveFactors(num);
    vector<int> primeFactors;
    vector<int> primePowers;
    //return vectorToString(factorList, ", ");
    for(int i = 1; i < factorList.size(); i++){
        bool composite = false;
        for(int j = 0; j < primeFactors.size(); j++){
            //cout << factorList.at(i) << ", " << primeFactors.at(j) << ", " << factorList.at(i) % primeFactors.at(j) << "\n\n\n";
            if(factorList.at(i) % primeFactors.at(j) == 0){
                composite = true;
                break;
            }
        }
        if(!composite){
            primeFactors.push_back(factorList.at(i));
            //return "sus";
        }
    }
    //return vectorToString(primeFactors," ") + "[]" + vectorToString(primeFactors," ") + "\n\n\n";
    string returnString = "";
    
    for(int i = 0; i < primeFactors.size(); i++){
        //return to_string(primeFactors.at(i));
        primePowers.push_back(floorLog(num,primeFactors.at(i)));
    }
    //return vectorToString(primeFactors, ", ") + "[]" + vectorToString(factorList, ", ") + "\n\n";
    for(int i = 0; i < primeFactors.size() - 1; i++){
        returnString += "(" + to_string(primeFactors.at(i)) + "^" + to_string(primePowers.at(i)) + ") * ";
    }
    return "(1^1) * " + returnString + "(" + to_string(primeFactors.at(primeFactors.size()-1)) + "^" + to_string(primePowers.at(primeFactors.size()-1)) + ") = " + to_string(num) + " --- " + to_string(findFactors(num)) + " factors.\n\n";
}
/*
string arrayToString(int* arr){
    string returnString = "[";
    for(int i = 0; i < arrSize(arr) - 1; i++){
        returnString += to_string(arr[i]) + ", ";
    }
    return returnString + to_string(arr[arrSize(arr) - 1]) + "]";
}
*/

int main()
{
    int maxFactors = 0;
    int magicNumber = 1;
    int lastAnti = 1;
    int lastTwin = 0;
    //cout << getPrimeFactors(12);
    for(int i = 4; i < 10000000; i += magicNumber){
        int currentFactors = findFactors(i);
        if(currentFactors > maxFactors){
            //cout << i << " (" << currentFactors << ", +" << (currentFactors - maxFactors) << ", +" << (i - lastAnti) << ")\n";
            //ughhhhh
            /*
            for(int ii = 0; ii < currentFactors; ii++){
                factorList[ii] = giveFactors(i, ii);
            }
            //cout << i << " (" << factorList << ")\n";
            */
            //cout << i << " (" << vectorToString(giveFactors(i + 1), ", ") << ")\n";
            
            //cout << i << " " << existsInVector(giveFactors(i), 120) << "\n";
            cout << i << "\n\n"; //getPrimeFactors(i) << << "\n\n";
            
            //lastAnti = i;
            maxFactors = currentFactors;
        }
        /*
        if(findFactors(i - 1) == 2 && findFactors(i + 3) == 2 && 0){
            cout << i << " => +" << i - lastTwin << "\n\n";
            lastTwin = i;
        }
        */
    }
    
    vector<int> myVector;
    myVector.push_back(2);
    myVector.push_back(1);
    myVector.push_back(5);
    myVector.push_back(7);
    myVector.at(1)++;
    //cout << vectorToString(myVector, " ");
    //cout << findInVector(myVector,5);
    //cout << arrayToString(myArr);
    //cout << vectorToString(myVector);
}