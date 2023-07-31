//Author: Diego Albarracin.
//This code corresponds to the algorithm that I came up with
//as a solution to the problem of finding the pivot index where
//the sum of the averages of both sub-arrays is maximum.
//Time Complexity= O(n^2)
//Space Complexity= O(1);

#include <bits/stdc++.h>
using namespace std;
void printVector(vector<int> vectorToPrint);
int solution(vector<int> vector);

int main(){
        int n=0, value;
        vector<int> arrayOfIntegers= {1,2,3,4,5,6,4};
        // cout << "How many elements will you store inside the array?";
        // cin >> n;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << "Type the value " << i << ": ";
        //     cin >> value;
        //     arrayOfIntegers.push_back(value);
        // }
        int pivot= solution(arrayOfIntegers);
        // if(pivot!=-1){
            cout<< "The pivot is the index: "<< pivot << endl;
        // }else{
        //     cout<< "Unfortunately, no index met the condition to be the pivot position." << endl;
        // }

        return 0;
}
int solution(vector<int> vector){
        int rightSide= 0, leftSide= 0, aux=0, maxValue=0, curentValue=0, pivot=0;
    
        for (int i = 0; i < vector.size() - 1; i++){
            leftSide+= vector[i];
            for (int j = (i+1); j < vector.size(); j++)
            {
                rightSide+= vector[j];
                aux+=1;
            }
            leftSide/= i+1;
            rightSide/= aux;

            curentValue= leftSide+rightSide;
            if(curentValue>maxValue){
                pivot= i;
                maxValue= curentValue;
            }
            curentValue=0;
            aux=0;
        }
    return pivot;
}







