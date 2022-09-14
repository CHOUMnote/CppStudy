#include <iostream>
#include <array>    //�����迭
#include <vector>   //�����迭

int main(){
    //array 1.stack���� ���� �Ҵ� 2.�����Ͻ� �Ҵ� 3.���� �Ҵ�
    std::array<int,10> array = {9};
    // == int array[10] = {0}

    //vector 1.heap���� ���� �Ҵ� 2.��Ÿ�ӽ� �Ҵ� 3.�����Ҵ�?? -> �� ū �޸� Ȯ��� ���� �ʿ� (reserve()�� �ſ� ū �޸� �̸� �������� �ذ�)
    std::vector<int> vector1(3);
    std::vector<int> vector2{1,2,34,5,5,2,41,421};

    std::cout<<"array�׽�Ʈ\n";
    for(int i=0; i<array.size(); i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

    std::cout<<"vector1�׽�Ʈ\n";
    for(int i=0; i<vector1.size(); i++)
        std::cout << vector1[i] << " ";
    std::cout << std::endl;

    std::cout<<"vector2�׽�Ʈ\n";
    for(int i=0; i<vector2.size(); i++)
        std::cout << vector2[i] << " ";
    std::cout << std::endl;

    std::cout<<"vector1 ������ �߰� �׽�Ʈ\n";
    vector1.emplace_back(99999);
    for(int a:vector1)
        std::cout << a << " ";
    std::cout << std::endl;    

    std::cout<<"vector2 ������ ���� �׽�Ʈ\n";    
    vector2.pop_back();
    for(int a:vector2)
        std::cout << a << " ";
    std::cout << std::endl;    

    return 0;
}