#include <iostream>
#include <vector>
#include <limits>  // Numeric_limits

using namespace std;

int findSecondMaximum(const vector<int>& arr) {
    if (arr.size() < 2) {
        // Handle the case where there are fewer than 2 elements
        cerr << "Array must have at least two elements." << endl;
        return numeric_limits<int>::min();  // Or another value to indicate error
    }

    // Initialize the two variables
    int max1 = numeric_limits<int>::min();
    int max2 = numeric_limits<int>::min();

    for (int num : arr) {
        if (num > max1) {
            // Update both max1 and max2
            max2 = max1;
            max1 = num;
        } else if (num > max2 && num < max1) {
            // Update only max2
            max2 = num;
        }
    }

    // Handle the case where there is no valid second maximum
    if (max2 == numeric_limits<int>::min()) {
        cerr << "No valid second maximum found." << endl;
        return numeric_limits<int>::min();  // Or another value to indicate error
    }

    return max2;
}

int main() {
    vector<int> arr = {10, 5, 7, 7, 9};

    int secondMax = findSecondMaximum(arr);

    if (secondMax != numeric_limits<int>::min()) {
        cout << "The second maximum value is: " << secondMax << endl;
    } else {
        cerr << "Error finding the second maximum value." << endl;
    }

    return 0;
}
