﻿#include <iostream>
#include <iomanip>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
double X[100], Y[100], dY[100], DY[100], d2Y[100], D2Y[100], pog1[100], pog2[100], h, I;
int i, a, b, k, r, v, m;
double f(double x)
{
	double t;
	t = sqrt(x) - pow(cos(x), 2);
	return(t);
}
double Gauss2(double A, double B, double M)
{
	double h, x12, x1, x2, s = 0, integral;
	int i;
	h = (B - A) / M;
	x12 = A + h / 2;
	x1 = x12 - (h / 2) * 0.5773502692;
	x2 = x12 + (h / 2) * 0.5773502692;
	for (i = 1; i <= m; i++)
	{
		s += f(x1) + f(x2);
		x12 = x12 + h;
		x1 = x12 - (h / 2) * 0.5773502692;
		x2 = x12 + (h / 2) * 0.5773502692;
	}
	integral = (h / 2) * s;
	return (integral);
}
void main(void)
{
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "Vibirete shag:\n" << "1 h=0.2\n" << "2 h=0.1\n" << "3 h=0.05\n";
	cin >> r;
	switch (r)
	{
	case 1:
		h = 0.2;
		break;
	case 2:
		h = 0.1;
		break;
	case 3:
		h = 0.05;
		break;
	default:
		cout << "Vibrano ne dopustimoe zna4enie";
	}
	cout << "Viberete m:\n1 m=10\n2 m=20\n3 m=40\n";
	cin >> v;
	switch (v)
	{
	case 1:
		m = 10;
		break;
	case 2:
		m = 20;
		break;
	case 3:
		m = 40;
		break;
	default:
		cout << "Vibrano ne dopustimoe zna4enie";
	}
	k = (b - a) / h;
	for (i = 1; i <= k + 1; i++)
	{
		X[i] = a + (i - 1) * h;
		Y[i] = f(X[i]);
	}
	
	dY[1] = -(3 * Y[1] - 4 * Y[2] + Y[3]) / (2 * h);
	dY[k + 1] = (Y[k - 1] - 4 * Y[k] + 3 * Y[k + 1]) / (2 * h);
	for (i = 2; i <= k; i++) dY[i] = (Y[i + 1] - Y[i - 1]) / (2 * h);
	for (i = 1; i <= k + 1; i++) DY[i] = 2 * X[i] - 5 * sin(X[i]);
	
	for (i = 1; i <= k + 1; i++) D2Y[i] = 2 - 5 * cos(X[i]);
	for (i = 2; i <= k; i++) d2Y[i] = (Y[i - 1] - 2 * Y[i] + Y[i + 1]) / (h * h);
	for (i = 1; i <= k + 1; i++)
	{
		pog1[i] = fabs(fabs(dY[i]) - fabs(DY[i]));
		pog2[i] = fabs(fabs(d2Y[i]) - fabs(D2Y[i]));
	}
	printf("X\tY\tdY\tDY\tpogr\td2Y\tD2Y\tpogr\n");
	for (i = 1; i <= k + 1; i++) printf("%2.1f\t%4.3f\t%4.3f\t%4.3f\t%5.4f\t%4.3f\t%4.3f\t%5.4f\n", X[i], Y[i], dY[i], DY[i], pog1[i], d2Y[i], D2Y[i], pog2[i]);
	I = Gauss2(a, b, m);
	cout << endl << "Integral=" << I << endl;
}
