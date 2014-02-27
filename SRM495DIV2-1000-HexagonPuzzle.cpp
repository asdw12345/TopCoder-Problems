#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <functional>
#include <numeric>
#include <utility>
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

#define MOD 1000000007

using namespace std;

int state[55][55], vis[55][55];
typedef pair<int, int > PII;

class HexagonPuzzle {
public:
	int theCount(vector <string>);
};

int dir[6][4] = { {0, 1, 1, 1}, {0, -1, 1, 0}, {1, 0, 1, 1},
                 {-1, -1, -1, 0}, {-1, 0, 0, 0}, {-1, -1, 0, 0}};

int HexagonPuzzle::theCount(vector <string> board) {
	memset(state, 0, sizeof(state));
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < board.size()-1; i ++)
    {
        for(int j = 0; j < board[i].length(); j ++)
        {
            if(board[i][j] == 'X') continue;
            if(board[i][j+1] == '.' && board[i+1][j+1] == '.')
            {
                state[i][j] |= (1 << 0);
                state[i][j+1] |= (1 << 1);
                state[i+1][j+1] |= (1 << 3);
            }
            if(board[i+1][j] == '.' && board[i+1][j+1] == '.')
            {
                state[i][j] |= (1 << 2);
                state[i+1][j] |= (1 << 4);
                state[i+1][j+1] |= (1 << 5);
            }
        }
    }
    queue<PII> que;

    vector<int> vec;
    for(int i = 0; i < board.size(); i ++)
    {
        for(int j = 0; j < board[i].length(); j ++)
        {
            if(state[i][j] == 0 || vis[i][j]) continue;
            que.push(make_pair(i, j));
            vis[i][j] = 1;
            int tp = 0;
            while(!que.empty())
            {
                PII cur = que.front(); que.pop();
                tp++;
                vis[cur.first][cur.second] = 1;
                for(int i = 0; i < 6; i ++)
                {
                    if(!(state[cur.first][cur.second] & (1<<i))) continue;
                    int x, y;
                    x = cur.first + dir[i][0], y = cur.second + dir[i][1];
                    if(!vis[x][y])
                    {
                        vis[x][y] = 1;
                        que.push(make_pair(x, y));
                    }

                    x = cur.first + dir[i][2], y = cur.second + dir[i][3];
                    if(!vis[x][y])
                    {
                        vis[x][y] = 1;
                        que.push(make_pair(x, y));
                    }
                }
            }
            vec.push_back(tp);
        }
    }
    long long ret = 1;
    for(long long i = 0; i < vec.size(); i ++)
    {
        for(long long j = 3; j <= vec[i]; j ++)
        {
            ret = (j % (long long)MOD) * (ret % (long long)MOD) % (long long)MOD;
        }
    }
    return (int)ret;
}

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	string t0[] = {".",
 ".X",
 "X..",
 ".X.X"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonPuzzle * obj = new HexagonPuzzle();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"X"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonPuzzle * obj = new HexagonPuzzle();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {".",
 "..",
 "...",
 ".X.."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonPuzzle * obj = new HexagonPuzzle();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 20160;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {".",
 "..",
 "XXX",
 "..X.",
 ".X..X",
 "XXXX..",
 "..X.X.X",
 "..X.XX.."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonPuzzle * obj = new HexagonPuzzle();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 108;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {".",
 "..",
 "...",
 "....",
 ".....",
 "......",
 ".......",
 "........"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonPuzzle * obj = new HexagonPuzzle();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 261547992;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
//<%:end-tests%>
int main() {
	int time;
	bool errors = false;

	time = test0();
	if (time < 0)
		errors = true;

	time = test1();
	if (time < 0)
		errors = true;

	time = test2();
	if (time < 0)
		errors = true;

	time = test3();
	if (time < 0)
		errors = true;

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
