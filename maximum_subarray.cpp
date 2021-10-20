#include <iostream>
#include <vector>
#include <limits>

using namespace std;


vector<float> find_maximum_crossing_subarray(vector<float> A, int low, int mid, int high) {
    int max_left;
    int max_right;

    float left_sum = -numeric_limits<float>::infinity();
    float right_sum = -numeric_limits<float>::infinity();

    float sum = 0;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        if (sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }

    sum = 0;
    for (int j = mid + 1; j < high; j++) {
        sum += A[j];
        if (sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }

    return {float(max_left), float(max_right), left_sum + right_sum};
}


vector<float> find_maximum_subarray(vector<float>A, int low, int high) {
    if (high == low) {
        return {float(low), float(high), A[low]};
    } else {
        int mid = (low + high) / 2;

        vector<float> left_maximum_subarray = find_maximum_subarray(A, low, mid);
        float left_low = left_maximum_subarray[0];
        float left_high = left_maximum_subarray[1];
        float left_sum = left_maximum_subarray[2];

        vector<float> right_maximum_subarray = find_maximum_subarray(A, mid + 1, high);
        float right_low = right_maximum_subarray[0];
        float right_high = right_maximum_subarray[1];
        float right_sum = right_maximum_subarray[2];

        vector<float> cross_maximum_subarray = find_maximum_crossing_subarray(A, low, mid, high);
        float cross_low = cross_maximum_subarray[0];
        float cross_high = cross_maximum_subarray[1];
        float cross_sum = cross_maximum_subarray[2];

        if (left_sum > right_sum && left_sum > cross_sum) {
            return {float(left_low), float(left_high), left_sum};
        } else if (right_sum > left_sum && right_sum > cross_sum) {
            return {float(right_low), float(right_high), right_sum};
        } else {
            return {float(cross_low), float(cross_high), cross_sum};
        }
    }
}
