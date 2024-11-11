#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <vector>

#define endl '\n'

using namespace std;

void print_vec(vector<int> arr){
    for(int val: arr){
        cout << val << ' ';
    }
    cout << endl;
}

vector<int> merge_sort(vector<int> arr){
    if(arr.size() == 1){
        return arr;
    }

    int mid = arr.size() / 2;
    vector<int> arr1 = merge_sort(vector<int>(arr.begin() + mid, arr.end()));
    vector<int> arr2 = merge_sort(vector<int>(arr.begin(), arr.begin() + mid));

    vector<int> arr1_2;
    auto it1 = arr1.begin();
    auto it2 = arr2.begin();
    while(it1 != arr1.end() && it2 != arr2.end()){
        if(*it1 > *it2){
            arr1_2.push_back(*it2);
            ++it2;
        }
        else{
            arr1_2.push_back(*it1);
            ++it1;
        }
    }
    while(it1 != arr1.end()){
        arr1_2.push_back(*it1);
        ++it1;
    }
    while(it2 != arr2.end()){
        arr1_2.push_back(*it2);
        ++it2;
    }
    return arr1_2;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // vector<int> arr = {73, 42, 91, 56, 18, 64, 39, 27, 85, 12};
    // vector<int> arr = {38, 27, 43, 10};
    ifstream inputFile("array_input.txt");
    vector<int> arr;
    string line;

    if(!inputFile) {
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    while(getline(inputFile, line)) {
        stringstream ss(line);
        string temp;
        while (getline(ss, temp, ',')) {
            if (!temp.empty()) {
                arr.push_back(std::stoi(temp));
            }
        }
    }
    inputFile.close();

    arr = merge_sort(arr);
    print_vec(arr);

    cout << "Ended\n";
    return 0;
}