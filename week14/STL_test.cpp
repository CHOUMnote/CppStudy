//���� STL ����
// 1. �����̳� : �ڷᱸ���� -> ����Ʈ, ����, ť, ����, �� ���
// 2. iterator : �� �����̳ʵ� ���ҵ� ������ container<T>::iteraor
// 3. �˰��� : �����̳ʿ� ���� ���� �Լ� -> ����, ����, �˻�, ���� ���(algorithm ����� ����)

#include <iostream>
#include <string>
//�� �����̳� Ŭ���� ��� �ʿ�
#include <vector> //�������� �迭
#include <map>    //��ųʸ�

//�˰��� ��� �ʿ�
#include <algorithm>
#include <tuple>

using namespace std; // STL�� ���� ����

int main()
{
    //���� ���� ���
    vector<int> v1{};                         //�� ����
    vector<int> v2(4);                        //ũ�� ����
    vector<int> v3(10, 3);                    // 3���� �ʱ�ȭ
    vector<int> v4({1, 2, 3, 4, 5, 6, 7, 8}); // initerizer-list
    vector<int> v5 = {1, 2, 3, 4};            //������ �ʱ�ȭ

    v3.emplace_back(99999999);
    v3.at(1) = 4;                                                     // v3[1];
    for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) //���ͷ�����
        cout << *it << " ";
    cout << '\n';
    for (int i : v4) // foreach
        cout << i << ' ';
    cout << endl
         << endl;

    //������ �� ǥ�� Ŭ����
    // pair : �� ������ ���´�. first, second�� ���� utility�� �ִ�.
    // tuple : ���� �����͸� ���´�.    //get<int> �� ����
    pair<string, int> person1{"Kim", 24};
    pair<string, int> person2 = make_pair("Lee", 26);
    // auto person3 = pair("Park"s, 22); //Ÿ�� �ڵ� �߷� - c++ 17
    tuple<string, int, string> t1{person1.first, person2.second, person2.first};
    tuple<string, int, string> t2 = t1;
    // auto [val1, val2, val3] = t2; //������ ��ڽ� - �ڵ��߷�  c++ 17

    // if (t1 == t2)
    //     cout << val1 << " " << val2 << ' ' << val3 << endl;
    cout << "t1�� ù ��° �� : " << get<0>(t1) << endl;
    cout << "Ʃ���� ���� �� : " << tuple_size<decltype(t1)>::value << endl; // decltype��� �ش� Ʃ�� ���׸� �����ϸ� ��
    cout << endl;

    // map - ��ųʸ�
    //���̽�� �ٸ��� ����(��������)
    map<string, int> m = {{"kim", 1}, {"lee", 2}}; //�ʱ�ȭ �� ���� - ���� ������ ����
    m.insert(make_pair<string, int>("park", 3));   // pair �Ǵ�, initalizer_list bool
    m.emplace("kim", 4);                           // insert->����,�̵� ���� emplace->Ŭ���� ������ ����
    //�ߺ��� ���� x insert, emplace -> ���� ���� ���η� pair ����
    m["jo"] = 100;
    m["jo"] = 5; //������ �ְ�, ������ ����
    auto flag = m.insert({"kim", 99999});
    cout << flag.first->first << " " << flag.first->second << " " << flag.second << endl; //�ش� ���ͷ�����, ���� ���� ���� ����
    for (map<string, int>::iterator lt = m.begin(); lt != m.end(); lt++)
        cout << lt->first << " " << lt->second << endl; //����!
}
