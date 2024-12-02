#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <vector>

#define endl '\n'
#define PB push_back
#define MP make_pair

using namespace std;

void initialize_arr(vector<int> &arr){
    ifstream inputFile("../data/array_input.txt");
    string line;

    if(!inputFile) {
        cerr << "Failed to open file!" << endl;
        return;
    }

    while(getline(inputFile, line)) {
        stringstream ss(line);
        string temp;
        while (getline(ss, temp, ',')) {
            if (!temp.empty()) {
                arr.PB(std::stoi(temp));
            }
        }
    }
    inputFile.close();
}

void print_vec(vector<int> arr){
    for(int val: arr){
        cout << val << ' ';
    }
    cout << endl;
}

void prty_vec(vector<int> arr){
    int curr_val = arr[0];
    vector<pair <int, int>> sorted_arr;
    int count = 1;
    for(int val: arr){
        if(curr_val != val){
            curr_val = val;
            sorted_arr.PB(MP(curr_val, count));
            count = 1;
        }
        else{
            ++count;
        }
    }
    for(auto it = sorted_arr.begin(); it != sorted_arr.end(); ++it){
        cout << "Val: " << it->first << " Frequency: " << it->second << endl;
    }
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

vector<int> bubble_sort(vector<int> arr){
    bool flag = true;
    while(flag){
        flag = false;
        for(size_t i = 0; i < arr.size() - 1; ++i){
            if(arr[i] > arr[i + 1]){
                int tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                flag = true;
            }
        }
    }
    return arr;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // vector<int> arr = {73, 42, 91, 56, 18, 64, 39, 27, 85, 12};
    // vector<int> arr = {38, 27, 43, 10};
    vector<int> arr;
    initialize_arr(arr);

    arr = merge_sort(arr);
    // arr = bubble_sort(arr);
    prty_vec(arr);

    cout << "Ended\n";
    return 0;
}