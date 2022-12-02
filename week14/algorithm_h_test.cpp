#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(int value){ cout << value << " "; }
bool isEven(int value){ return (value % 2 == 0); }

int main(){
    vector<int> v({9,1,6,4,7,8,3,5,2,7,8,0});
    cout << "원본 배열 : ";
    for_each(v.begin(),v.end(), print); //콜백함수

    cout << endl;

    sort(v.begin(),v.end()); //정렬
    cout << "정렬 배열 : ";
    for_each(v.begin(),v.end(), print); 
    
    cout << endl;

    cout << "역순 배열 : ";
    reverse(v.begin(), v.end());    //뒤집기
    for_each(v.begin(),v.end(), print);

    cout << endl;

    cout << "회전 배열 : ";
    rotate(v.begin(), v.begin()+3, v.end());    //왼쪽으로 3번 회전 (시작을 3번 인덱스로 바꿈)
    for_each(v.begin(),v.end(), print);

    cout << endl;

    cout << "랜덤 정렬 : ";
    random_shuffle(v.begin(),v.end());
    for_each(v.begin(),v.end(), print);

    cout << endl;

    cout << "3의 갯수 : ";
    cout << count(v.begin(),v.end(),3);

    cout << endl;

    cout << "짝수 갯수 : ";
    cout << count_if(v.begin(), v.end(), isEven);  //콜백 리턴이 트루인거 갯수 카운트

    cout << endl;

    cout << "이진 탐색 :";
    sort(v.begin(),v.end()); //정렬
    cout << binary_search(v.begin(), v.end(), 8);   //이진 탐색 -> 정렬 필요

    cout << endl;

}