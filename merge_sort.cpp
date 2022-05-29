#include<bits/stdc++.h>
using namespace std;

vector<int> merge(vector<int> A, vector<int> B) {
    vector<int> result;
    int p1 = 0;
    int p2 = 0;

    while(p1 < A.size() && p2 < B.size()) {
        if(A[p1] < B[p2]) {
            result.push_back(A[p1]);
            p1++;
        }
        else {
            result.push_back(B[p2]);
            p2++;
        }
    }
    while(p1 < A.size()) {
        result.push_back(A[p1]);
        p1++;
    }
    while(p2 < B.size()) {
        result.push_back(B[p2]);
        p2++;
    }

    return result;
}

// return sorted array
vector<int> merge_sort(vector<int> A) {

    int N = A.size();

    if(N == 1) return A;

    int mid = N / 2;

    assert(N > 1);

    vector<int> left(A.begin(), A.begin() + mid);
    vector<int> right(A.begin() + mid, A.end());

    vector<int> sorted_left = merge_sort(left);
    vector<int> sorted_right = merge_sort(right);

    vector<int> result = merge(sorted_left, sorted_right);

    return result;
}

int main() {

    vector<int> a = {100, 20, 50, 1, 15, 69};

    vector<int> sorted_a = merge_sort(a);

    for(int num: sorted_a) cout << num << " ";

    return 0;
}