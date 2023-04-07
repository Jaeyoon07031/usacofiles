#include <bits/stdc++.h>
using namespace std;

int main() {
  // Read input
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Divide the array into k subarrays
  sort(a.begin(), a.end());
  vector<vector<int>> subarrays;
  for (int i = 0; i < n; i += n / k) {
    subarrays.push_back(vector<int>(a.begin() + i, a.begin() + i + n / k));
  }

  // Adjust the division by moving one element from the subarray
  // with the largest sum to one of the other subarrays
  while (true) {
    // Find the subarray with the largest sum
    int max_sum = 0;
    for (const auto& subarray : subarrays) {
      max_sum = max(max_sum, accumulate(subarray.begin(), subarray.end(), 0));
    }

    // Check if all the subarrays have the same sum
    if (all_of(subarrays.begin(), subarrays.end(), [&](const auto& subarray) {
          return accumulate(subarray.begin(), subarray.end(), 0) == max_sum;
        })) {
      break;
    }

    // Move one element from the subarray with the largest sum
    // to one of the other subarrays
    for (int i = 0; i < subarrays.size(); i++) {
      if (accumulate(subarrays[i].begin(), subarrays[i].end(), 0) == max_sum) {
        for (int j = 0; j < subarrays.size(); j++) {
          if (i != j &&
              accumulate(subarrays[j].begin(), subarrays[j].end(), 0) != max_sum) {
            subarrays[j].push_back(subarrays[i].back());
            subarrays[i].pop_back();
            break;
          }
        }
        break;
      }
    }
  }

  // Print the maximum sum in a subarray
  int max_sum = 0;
  for (const auto& subarray : subarrays) {
    max_sum = max(max_sum, accumulate(subarray.begin(), subarray.end(), 0));
  }
  cout << max_sum << endl;

  return 0;
}
