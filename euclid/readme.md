# 알고리즘 설계 구현 결과 : <최대공약수>

<문제 정의>

문제이름: 최대공약수 찾기

문제설명: 임의의 두 정수의 최대 공약수를 찾는다.

문제예시: 24와 14의 최대공약수는 2이다.

<알고리즘>

명칭: 최대공약수(Euclid)

입력: 정수 a, b 단, a>=b>=0

출력: 최대공약수(a, b)

### 재귀적방법

의사코드


int recursiveEuclid(int a, int b)
{
    if (b == 0) return a;
    return recursiveEuclid(b, a % b);
}


순서도

![재귀적 함수](https://user-images.githubusercontent.com/90670592/232190587-a4e73e0d-5274-4337-aeda-79f76e8f8b5d.png)

처리순서:
1. 최대공약수(a, b)
2. 최대공약수(b, a mod b)
3. b가 0이 될때까지 반복한다.

반복적 방법 의사코드

int repetitiveEuclid(int a, int b)
{
    int gcd;

    while (b != 0) {
        gcd = b;
        b = a % b;
        a = gcd;
    }
    return a;
}

반복적 방법 처리순서:
1. 최대공약수(a, b)
2. b 위치에 a와 b를 나눈 나머지 값을 놓는다.
3. a 위치에 b를 놓는다.
4. b가 0이 아니면 계속해서 반복한다.

<코드 설계>
1. 자료 구조 정의
- 임의의 두 수 : a, b(int)
- 최대공약수 :euclid(a, b)

2. 함수 정의
- 기능: 두 수의 최대공약수 계산
- 프로토타입: int testEuclid()

3. 테스트 케이스 설계
TC1. 재귀적 방법과 반복적 방법으로 2가지 함수 구현하고 테스트 코드 작성한다.
TC2. 매우 큰 두 수의 쌍 N개를 rand 함수를 이용해 만들어 반복적으로 실행하고 두 방법의 값이 같은지 체크하고 모두 마칠 때까지의 실행시간을 비교한다.

<C코드 구현 결과>

// TC1. 재귀적 방법과 반복적 방법으로 2가지 함수 구현하고 테스트 코드 작성한다.

// 재귀적 방법

	int recursiveEuclid(int a, int b) {
	    if (b == 0) return a;
	    return recursiveEuclid(b, a % b);
	}
	
// 반복적 방법

	int repetitiveEuclid(int a, int b) {
	    int gcd;

	    while (b != 0) {
		gcd = b;
		b = a % b;
		a = gcd;
	    }
	    return a;
	}
	
// 테스트 코드

	int testEuclid() {
		int a = 24;
		int b = 14;
		int gcd_rec, gcd_rep; // 각 함수의 결과값

		gcd_rec = recursiveEuclid(a, b);
		gcd_rep = repetitiveEuclid(a, b);

		printf("재귀적 방법(%d %d) : %d\n", a, b, gcd_rec);
		printf("반복적 방법(%d %d) : %d\n", a, b, gcd_rep);

		return 0;
	}
	
// TC2: 테스트 코드2

// 매우 큰 두 수의 쌍 N개를 rand 함수를 이용해 만들어 반복적으로 실행하고 두 방법의 값이 같은지 체크하고 모두 마칠 때까지의 실행시간을 비교한다.

	int testEuclid2() {

		int n = 1000;
		int a, b; // 임의의 숫자
		clock_t start, end;
		int rec_result, rep_result;
		double rec_time, rep_time;	// 각 함수의 실행시간

		// 랜덤한 매우 큰 두 수의 쌍 N개 생성
		srand(time(NULL));
		printf("랜덤 번호 :\n");
		for (int i = 0; i < n; i++) {
			a = rand() % 100000000 + 1;
			b = rand() % 100000000 + 1;
			printf("%d %d\n", a, b);
		}
		printf("\n");

		// 재귀적 방법으로 각 쌍의 최대공약수 계산
		start = clock(); // 수행 시간 측정 시작
		for (int i = 0; i < n; i++) {
			a = rand() % 100000000 + 1;
			b = rand() % 100000000 + 1;
			rec_result = recursiveEuclid(a, b);
		}
		end = clock(); // 수행 시간 측정 종료
		rec_time = (double)(end - start) / CLOCKS_PER_SEC;

		// 반복적 방법으로 각 쌍의 최대공약수 계산
		start = clock(); // 수행 시간 측정 시작
		for (int i = 0; i < n; i++) {
			a = rand() % 100000000 + 1;
			b = rand() % 100000000 + 1;
			rep_result = repetitiveEuclid(a, b);
		}
		end = clock(); // 수행 시간 측정 종료
		rep_time = (double)(end - start) / CLOCKS_PER_SEC;

		if (rec_result != rep_result) {
			printf("두 함수의 결과값이 다릅니다.");
		}
		else {
			// 결과 출력
			printf("재귀적 방법 결과값 : %d, 재귀적 방법 걸린 시간: %f sec\n", rec_result, rec_time);
			printf("반복적 방법 결과값 : %d, 반복적 방법 걸린 시간: %f sec\n", rep_result, rep_time);
		}
		return 0;
	}
	
// 메인 함수

	int main(void) {
		testEuclid1();
		testEuclid2();

		return 0;
	}
