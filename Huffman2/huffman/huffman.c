#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct _HNode {
    char str;
    int freq;
    struct _HNode* left;
    struct _HNode* right;
} HNode;

typedef struct _PQNode {
    struct _HNode* node;
    struct _PQNode* next;
} PQNode;

typedef struct _PQueue {
    struct _PQNode* head;
} PQueue;

void create_inputFile() {

    FILE* input;
    char str[MAX_SIZE];

    input = fopen("input.txt", "w");
    if (input == NULL) {
        printf("입력 파일 열기 오류.\n");
        return;
    }

    printf("텍스트를 입력하세요: ");
    fgets(str, sizeof(str), stdin);

    // 개행 문자 제거
    str[strcspn(str, "\n")] = '\0';

    fprintf(input, "%s", str);

    fclose(input);
}

void cal_freq(char* input, int* freq) {
    int i = 0;
    while (input[i] != '\0') {
        unsigned char c = input[i];
        freq[c]++;
        i++;
    }
}

void sort_freq(int* freq, char* str, int num) {
    int i, j;
    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (freq[j] < freq[i]) {
                int tempF = freq[i];
                freq[i] = freq[j];
                freq[j] = tempF;

                char tempC = str[i];
                str[i] = str[j];
                str[j] = tempC;
            }
        }
    }
}

void cal_strFreq(const char* filename) {
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("error.\n");
        return;
    }

    int freq[MAX_SIZE] = { 0 };

    char input[MAX_SIZE];
    fgets(input, MAX_SIZE, inputFile);
    fclose(inputFile);

    cal_freq(input, freq);

    char str[MAX_SIZE];
    int num = 0;
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (freq[i] > 0) {
            str[num++] = (char)i;
        }
    }

    sort_freq(freq, str, num);

    FILE* outputFile = fopen("stats.txt", "w");
    if (outputFile == NULL) {
        printf("error.\n");
        return;
    }

    for (i = 0; i < num; i++) {
        fprintf(outputFile, "%c\t%d\n", str[i], freq[str[i]]);
    }

    fclose(outputFile);
}

HNode* create_node(char str, int freq) {
    HNode* node = (HNode*)malloc(sizeof(HNode));
    node->str = str;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void enqueue(PQueue* queue, HNode* node) {
    PQNode* newNode = (PQNode*)malloc(sizeof(PQNode));
    newNode->node = node;
    newNode->next = NULL;

    if (queue->head == NULL) {
        queue->head = newNode;
    }
    else {
        if (node->freq < queue->head->node->freq) {
            newNode->next = queue->head;
            queue->head = newNode;
        }
        else {
            PQNode* current = queue->head;
            while (current->next != NULL && current->next->node->freq <= node->freq) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

HNode* dequeue(PQueue* queue) {
    if (queue->head == NULL) {
        return NULL;
    }

    HNode* node = queue->head->node;
    PQNode* temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
    return node;
}

HNode* build_Htree(char strs[], int freq[], int size) {
    PQueue* queue = (PQueue*)malloc(sizeof(PQueue));
    queue->head = NULL;

    for (int i = 0; i < size; i++) {
        HNode* node = create_node(strs[i], freq[i]);
        enqueue(queue, node);
    }

    while (queue->head->next != NULL) {
        HNode* left = dequeue(queue);
        HNode* right = dequeue(queue);

        HNode* newNode = create_node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        enqueue(queue, newNode);
    }

    HNode* root = dequeue(queue);
    free(queue);
    return root;
}

void build_Codes(HNode* root, int code[], int top) {
    if (root->left != NULL) {
        code[top] = 0;
        build_Codes(root->left, code, top + 1);
    }

    if (root->right != NULL) {
        code[top] = 1;
        build_Codes(root->right, code, top + 1);
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->str);
        for (int i = 0; i < top; i++) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

void compress_file() {
    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.huf", "wb");

    if (inputFile == NULL || outputFile == NULL) {
        printf("error.\n");
        return;
    }

    int freq[MAX_SIZE] = { 0 };
    char input[MAX_SIZE];
    fgets(input, MAX_SIZE, inputFile);
    fclose(inputFile);

    cal_freq(input, freq);

    char str[MAX_SIZE];
    int num = 0;
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (freq[i] > 0) {
            str[num++] = (char)i;
        }
    }

    sort_freq(freq, str, num);

    HNode* root = build_Htree(str, freq, num);

    int code[MAX_SIZE] = { 0 };
    build_Codes(root, code, 0);

    unsigned char bitBuffer = 0;
    int bitsInBuffer = 0;

    for (i = 0; i < strlen(input); i++) {
        char ch = input[i];
        for (int j = 0; j < num; j++) {
            if (ch == str[j]) {
                int codeLength = 0;
                HNode* currentNode = root;
                while (currentNode->str != ch) {
                    if (code[codeLength] == 0)
                        currentNode = currentNode->left;
                    else
                        currentNode = currentNode->right;

                    codeLength++;
                }

                for (int k = 0; k < codeLength; k++) {
                    bitBuffer <<= 1;
                    bitBuffer |= (code[k] & 1);
                    bitsInBuffer++;

                    if (bitsInBuffer == 8) {
                        fwrite(&bitBuffer, sizeof(unsigned char), 1, outputFile);
                        bitBuffer = 0;
                        bitsInBuffer = 0;
                    }
                }
                break;
            }
        }
    }

    if (bitsInBuffer > 0) {
        bitBuffer <<= (8 - bitsInBuffer);
        fwrite(&bitBuffer, sizeof(unsigned char), 1, outputFile);
    }

    fclose(outputFile);

}

void decompress_file() {
    FILE* inputFile = fopen("output.huf", "rb");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("error.\n");
        return;
    }

    int freq[MAX_SIZE] = { 0 };
    char str[MAX_SIZE];
    int num = 0;

    unsigned char ch;
    while (fread(&ch, sizeof(unsigned char), 1, inputFile) > 0) {
        for (int i = 7; i >= 0; i--) {
            int bit = (ch >> i) & 1;
            freq[str[num]]++;
            if (bit == 0) {
                if (str[num] != '\0') {
                    fprintf(outputFile, "%c", str[num]);
                }
                num = 0;
            }
            else {
                num++;
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    create_inputFile();
    cal_strFreq("input.txt");
    compress_file();
    decompress_file();

    return 0;
}
