// ���� 19636
#include <iostream>
#include <tuple>
#include <cmath> //abs(), floor()
using namespace std;

// w0: ü��, i0: ���� ������ ���뷮
// i: ���� ������ ���뷮(���̾�Ʈ), a: ���� Ȱ����緮(���̾�Ʈ)
// d: ���̾�Ʈ �ϼ�, t: ���ʴ�緮 ��ȭ ��ġ
tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t) {
	//w: ������, m: ���ʴ�緮
	int w1 = w0, m1 = i0; //���ʴ�緮�� ��ȭ ���x
	int w2 = w0, m2 = i0; //���ʴ�緮�� ��ȭ ���o

	while (d--) { //���̾�Ʈ �ϴ� ����
		// 1. ü�� ��ȭ
		// ü�� += ���� ������ ���뷮 - ���� ������ �Һ�
		// ���� ������ �Һ� = ���� ���ʴ�緮 + ���� Ȱ����緮
		w1 += (i - (m1 + a));
		w2 += (i - (m2 + a));

		// 2. ���ʴ�緮 ��ȭ(m2�� ��ȭ)
		if (abs(i - (m2 + a)) > t) { //���ʴ�緮 ��ȭ ��ġ ���
			m2 += floor(i - (m2 + a)) / 2; 
		}
	}

	return { w1, w2, m2 };
}

int main() {
	//�Է�
	int w0, i0, i, a, d, t;
	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a;

	//����
	tuple<int, int, int>ans = diet(w0, i0, i, a, d, t);
	int w1 = get<0>(ans), m1 = i0; //���ʴ�緮�� ��ȭ ���x
	int w2 = get<1>(ans), m2 = get<2>(ans); //���ʴ�緮�� ��ȭ ���o

	//���
	//���ʴ�緮 ��ȭ ���x
	if (w1 <= 0) { //������<=0
		cout << "Danger Diet\n";
	}
	else {
		cout << w1 << " " << m1 << "\n";
	}

	//���ʴ�緮 ��ȭ ���o
	if (w2 <= 0 || m2 <= 0) { //������ <=0||���ʴ�緮<=0
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