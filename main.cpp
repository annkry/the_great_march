#include <iostream>
#include <vector>
#include <map>
using namespace std;
vector<pair<int, int>> inc2[500000];
pair<int, int> queue[500002];
map<pair<int, int>, pair<int, int>> my_map;
map<pair<int, int>, pair<int, int>> deg;
int n;
int m;
int t;
int idd;
int ik;
int ik2;

int main() {
	int a1;
	int b1;
	int a2;
	int b2;
	if (scanf("%d %d %d", &m, &n, &t) == 0) {
		printf("Error");
	}
	idd = 0;
	for (int i = 0; i < t; i++) {
		if (scanf("%d %d %d %d", &a1, &b1, &a2, &b2) == 0) {
			printf("Error");
		}
		if (my_map.find(make_pair(a2, b2)) == my_map.end()) {
			inc2[idd].push_back(make_pair(a2, b2));
			inc2[idd].push_back(make_pair(a1, b1));
			my_map.insert(make_pair(make_pair(a2, b2), make_pair(idd, 0)));
			idd = idd + 1;
		}
		else {
			inc2[my_map[make_pair(a2, b2)].first].push_back(make_pair(a1, b1));
		}
		deg[make_pair(a2, b2)].first++;
	}
	ik = 0;
	ik2 = 0;
	pair<int, int> v;
	v = make_pair(m, n);
	int i = 0;
	queue[0] = v;
	if (deg[make_pair(m, n)].first > 0) {
		while (ik != ik2 + 1) {
			v = queue[ik];
			i = 1;
			if (v != make_pair(0, 0)) {
				if (deg[v].first != 0) {
					while (i < ((int)size(inc2[my_map[v].first]))) {
						if (deg[inc2[my_map[v].first][i]].second == 0) {
							ik2++;
							queue[ik2] = inc2[my_map[v].first][i];
						}
						
							deg[inc2[my_map[v].first][i]].second++;
						
						i++;
					}
				}
			}
			ik++;
		}
	}
	v = make_pair(m, n);
	my_map[v].second = 1;
	i = 0;
	ik = 0;
	ik2 = 0;
	queue[0] = v;
	if (deg[make_pair(m, n)].first > 0) {
		while (ik != ik2 + 1) {
			v = queue[ik];
			if (v != make_pair(0, 0)) {
				i = 1;
				if (deg[v].first != 0) {
					while (i < ((int)size(inc2[my_map[v].first]))) {
						deg[inc2[my_map[v].first][i]].second--;
						if (deg[inc2[my_map[v].first][i]].second == 0) {
							ik2++;
							queue[ik2] = inc2[my_map[v].first][i];
						}
						deg[v].first--;
						if (my_map[inc2[my_map[v].first][i]].second == 0) {
							my_map[inc2[my_map[v].first][i]].second = my_map[v].second % 999979;
						}
						else {
							my_map[inc2[my_map[v].first][i]].second += my_map[v].second % 999979;
						}
						i++;
					}
				}
			}
			ik++;
		}
		my_map[make_pair(0, 0)].second = my_map[make_pair(0, 0)].second % 999979;
		printf("%d", my_map[make_pair(0, 0)].second);
	}
	else {
		printf("0");
	}
	return 0;
}