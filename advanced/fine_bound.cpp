#include <bits/stdc++.h>
using namespace std;

int LowerBound(vector<int> &v, const int x){  
    //x이상의 첫번째 값
    //v[mid-1]< x <=v[mid]
    const int n = v.size();
    int low = -1;
    int high = n;
    while(low+1 < high){
        int mid = (low+high)/2;
        if(!(v[mid] >= x)) //mid가 x보다 작음
            low = mid;  
        else //더 큼
            high = mid;
    }
    return high;    //x중 가장 먼저인 값 - high가 x를 포함 함
}

int UpperBound(vector<int> &v, const int x){
    //x(초과) 첫번재 값
    //v[mid-1] <= x < v[mid]
    const int n = v.size();
    int low = -1;
    int high = n;
    while(low+1 < high){
        int mid = (low + high) / 2;
        if (!(v[mid] > x)) //mid가 x보다 작거나 같음
            low = mid;
        else 
            high = mid;
    }
    return high; //high가 x를 포함하지 않고 그 다음 값
}
int main() {
    vector<int> v = { 1, 2, 3, 3, 4 };

    cout << LowerBound(v, 3) << '\n'; // 2 - 3의 시작점
    cout << UpperBound(v, 3) << '\n'; // 4 - 3의 바로 다음
    cout << UpperBound(v, 5) << '\n'; // 없음
    cout << UpperBound(v, 3) - LowerBound(v, 3) << '\n'; // 2 - 길이

    cout << "===============\n";
    //라이브 러리 사용
    auto a = lower_bound(v.begin(),v.end(), 2); 
    auto b = upper_bound(v.begin(),v.end(), 3);
    //2~3까지 범위
    for(auto i=a;i!=b;i++)
        cout << *i << " ";
        cout << endl;

}   