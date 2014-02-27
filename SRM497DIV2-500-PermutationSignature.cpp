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

class PermutationSignature {
public:
	vector <int> reconstruct(string);
};

vector <int> PermutationSignature::reconstruct(string signature)
{
	int n=signature.size();
	vector <int> ans(n+1,0);
	signature[n]='I';
	int i,j,k,temp=2,tt;
	for(i=0;i<n;i++)
    {
        tt=0;
        if(signature[i]=='I')
        {
            tt=1;
            ans[i]=1;
            temp=2;
            for(j=i-1;j>=0;j--) ans[j]=temp++;
            break;
        }
    }
    if(tt==0)
    {
        ans[n]=1;
        int t=2;
        for(j=n-1;j>=0;j--) ans[j]=t++;
    }
    else
    {
        for(j=i+1;j<=n;j++)
        {
            if(signature[j-1]=='D') ans[j]=ans[j-1]-1;
            else if(signature[j-1]=='I')
            {
                int num=0;
                if(signature[j]=='I') ans[j]=*max_element(ans.begin(),ans.end())+1;
                else
                {
                    for(k=j+1;k<=n;k++)
                    {
                        if(signature[k]=='I') break;
                    }
                    if(j+1==k) ans[j]=*max_element(ans.begin(),ans.end())+2;
                    else
                    {
                        ans[k]=*max_element(ans.begin(),ans.end())+1;
                        int a=ans[k];
                        for(int kk=k-1;kk>=j;kk--) ans[kk]=++a;
                    }
                }
            }
        }
    }
    return ans;
}

//<%:testing-code%>
//<%:start-tests%>
double test0() {
	string p0 = "DIDIIIDIDIDIDIDIDIIDIDIDIDIDDDDD";
	PermutationSignature * obj = new PermutationSignature();
	clock_t start = clock();
	vector <int> my_answer = obj->reconstruct(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {2, 1, 4, 3, 5, 6, 8, 7, 10, 9, 12, 11, 14, 13, 16, 15, 18, 17, 19, 21, 20, 23, 22, 25, 24, 27, 26, 33, 32, 31, 30, 29, 28 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string p0 = "DI";
	PermutationSignature * obj = new PermutationSignature();
	clock_t start = clock();
	vector <int> my_answer = obj->reconstruct(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {2, 1, 3 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string p0 = "IIIID";
	PermutationSignature * obj = new PermutationSignature();
	clock_t start = clock();
	vector <int> my_answer = obj->reconstruct(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {1, 2, 3, 4, 6, 5 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string p0 = "DIIDID";
	PermutationSignature * obj = new PermutationSignature();
	clock_t start = clock();
	vector <int> my_answer = obj->reconstruct(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {2, 1, 3, 5, 4, 7, 6 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
