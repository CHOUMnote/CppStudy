#include <string>
#include <iostream>

using namespace std;

template <typename T, int size>
decltype(auto) add(const T (&data)[size])   //&data TŸ�� �迭�� ���� ����
{                 //TŸ�� �迭�� ���� ����
    T sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += data[i];
    }
    return sum; //�����Ϸ��� �Լ��� ���� Ÿ���� �ڵ����� �߷�
}

template <typename T, int size = 10> //�⺻ �Ű����� ����
decltype(auto) print(T a)
{
    for (int i = 0; i < size; i++)
        cout << i;
}

//���ø� �Լ� ��ȯ Ÿ��
//1. auto : ���� �� ��ȯ -> const & ����
//2. decltype(auto) : const, & ��ȯ
template<typename T>
decltype(auto) add(T a, T b){
    cout << "1�� ���ø� �Լ� : ";
    return a+b;
}
template <typename T>
decltype(auto) add(T a, T b, T c){
    cout << "2�� ���ø� �Լ� : ";
    return a+b+c;
}
int main()
{
    int x[5] = {1, 2, 3, 4, 5};
    double d[6] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7};
    // �Լ� ���ø��� ȣ���� �� �����Ϸ��� T�� ��ü���� �� �Ӹ� �ƴ϶� size �� �߷�
    cout << "sum of x[] = " << add(x) << endl; //�Ǵ� add<int>(x);
    cout << "sum of d[] = " << add(d) << endl;
    
    print<int>(1);
    cout << endl;
    print<int,5>(1);

    cout << endl;
    cout << add(1,2) << endl;
    cout << add(1,2,3) << endl;
}