#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
using namespace std;

map<string, int> usrCnt;			 // ������ �Ű� ���� Ƚ���� ��� �迭
map<string, set<string>> usrReport;	 // ������ �Ű��� �ٸ� �������� ����� ��� �迭


vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;

	// �Ű� ���� �ޱ�
	for (string s : report) {
		int blank = s.find(' ');
		string first = s.substr(0, blank);
		string second = s.substr(blank);

		if (usrReport[first].find(second) == usrReport[first].end()) {
			usrReport[first].insert(second);
			usrCnt[second]++;
		}
	}

	// �Ű� ���� �����ϱ� _ ( k�� �̻� �Ű� ���� �� �Ű��ڿ� ���� �߼� )
	for (string usr_id : id_list) {
		int count = 0;  // �ް� �� ������ ��
		for (string s : usrReport[usr_id]) {	//usr_id�� �Ű��� �̷��� ��ȸ�ϸ�,
			if (usrCnt[s] >= k)	// �ش�(�Ű� ����) ������ �Ű� ���� Ƚ���� k�� �̻��̶�� �߼��ؾ��Ѵ�.
				count++;
		}
		answer.push_back(count);
	}

	return answer;
}

// Ȯ���غ���
int main() {
	vector<string> ex1;
	ex1.push_back("muzi");
	ex1.push_back("frodo");
	ex1.push_back("apeach");
	ex1.push_back("neo");

	vector<string> ex1_report;
	ex1_report.push_back("muzi frodo");
	ex1_report.push_back("apeach frodo");
	ex1_report.push_back("frodo neo");
	ex1_report.push_back("muzi neo");
	ex1_report.push_back("apeach muzi");

	vector<int> answer;
	answer = solution(ex1, ex1_report, 2);

	cout << '[' << ' ';
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' ';
	}
	cout << ']';
}