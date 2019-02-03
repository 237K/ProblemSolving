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
enum BombType{Atype = 0, Btype = 1, Ctype = 2};

#include <iostream>
#include <fstream>
using namespace std;

class Bomb
{
public:
    Bomb() {}
    virtual ~Bomb() {}
};

class BombAType : public Bomb
{
private:
    const int EffectArea;
public:
    
};

class BombBType : public Bomb
{
    
};

class BombCType : public Bomb
{
    
};

class BombTest
{
private:
    bool **Map;
    const int size;
    pair<int, int> Location;        //폭탄을 투하하는 위치
    int Unaffected;
    const char comma;
public:
    BombTest(const int _size) : size(_size), Location(pair<int, int>(0, 0)), Unaffected(0), comma(',')
    {
        Map = new bool* [_size];
        for(int init = 0 ; init < _size ; ++init)
        {
            Map[init] = new bool [_size];
        }
        for(int r = 0 ; r < _size ; ++r)
        {
            for(int c = 0 ; c < _size ; ++c)
            {
                Map[r][c] = false;
            }
        }
    }
    ~BombTest()
    {
        for(int del = 0 ; del < size ; ++del)
        {
            delete[] Map[del];
        }
        delete[] Map;
    }
    void MakeMap(ifstream& _in)
    {
        for(int i = 0 ; i < 3 ; ++i)
        {
            
        }
    }
};

int main(void)
{
    BombTest *BT[100];
    int testcase = 0;
    int MapSize = 0;
    ifstream in("testcase_Bomb.txt");
    in>>testcase;
    
    for(int tc = 1 ; tc <= testcase ; ++tc)
    {
        in>>MapSize;
        BT[tc] = new BombTest(MapSize);
        BT[tc]->MakeMap(in);
    }
    
    
    in.close();
    for(int del = 0 ; del < testcase ; ++del)
    {
        delete BT[del];
    }
    return 0;
}
