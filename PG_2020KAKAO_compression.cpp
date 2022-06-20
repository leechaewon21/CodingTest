#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    string input;
    cin >> input;

    int min_len=input.length();

    // �ݺ��Ǵ� ���ڿ� ���̸� ���ϴ� �ݺ���
    for(int sz=1; sz<=input.length()/2; sz++) {

        string before_part = ""; //���� ���� ����
        int before_part_count = 0; //���� �������� ��� ���ӵǾ�����
        int now_len = 0; //������� ����� ���ڿ� ����

        int posi=0; //���� ��ġ
        while(posi<=input.length()-sz) { //���� ������ �ݺ��Ǵ� ���ڿ� ���̺��� ������ �ȵȴ�

            string part = input.substr(posi,sz); //���� ����

            // ���� ������ �ִ��� ������
            if(posi==0) {
                before_part_count=1;
                before_part = part;
            }
            else {

                // ���� �����̶� ������ �� ������
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

            // ������������ �̵�
            posi = posi+sz;
        }


        //�ݺ��� �����鼭 �ذ���� �κ� update
        if(before_part_count!=1) now_len = now_len + (to_string(before_part_count).length());
        now_len = now_len + before_part.length();

        //������ �ش���� ���� ���ڵ� update
        now_len = now_len + (input.length()-posi);


        //����
        if(now_len < min_len) min_len = now_len;
    }

    cout <<min_len;

    return 0;
}
