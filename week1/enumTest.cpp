#include <iostream>
using namespace std;

//enum class�� ����� ����ȯ �׽�Ʈ
//1. ����ȯ�� �ǵ�ġ ���� ������ ���� �ؾ��Ѵ�.
//2. enum class�� ����ϸ� c�� enum�� �޸� �ٸ� �����̽��� ����ؼ� �� �� ����ġ ���� ������ ���� �� �ִ�. 
//���� c enum�� ���� ������ ����üũ -> ����, ����
//class�� �������� class�� �ƴϴ�. �ܼ� ����
int main(){
    enum class Color {Blue=1, Red, Green, other=100};

    Color color = Color::Blue;
    cout << "enum class ���� ��ȯ : " << static_cast<int>(color) << endl;
    cout << static_cast<int>(Color::Blue) << endl;
    cout << static_cast<int>(Color::Red) << endl;
    cout << static_cast<int>(Color::Green) << endl;
    cout << static_cast<char>(Color::other) << endl;

    return 0;
}
