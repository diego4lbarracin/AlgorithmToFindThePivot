//Author: Diego Albarracin.
//This code corresponds to the algorithm that I came up with
//as a solution to the problem of finding the pivot index where
//the sum of the averages of both sub-arrays is maximum.
//Time Complexity= O(n)
//Space Complexity= O(1);

#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> vector);

int main(){
        int n=0, value;
        vector<int> arrayOfIntegers= { 10, 20, 30, 40, 50, 6, 4};

        int pivot= solution(arrayOfIntegers);
        if(pivot!=-1){
            cout<< "The pivot is the index: "<< pivot << endl;
        }else{
            cout<< "Unfortunately, no index met the condition to be the pivot position." << endl;
        }

        return 0;
}

int solution(vector<int> vector){
        double rightSide= 0, leftSide= 0, leftAVG=0, rightAVG=0, 
        maxAVG=0, curentAVG=0, total=0; 
        int pivot= -1;
        //Calculating the total sum of the elements in the array.
        for(int num: vector){
            total+=num;
        }
        //Iterating through the array to find the pivot index.
        for (int i = 0; i < vector.size(); i++){
            rightSide= total - vector[i] - leftSide;
            leftAVG= leftSide/i;
            rightAVG= (rightSide)/(vector.size()-(i+1));
            curentAVG= leftAVG + rightAVG;
            //Checking if the currentAVG is the maximum possible average of both sub-arrays.
            if(curentAVG>maxAVG){
                //Updating the maximum average.
                maxAVG= curentAVG;
                //Updating the pivot.
                pivot= i;
            }
            leftSide+= vector[i];
        }
        cout<< "The maximum average is: "<< maxAVG << endl;
    return pivot;
}







