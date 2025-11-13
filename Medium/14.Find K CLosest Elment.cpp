#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int lo = 0, hi = n - k; // possible start indices for the k-length window

        // Binary search for the smallest start index such that the window [start, start+k-1]
        // is the best (closest to x). Compare distance from x to the two endpoints.
        while (lo < hi) {
            cout<<"LOW:"<<lo<<endl;
            int mid = lo + (hi - lo) / 2;
            // If arr[mid] is farther from x than arr[mid+k], shift right, else shift left
            if (x - arr[mid] > arr[mid + k] - x) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        // Collect k elements starting at lo
        return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
    }
};
