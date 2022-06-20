#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    string input;
    cin >> input;

    int min_len=input.length();

    // 반복되는 문자열 길이를 정하는 반복문
    for(int sz=1; sz<=input.length()/2; sz++) {

        string before_part = ""; //이전 조각 저장
        int before_part_count = 0; //같은 조각들이 몇번 연속되었는지
        int now_len = 0; //현재까지 압축된 문자열 길이

        int posi=0; //현재 위치
        while(posi<=input.length()-sz) { //남은 조각이 반복되는 문자열 길이보다 작으면 안된다

            string part = input.substr(posi,sz); //현재 조각

            // 이전 조각이 있는지 없는지
            if(posi==0) {
                before_part_count=1;
                before_part = part;
            }
            else {

                // 이전 조각이랑 같은지 안 같은지
                if(before_part==part) before_part_count++;
                else {

                    //len update
                    if(before_part_count!=1) now_len = now_len + (to_string(before_part_count).length());
                    now_len = now_len + before_part.length();

                    //init
                    before_part_count=1;
                    before_part=part;
                }
            }

            // 다음조각으로 이동
            posi = posi+sz;
        }


        //반복문 나오면서 해결못한 부분 update
        if(before_part_count!=1) now_len = now_len + (to_string(before_part_count).length());
        now_len = now_len + before_part.length();

        //조각에 해당되지 못한 문자들 update
        now_len = now_len + (input.length()-posi);


        //갱신
        if(now_len < min_len) min_len = now_len;
    }

    cout <<min_len;

    return 0;
}
