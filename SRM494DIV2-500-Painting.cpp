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

class Painting {
public:
	int largestBrush(vector <string>);
};
#define INF 0x3f3f3f3f
#define MAXN 100
int num[MAXN][MAXN];
int Painting::largestBrush(vector <string> picture)
{
    int n=picture.size(),m=picture[0].size();
    int i,j,ii,jj,pos;
    for(i=0;i<MAXN;i++)
        for(j=0;j<MAXN;j++)
            num[i][j]=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(picture[i][j]=='B')
            {
                pos=min(n-i,m-j);
                for(ii=i;ii<n;ii++)
                {
                    for(jj=j;jj<m;jj++)
                    {
                        if(picture[ii][jj]=='W')
                        {
                            pos=min(pos,max(ii-i,jj-j));
                        }
                    }
                }
                for(ii=i;ii<pos+i;ii++)
                    for(jj=j;jj<pos+j;jj++)
                        num[ii][jj]=max(pos,num[ii][jj]);
            }
        }
    }
    int minn=max(n,m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(picture[i][j]=='B') minn=min(num[i][j],minn);
        }
    }
    return minn;
}

//<%:start-tests%>
double test0() {
	string t0[] = {"BBBB",
 "BBBB",
 "BBBB",
 "BBBB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Painting * obj = new Painting();
	clock_t start = clock();
	int my_answer = obj->largestBrush(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
	string t0[] = {"BBBB",
 "BWWB",
 "BWWB",
 "BBBB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Painting * obj = new Painting();
	clock_t start = clock();
	int my_answer = obj->largestBrush(p0);
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
	string t0[] = {"WBBBBB",
 "BBBBBB",
 "BBBBBB",
 "BBBBBB"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Painting * obj = new Painting();
	clock_t start = clock();
	int my_answer = obj->largestBrush(p0);
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
double test3() {
	string t0[] = {"BBBB",
 "BBBB",
 "WBBB",
 "BBBB",
 "BBBB",
 "BBBB"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Painting * obj = new Painting();
	clock_t start = clock();
	int my_answer = obj->largestBrush(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	string t0[] = {"WBBBBBWWWWWWWWW",
 "WBBBBBBWWWWWWWW",
 "WBBBBBBBBBBBWWW",
 "WBBBBBBBBBBBWWW",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBBBBBBBB",
 "BBBBBBBBWWBBBBB",
 "BBBBBBBBWBBBBBB",
 "WBBBBBBBWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBBWWBBBBBW",
 "BBBBBBWWWBBBBBW",
 "BBBBBWWWWWWWWWW",
 "BBBBBWWWWWWWWWW"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Painting * obj = new Painting();
	clock_t start = clock();
	int my_answer = obj->largestBrush(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
