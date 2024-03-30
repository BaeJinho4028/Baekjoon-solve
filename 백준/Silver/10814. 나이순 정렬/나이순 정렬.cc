#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct information
{
    int age;
    string name;
    int index;
};

bool compare(information p1, information p2)
{
    if (p1.age == p2.age)
    {
        return p1.index < p2.index;
    }
    else
    {
        return p1.age < p2.age;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;

    cin >> N; // 회원의 수
    vector<information> v(N); // 회원들의 정보를 담을 벡터 생성

    for (int i = 0; i < N; ++i) // 정보를 입력받아 벡터에 저장
    {
        cin >> v[i].age >> v[i].name;
        v[i].index = i;
    }

    // 저장된 정보들을 정렬(나이 순, 나이가 같으면 가입 순)
    sort(v.begin(), v.end(), compare);

    // 출력
    for (int i = 0; i < N; ++i)
    {
        cout << v[i].age << " " << v[i].name << "\n";
    }






    return 0;
}