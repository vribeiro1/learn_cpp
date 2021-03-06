#include <iostream>
#include <vector>

using namespace std;


vector<double> insertion_sort(vector<double> A) {
    int curr_elem;

    for (int j = 1; j < A.size(); j++) {
        curr_elem = A[j];

        int i = j - 1;
        while (i >= 0 && A[i] > curr_elem) {
            A[i + 1] = A[i];
            i--;
        }

        A[i + 1] = curr_elem;
    }

    return A;
}
