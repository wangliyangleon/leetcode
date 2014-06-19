// https://oj.leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (0 == n) {
            return 0;
        }
        return maxSubArrayDivide(A, 0, n - 1);
    }

private:
    int maxSubArrayDivide(int A[], int start, int end) {
        if (start == end) {
            return A[start];
        } else if (start + 1 == end) {
            return std::max(A[start], std::max(A[end], A[start] + A[end]));
        } else {
            int mid = start + (end - start) / 2;
            int result_left = maxSubArrayDivide(A, start, mid - 1);
            int result_right = maxSubArrayDivide(A, mid + 1, end);
            int result_mid = A[mid], tmp = A[mid];
            for (int i = mid - 1; i >= start; --i) {
                tmp += A[i];
                if (tmp > result_mid) {
                    result_mid = tmp;
                }
            }
            tmp = result_mid;
            for (int i = mid + 1; i <= end; ++i) {
                tmp += A[i];
                if (tmp > result_mid) {
                    result_mid = tmp;
                }
            }
            return std::max(result_left, std::max(result_right, result_mid));
        }
    }
};
