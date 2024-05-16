#include<iostream>
#include<array>
using namespace std;

/*

*/


int main(){

    array<int,10> arr;
    add_element(arr,5,10);




}

 void add_element(std::array<int,10>arr,int i,int j){


    cout<< "input i: index, j : value";
    cin >> i >>j;

    if (i >9&& i< -1){
        cout << "error : out of range";
    }
    else {
        arr[i] = j;
        cout << "index of "<<i<<j<<"inserted";

    }
    


}