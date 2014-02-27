#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class PalindromfulString{
public :
    long long A[12];
    int N,M,K;

    bool chk(string str)
    {
        int cnt = 0;
        for(int i = 0 ;  i + M -1 < N ; i ++)
        {
            int L = i , R = i + M - 1;
            bool ok = true;
            while(L < R)
            {
                if(str[L] != str[R])
                {
                    ok = false;
                    break;
                }
                L ++;
                R --;
            }
            if(ok)
                cnt++;
        }
        return cnt >= K;
    }

    long long dfs(string str ,int cur , int used)
    {
        if(cur == N)
        {
            return chk(str) ? A[used] : 0;
        }
        long long ans = 0;
        for(int i = 0 ; i < used ; i ++)
        {
            ans += dfs(str + (char)('A' + i) , cur + 1 , used);
        }
        ans += dfs(str + (char)('A'+used) , cur+1 , used+1);
        return ans;
    }

    long long count(int _N, int _M, int _K)
    {
        N = _N;
        M = _M;
        K = _K;

        A[0] = 1;
        for(int i =  1; i <= N ; i ++)
        {
            A[i] = A[i-1] * (26-i+1);
        }
        return dfs("",0,0);
    }
};

//long long perm( long long n, long long k )
//{
//    long long r = 1;
//    for ( int i=0; i<k; i++ )
//        r *= n-i;
//    return r;
//}
//
//long long BT( string s )
//{
//    int n = (int)s.length();
//    char d = 'A'-1;
//    for ( int i=0; i<n; i++ )
//        d = max( d, s[i] );
//
//    if ( n >= N )
//    {
//        int c = 0;
//        for ( int i=0; i<=N-M; i++ )
//        {
//            int f = 1;
//            for ( int j=0; j<M/2; j++ )
//                if ( s[i+j] != s[i+M-j-1] )
//                    f = 0;
//            c += f;
//        }
//        if ( c >= K )
//            return perm(26,d-'A'+1);
//        else
//            return 0;
//    }
//
//    long long ans = 0;
//
//    for ( char c='A'; c<=d+1; c++ )
//        ans += BT(s+c);
//
//    return ans;
//}
//
//long long PalindromfulString::count(int N, int M, int K)
//{
//    ::N = N,  ::M = M,  ::K = K;
//    return BT("");
//}

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	int p0 = 2;
	int p1 = 2;
	int p2 = 1;
	PalindromfulString * obj = new PalindromfulString();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 26LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	int p1 = 2;
	int p2 = 0;
	PalindromfulString * obj = new PalindromfulString();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 676LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 3;
	int p1 = 2;
	int p2 = 1;
	PalindromfulString * obj = new PalindromfulString();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 1326LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 4;
	int p1 = 4;
	int p2 = 1;
	PalindromfulString * obj = new PalindromfulString();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 676LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 7;
	int p1 = 3;
	int p2 = 3;
	PalindromfulString * obj = new PalindromfulString();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 4310176LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
