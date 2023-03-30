#include <stdio.h>

void findFakeCoin(int* coin, int left, int right);

void findFakeCoin(int* coin, int left, int right){

    int count = 0;
    int sum1, sum2;
    int mid;
    whilt(left < right) 
        count++;
        sum1 = 0;
        sum2 = 0;
        mid = (left + right) / 2;
        for (int i = left; i <= right; i++) {
            if (i <= mid) sum1 += coin[i];
            else sum2 += coin[i];
        }
        if (sum1 < sum2) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
}


int main() {
    find_FakeCoin();
    return 0;
}