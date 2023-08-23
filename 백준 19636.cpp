// 백준 19636
#include <iostream>
#include <tuple>
#include <cmath> //abs(), floor()
using namespace std;

// w0: 체중, i0: 일일 에너지 섭취량
// i: 일일 에너지 섭취량(다이어트), a: 일일 활동대사량(다이어트)
// d: 다이어트 일수, t: 기초대사량 변화 역치
tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t) {
	//w: 몸무게, m: 기초대사량
	int w1 = w0, m1 = i0; //기초대사량의 변화 고려x
	int w2 = w0, m2 = i0; //기초대사량의 변화 고려o

	while (d--) { //다이어트 하는 동안
		// 1. 체중 변화
		// 체중 += 일일 에너지 섭취량 - 일일 에너지 소비량
		// 일일 에너지 소비량 = 일일 기초대사량 + 일일 활동대사량
		w1 += (i - (m1 + a));
		w2 += (i - (m2 + a));

		// 2. 기초대사량 변화(m2만 변화)
		if (abs(i - (m2 + a)) > t) { //기초대사량 변화 역치 고려
			m2 += floor(i - (m2 + a)) / 2; 
		}
	}

	return { w1, w2, m2 };
}

int main() {
	//입력
	int w0, i0, i, a, d, t;
	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a;

	//연산
	tuple<int, int, int>ans = diet(w0, i0, i, a, d, t);
	int w1 = get<0>(ans), m1 = i0; //기초대사량의 변화 고려x
	int w2 = get<1>(ans), m2 = get<2>(ans); //기초대사량의 변화 고려o

	//출력
	//기초대사량 변화 고려x
	if (w1 <= 0) { //몸무게<=0
		cout << "Danger Diet\n";
	}
	else {
		cout << w1 << " " << m1 << "\n";
	}

	//기초대사량 변화 고려o
	if (w2 <= 0 || m2 <= 0) { //몸무게 <=0||기초대사량<=0
		cout << "Danger Diet";
	}
	else { 
		cout << w2 << " " << m2;
		if (m2 < i0)
			cout << " YOYO";
		else
			cout << " NO";
	}

	return 0;
}