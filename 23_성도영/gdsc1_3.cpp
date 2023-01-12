#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0;
	int haveToFind = 1; // �� ������ 0�� �� ��, x�� x�� �ƴ� ������ ������ ��������
	int first_idx = 0;
	int SECOND_IDX = 1;

	string X = s.substr(first_idx, SECOND_IDX);

	for (first_idx = 1; first_idx < s.size(); first_idx++) {
		if (s.substr(first_idx, SECOND_IDX) == X) {
			haveToFind++;
		}
		else {
			haveToFind--;
	
			if (haveToFind == 0) {
				answer++;
				
				if (first_idx != s.size() - 1) {
					// ���ο� X�� ���� ����
					int newFirst_idx = first_idx + 1;
					X = s.substr(newFirst_idx, SECOND_IDX);
				}
			}
		}
	}

	if (haveToFind != 0)
		answer++;

	return answer;
}

int main() {

	int result = solution("banana");
	int result2 = solution("abracadabra");
	int result3 = solution("aaabbaccccabba");
	cout << result << '\n';
	cout << result2 << '\n';
	cout << result3 << '\n';
}