#include <string>
#include <vector>

using namespace std;

vector <int> solution(vector<string> id_list, vector<string> report, int k) {
    int id_size = id_list.size();
    vector<int> answer(id_size, 0); 
    vector<int> count(id_size, 0); //신고받은 횟수 저장 
    vector<string> save(id_size, "-");//각 사용자가 신고한 사용자 저장
    string id, re;

    for (int i = 0; i < report.size(); i++) {
        int temp = report[i].find(" ");

        id = report[i].substr(0, temp); //사용자
        re = report[i].substr(temp + 1); //신고자

        for (int j = 0; j < id_size; j++) {

            if (id_list[j] == id && save[j].find(re) == -1) {
                save[j] += re;

                for (int p = 0; p < id_size; p++) {
                    if (id_list[p] == re)
                        count[p]++;
                }
            }
        }
    
    for (int q = 0; q < id_size; q++) {
        if (k <= count[q]) { //신고받은 횟수가 k보다 크면, 해당 이름을 신고한 사용자 찾아 answer[q] ++
            for (int i = 0; i < save.size(); i++) {
                if (save[i].find(id_list[q]) != -1) {
                    answer[i]++;

                }
            }
        }

    }

    return answer;
}
