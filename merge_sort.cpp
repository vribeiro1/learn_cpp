#include <iostream>
#include <vector>
#include <limits>

using namespace std;


vector<double> merge(vector<double> A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<double> L(n1 + 1);
    vector<double> R(n2 + 1);

    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = A[q + j + 1];
    }

    L[n1] = numeric_limits<double>::infinity();
    R[n2] = numeric_limits<double>::infinity();

    int i = 0;
    int j = 0;

    for (int k = p; k <= r; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }

    return A;
}


vector<double> merge_sort(vector<double> A, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;

        A = merge_sort(A, p, q);
        A = merge_sort(A, q + 1, r);
        A = merge(A, p, q, r);
    }

    return A;
}


vector<double> merge_sort(vector<double> A) {
    return merge_sort(A, 0, A.size() - 1);
}
