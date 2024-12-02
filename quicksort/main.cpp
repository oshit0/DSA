#include <iostream>
#include <cstdio>
#include <vector>
#include <cctype>
#include <chrono>
#include <random>
#include <fstream>
#include <sstream>

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

void prty_vec(const vector<int> arr){
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

void print_vec(const vector<int> arr){
    for(int val: arr){
        cout << val << ' ';
    }
    cout << endl;
}

int rand_pivot(int start, int end){
    const uint_least32_t seed = static_cast<uint_least32_t>(time(nullptr));
    mt19937 generator(seed);
    // Do not forget to reduce len if you are not decrementing arr.size() before calling.
    uniform_int_distribution<uint_least32_t> distribute(start, end);
    return distribute(generator);
}

void quicksort(vector<int> &arr, int start, int end){
    if(start >= end) return;
    int pivot = arr[rand_pivot(start, end - 1)];
    int i = start - 1;
    int j = end + 1;
    int tmp;
    while(true){
        do i++; while(arr[i] < pivot);
        do j--; while(arr[j] > pivot);
        if(i >= j) break;
        tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
    quicksort(arr, start, j);
    quicksort(arr, j + 1, end);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // vector<int> arr = {73, 42, 91, 56, 18, 64, 39, 27, 85, 12};
    vector<int> arr;
    initialize_arr(arr);

    quicksort(arr, 0, arr.size() - 1);
    print_vec(arr);

    return 0;
}