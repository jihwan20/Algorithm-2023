#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000

// 두 개의 정렬된 배열을 합치는 함수
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int LSize = mid - left + 1; // 왼쪽 배열의 크기
    int RSize = right - mid; // 오른쪽 배열의 크기

    // L, R 배열 동적 할당
    int* L = (int*)malloc(sizeof(int) * LSize);
    int* R = (int*)malloc(sizeof(int) * RSize);

    // 왼쪽 배열과 오른쪽 배열에 값을 저장
    for (i = 0; i < LSize; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < RSize; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    // 두 개의 배열을 하나로 합치기
    while (i < LSize && j < RSize) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 남은 원소가 있다면 배열에 추가
    while (i < LSize) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < RSize) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // 동적 할당한 배열 메모리 해제
    free(L);
    free(R);
}

// 합병 정렬 함수
void mergesort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // 중간값을 구함

        mergesort(arr, left, mid); // 왼쪽 배열을 정렬
        mergesort(arr, mid + 1, right); // 오른쪽 배열을 정렬

        merge(arr, left, mid, right); // 두 개의 배열을 합치기
    }
}

int main() {
    FILE* input, * output;
    int arr[MAX_SIZE], n = 0; // 입력 데이터를 저장할 배열과 배열의 크기

    input = fopen("data.txt", "r"); // 입력 파일 열기
    output = fopen("result.txt", "w"); // 출력 파일 열기

    // 파일에서 정수 읽어들이기
    while (fscanf(input, "%d", &arr[n]) != EOF) {
        n++;
    }

    mergesort(arr, 0, n - 1); // 합병 정렬 함수 호출

    // 정렬된 결과를 출력 파일에 저장
    for (int i = 0; i < n; i++) {
        fprintf(output, "%d ", arr[i]);
    }

    fclose(input); // 입력 파일 닫기
    fclose(output); // 출력 파일 닫기

    return 0;
}
