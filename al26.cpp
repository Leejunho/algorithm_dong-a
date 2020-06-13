#include <stdio.h>
#include<iostream>
#include<fstream>
#include <cstdio>
#include <climits>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
struct blocks {
	int x, y, p, q;
	blocks() {}
	blocks(int x, int y, int p, int q) :
		x(x), y(y), p(p), q(q) {}
};

bool cmpX(const blocks& e1, const blocks& e2) {
	if (e1.x != e2.x) return e1.x<e2.x;
	return e1.y<e2.y;
}

bool cmpY(const blocks& e1, const blocks& e2) {
	if (e1.y != e2.y) return e1.y<e2.y;
	return e1.x<e2.x;
}


int main() {
	ifstream fin;
	ofstream fout;

	fin.open("block.inp");
	fout.open("block.out");

	int T;//test case
	int i, j,te;
	fin >> T;
	for (te = 0; te < T; te++) {
		fin >> N;
		vector<blocks> v;
		for (j = 0; j < N; j++) {
			blocks t;
			fin >> t.x >> t.y >> t.p >> t.q;
			v.push_back(t);
		}
		int i, j;
		int finish = 1;
		blocks check(INT_MAX, INT_MAX, INT_MIN, INT_MIN);
		while (finish) {
			finish = false;
			sort(v.begin(), v.end(), cmpY);
			for (int i = 0; i < N; i++) {
				if (!v[i].y) continue;
				int now = 0;
				for (int j = i - 1; j >= 0; j--)
					if (((v[j].x >= v[i].x && v[j].x < v[i].p) || (v[j].p > v[i].x && v[j].p <= v[i].p)) || (v[j].x <= v[i].x && v[j].p >= v[i].p)) {
						now = max(now, v[j].q);
						if (v[i].y == v[j].q) break;
					}
				if (v[i].y == now) continue;
				int diff = v[i].q - v[i].y;
				v[i].y = now;
				v[i].q = now + diff;
				
				finish = 1;
			}
			sort(v.begin(), v.end(), cmpX);
			for (int i = 0; i < N; i++) {
				if (!v[i].x) continue;
				int now = 0;
				for (int j = i - 1; j >= 0; j--)
					if (((v[j].y >= v[i].y && v[j].y < v[i].q) || (v[j].q > v[i].y && v[j].q <= v[i].q)) || (v[j].y <= v[i].y && v[j].q >= v[i].q)) {
						now = max(now, v[j].p);
						if (v[i].x == v[j].p) break;
					};
				if (v[i].x == now) continue;
				int diff = v[i].p - v[i].x;
				v[i].x = now;
				v[i].p = now + diff;
				
				finish = 1;
			}
		}
		for (int i = 0; i < N; i++) {
			check.q = max(check.q, v[i].q);
			check.p = max(check.p, v[i].p);
			check.x = min(check.x, v[i].x);
			check.y = min(check.y, v[i].y);
		}
		fout << check.p - check.x << " " << check.q - check.y << endl;
		
	}

	return 0;
}
