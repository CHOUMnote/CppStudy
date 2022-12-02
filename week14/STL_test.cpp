//간단 STL 공부
// 1. 컨테이너 : 자료구조들 -> 리스트, 스택, 큐, 집합, 맵 등등
// 2. iterator : 각 컨테이너들 원소들 포인터 container<T>::iteraor
// 3. 알고리즘 : 컨테이너에 대한 내장 함수 -> 복사, 정렬, 검색, 삭제 등등(algorithm 헤더에 존재)

#include <iostream>
#include <string>
//각 컨테이너 클래스 헤더 필요
#include <vector> //가변길이 배열
#include <map>    //딕셔너리

//알고리즘 헤더 필요
#include <algorithm>
#include <tuple>

using namespace std; // STL은 여기 포함

int main()
{
    //벡터 선언 방법
    vector<int> v1{};                         //빈 벡터
    vector<int> v2(4);                        //크기 선언
    vector<int> v3(10, 3);                    // 3으로 초기화
    vector<int> v4({1, 2, 3, 4, 5, 6, 7, 8}); // initerizer-list
    vector<int> v5 = {1, 2, 3, 4};            //유니폼 초기화

    v3.emplace_back(99999999);
    v3.at(1) = 4;                                                     // v3[1];
    for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) //이터레이터
        cout << *it << " ";
    cout << '\n';
    for (int i : v4) // foreach
        cout << i << ' ';
    cout << endl
         << endl;

    //데이터 쌍 표현 클래스
    // pair : 두 데이터 묶는다. first, second로 접근 utility에 있다.
    // tuple : 여러 데이터를 묶는다.    //get<int> 로 접근
    pair<string, int> person1{"Kim", 24};
    pair<string, int> person2 = make_pair("Lee", 26);
    // auto person3 = pair("Park"s, 22); //타입 자동 추론 - c++ 17
    tuple<string, int, string> t1{person1.first, person2.second, person2.first};
    tuple<string, int, string> t2 = t1;
    // auto [val1, val2, val3] = t2; //데이터 언박싱 - 자동추론  c++ 17

    // if (t1 == t2)
    //     cout << val1 << " " << val2 << ' ' << val3 << endl;
    cout << "t1의 첫 번째 값 : " << get<0>(t1) << endl;
    cout << "튜플의 원소 수 : " << tuple_size<decltype(t1)>::value << endl; // decltype대신 해당 튜플 제네릭 기입하면 됨
    cout << endl;

    // map - 딕셔너리
    //파이썬과 다르게 정렬(오름차순)
    map<string, int> m = {{"kim", 1}, {"lee", 2}}; //초기화 및 생성 - 집합 구조라 정렬
    m.insert(make_pair<string, int>("park", 3));   // pair 또는, initalizer_list bool
    m.emplace("kim", 4);                           // insert->복사,이동 수행 emplace->클래스 내에서 생성
    //중복시 삽입 x insert, emplace -> 삽입 성공 여부로 pair 리턴
    m["jo"] = 100;
    m["jo"] = 5; //없으면 넣고, 있으면 수정
    auto flag = m.insert({"kim", 99999});
    cout << flag.first->first << " " << flag.first->second << " " << flag.second << endl; //해당 이터레이터, 삽입 성공 여부 리턴
    for (map<string, int>::iterator lt = m.begin(); lt != m.end(); lt++)
        cout << lt->first << " " << lt->second << endl; //정렬!
}
