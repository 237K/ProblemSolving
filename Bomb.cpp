//
//  Bomb.cpp
//  ProblemSolving
//
//  OS macOS
//  Created by 형성모 on 02/02/2019.
//
//  [Algorithm Problem Solving]
//
//  <폭탄 실험>
//  1. A형 폭탄은 동, 서, 남, 북으로 각 1칸 씩 영향을 미침
//  2. B형 폭탄은 각 2칸 씩 영향
//  3. C형 폭탄은 각 3칸 씩 영향
//  4. 지도의 크기, 폭탄의 종류와 투하한 좌표를 입력받아서
//  5. 폭탄의 영향을 받지 않은 지역의 수를 출력
//
enum Bomb{Atype = 0, Btype = 1, Ctype = 2};

#include <iostream>
#include <fstream>
using namespace std;

class BombTest
{
private:
    bool **Map;
    pair<int, int> Location;        //폭탄을 투하하는 위치
    int Unaffected;
public:
};
