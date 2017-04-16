#include <bits/stdc++.h>
using namespace std;

struct Coordinate
{
	int x, y;
};

Coordinate p0;

Coordinate nextToTop(stack<Coordinate> &S)
{
	Coordinate p = S.top();
	S.pop();
	Coordinate res = S.top();
	S.push(p);
	return res;
}

int swap(Coordinate &p1, Coordinate &p2)
{
	Coordinate temp = p1;
	p1 = p2;
	p2 = temp;
}

int Distance(Coordinate p1, Coordinate p2)
{
	return (p1.x - p2.x)*(p1.x - p2.x) +
		(p1.y - p2.y)*(p1.y - p2.y);
}


int dir(Coordinate p, Coordinate q, Coordinate r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0; // colinear
	return (val > 0)? 1: 2; // clock or counterclock wise
}

//used to sort
int Comparison(const void *vp1, const void *vp2)
{
Coordinate *p1 = (Coordinate *)vp1;
Coordinate *p2 = (Coordinate *)vp2;

int o = dir(p0, *p1, *p2);
if (o == 0)
	return (Distance(p0, *p2) >= Distance(p0, *p1))? -1 : 1;

return (o == 2)? -1: 1;
}

// Prints convex hull of a set of n Coordinates.
void convexHull(Coordinate Coordinates[], int n)
{

int ymin = Coordinates[0].y, min = 0;
for (int i = 1; i < n; i++)
{
	int y = Coordinates[i].y;


	if ((y < ymin) || (ymin == y &&
		Coordinates[i].x < Coordinates[min].x))
		ymin = Coordinates[i].y, min = i;
}


swap(Coordinates[0], Coordinates[min]);

//sorting using Comparison
p0 = Coordinates[0];
qsort(&Coordinates[1], n-1, sizeof(Coordinate), Comparison);


int m = 1; 
for (int i=1; i<n; i++)
{

	while (i < n-1 && dir(p0, Coordinates[i],Coordinates[i+1]) == 0)//check same angle
		i++;

	Coordinates[m] = Coordinates[i];
	m++; 
}


if (m < 3) return;


stack<Coordinate> S;
S.push(Coordinates[0]);
S.push(Coordinates[1]);
S.push(Coordinates[2]);


for (int i = 3; i < m; i++)
{
	
	while (dir(nextToTop(S), S.top(), Coordinates[i]) != 2)
		S.pop();
	S.push(Coordinates[i]);
}


while (!S.empty())
{
	Coordinate p = S.top();
	cout << "(" << p.x << ", " << p.y <<")" << endl;
	S.pop();
}
}

int main()
{
	Coordinate Coordinates[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
					{0, 0}, {1, 2}, {3, 1}, {3, 3}};
	int n = sizeof(Coordinates)/sizeof(Coordinates[0]);
	convexHull(Coordinates, n);
	return 0;
}
