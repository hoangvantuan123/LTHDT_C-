
#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("dsten.txt");
    ofstream fout("dsten-sapxep.txt");
    int n,i;
    string x;
    vector <string> a;
    fin>>n;
    for (int i = 0; i < n; i++) {
        fin >> x;
        a.push_back(x);
    }
    while (a.size() > 0) {
        int m = 0;
        for (int i = 1; i < a.size(); i++) {
            if (a[i].length() < a[m].length()
            || (a[i].length() == a[m].length() && a[i] < a[m]))
                m = i;
        }
        cout << a[m] << endl;
        fout << a[m] << endl;
        a.erase(a.begin() + m);
    }
    return 0;
}
