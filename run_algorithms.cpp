#include <iostream>
#include <vector>
#include <limits>

#include "insertion_sort.h"
#include "merge_sort.h"
#include "maximum_subarray.h"

using namespace std;


void run_insertion_sort() {
    vector<double> A = {5, 2, 4, 7, 1, 3, 2, 6};

    vector<double> sorted_A = insertion_sort(A);

    for (int i = 0; i < sorted_A.size(); i++) {
        cout << sorted_A[i] << " ";
    }
    cout << endl;
}


void run_merge_sort() {
    vector<double> A = {5, 2, 4, 7, 1, 3, 2, 6};

    vector<double> sorted_A = merge_sort(A);

    for (int i = 0; i < sorted_A.size(); i++) {
        cout << sorted_A[i] << " ";
    }
    cout << endl;
}


void run_maximum_subarray() {
    vector<float> A = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    vector<float> maximum_subarray = find_maximum_subarray(A, 0, A.size());
    int left = int(maximum_subarray[0]);
    int right = int(maximum_subarray[1]);
    float sum = maximum_subarray[2];

    cout << left << " " << right << " " << sum << endl;
}

int main() {
    cout << "Insertion sort:" << endl;
    run_insertion_sort();
    cout << endl;

    cout << "Merge sort:" << endl;
    run_merge_sort();
    cout << endl;

    cout << "Maximum subarray:" << endl;
    run_maximum_subarray();
    cout << endl;

    return 0;
}
