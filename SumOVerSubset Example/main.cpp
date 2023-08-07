#include <bits/stdc++.h>
using namespace std;
int sos[1 << 3];
// function to print the sum over subsets value
void SumOverSubsets(int a[], int n) {

  // array to store the SumOverSubsets


  // iterate for all possible x
  for (int x = 0; x < (1 << n); x++) {
    sos[x] = a[0];

    // iterate for the bitwise subsets only
    for (int i = x; i > 0; i = (i - 1) & x)
      sos[x] += a[i];
  }

  // print all the subsets
  for (int i = 0; i < (1 << n); i++)
    cout << sos[i] << " ";
}
1 0 0 = 1
0 1 1 = 6
0 0 0 = 0
// Driver Code
int main() {//7 + 2. el seis + 5.el cuatro + 14.el dos
    //sol de 5 seria 7 * 12.el cinco + 5.el cuatro + 12.el uno
  int a[] = {7, 12, 14, 16, 5, 12, 2, 3};
  int n = 3;
  SumOverSubsets(a, n);
  return 0;
}
