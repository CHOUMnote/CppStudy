#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(int value){ cout << value << " "; }
bool isEven(int value){ return (value % 2 == 0); }

int main(){
    vector<int> v({9,1,6,4,7,8,3,5,2,7,8,0});
    cout << "���� �迭 : ";
    for_each(v.begin(),v.end(), print); //�ݹ��Լ�

    cout << endl;

    sort(v.begin(),v.end()); //����
    cout << "���� �迭 : ";
    for_each(v.begin(),v.end(), print); 
    
    cout << endl;

    cout << "���� �迭 : ";
    reverse(v.begin(), v.end());    //������
    for_each(v.begin(),v.end(), print);

    cout << endl;

    cout << "ȸ�� �迭 : ";
    rotate(v.begin(), v.begin()+3, v.end());    //�������� 3�� ȸ�� (������ 3�� �ε����� �ٲ�)
    for_each(v.begin(),v.end(), print);

    cout << endl;

    cout << "���� ���� : ";
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(), print);

    cout << endl;

    cout << "3�� ���� : ";
    cout << count(v.begin(),v.end(),3);

    cout << endl;

    cout << "¦�� ���� : ";
    cout << count_if(v.begin(), v.end(), isEven);  //�ݹ� ������ Ʈ���ΰ� ���� ī��Ʈ

    cout << endl;

    cout << "���� Ž�� :";
    sort(v.begin(),v.end()); //����
    cout << binary_search(v.begin(), v.end(), 8);   //���� Ž�� -> ���� �ʿ�

    cout << endl;

}