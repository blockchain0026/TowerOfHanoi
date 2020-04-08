// 河內塔範例.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"
#include <string>
#include <iostream>
using namespace std;
#define MAX 5
#define MAX_ITEM 1000


typedef struct STACK
{
	int num[MAX_ITEM];
	int top = -1;
}stack;

int push(stack *S, int n)
{
	if (S->top == (MAX_ITEM - 1))
		return false;
	S->top = S->top +1;
	S->num[S->top] = n;

		
	return true;
}

int pop(stack *S, int *n)
{
	if (S->top == -1)
		return false;
	*n = S->num[S->top];
	S->num[S->top] = -1;
	(S->top)--;
	return true;
}

int PrintHanoi(stack *A, stack *B, stack *C,int N)
{
	for (int i = N - 1; i >= 0;i--)
	{
		if ((A->num[i] < 0) & (B->num[i] < 0) &(C->num[i] < 0))
			cout <<" "<< "-" << " " << "-" << " " << "-" << endl;
		else if ((A->num[i] < 0) & (B->num[i] < 0))
			cout << " " << "-" << " " << "-" << " " << C->num[i] << endl;
		else if ((A->num[i] < 0) & (C->num[i] < 0))
			cout << " " << "-" << " " << B->num[i] << " " << "-" << endl;
		else if ((B->num[i] < 0) & (C->num[i] < 0))
			cout << " " << A->num[i] << " " << "-" << " " << "-" << endl;
		else if (A->num[i] < 0)
			cout << " " << "-" << " " << B->num[i] << " " << C->num[i] << endl;
		else if (B->num[i] < 0)
			cout << " " << A->num[i] << " " << "-" << " " << C->num[i] << endl;
		else if (C->num[i] < 0)
			cout << " " << A->num[i] << " " << B->num[i] << " " << "-" << endl;
		else
			cout << " " << A->num[i] << " " << B->num[i] << " " << C->num[i] << endl;
	}
	return true;
}

typedef struct COUNT
{
	int cou=0;
}Count;

void hanoi(stack *A,stack *B,stack *C,int n,int N, string from, string by, string to,Count *Cou)
{
	int *Rnum=new int;
	*Rnum = 1;
	if (n > 0)
	{
		hanoi(A,B,C,n - 1,N, from, to, by,Cou);
		cout <<endl << "Move no. " << n << " disk from " << from << " to " << to <<endl;
		Cou->cou++;
		if (to == "A")
		{
			if (from == "B")
			{
				pop(B, Rnum);
				push(A, *Rnum);
				PrintHanoi(A, B, C, N);
			}
			else if (from == "C")
			{
				pop(C, Rnum);
				push(A, *Rnum);
				PrintHanoi(A, B, C, N);
			}
		}
		if (to == "B")
		{
			if (from == "A")
			{
				pop(A, Rnum);
				push(B, *Rnum);
				PrintHanoi(A, B, C, N);
			}
			else if (from == "C")
			{
				pop(C, Rnum);
				push(B, *Rnum);
				PrintHanoi(A, B, C, N);
			}
		}
		if (to == "C")
		{
			if (from == "A")
			{
				pop(A, Rnum);
				push(C, *Rnum);
				PrintHanoi(A, B, C,N);
			}
			else if (from == "B")
			{
				pop(B, Rnum);
				push(C, *Rnum);
				PrintHanoi(A, B, C, N);
			}
		}

		hanoi(A,B,C,n - 1,N, by, from, to,Cou);
		
	}
}

int main()
{
	cout << "【tower of hanoi】"<<endl ;

	while (true)
	{
		cout <<endl<< "------------------------------------------";
		//cout << endl << "Please enter the number of plates :";
		cout << endl << "請輸入盤子總數：";
		int n;
		cin >> n;

		string a = "A", b = "B", c = "C";

		stack *A = new stack;
		stack *B = new stack;
		stack *C = new stack;
		Count *D = new Count;
		for (int i = 0;i < n;i++)
			push(A,n - i);
		for (int i = n - 1;i >= 0;i--)
		    cout << " " << A->num[i] << " " << "-" << " " << "-" << endl;
		cout << endl;
		system("pause");
		cout << endl << endl;
		hanoi(A,B,C,n,n, a, b, c,D);

		
		//cout <<endl << endl << endl << "Moved " << D->cou << " times in total." << endl <<endl;
		//cout << "translated by 科丞." ;
		cout << endl << endl << endl << "總共移動了 " << D->cou << " 次盤子" << endl;
		cout << "------------------------------------------"<<endl<<endl ;
	}
    return 0;
}

