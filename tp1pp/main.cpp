#include <iostream>

using namespace std;

int &valAt(int *tab, int i) {
	return (tab[i]);
}

void printTab(int *tab, int MAX) {
    // int tab_len = sizeof(tab)/sizeof(tab[0]);

	for (size_t i = 0; i < MAX; ++i) {
		cout << valAt(tab, i) << endl;
	}
}

void init_tab(int *tab, int MAX) {
	for (size_t i = 0; i < MAX; i++) {
		valAt(tab, i) = i;
	}
}

int main() {
	const size_t MAX = 20;

	int tab[MAX];

	init_tab(tab, MAX);
	printTab(tab, MAX);

	return (0);
}