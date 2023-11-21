#include <iostream>
#include <unordered_map>
#include <cstring>

#define N 202

using namespace std;

static char s[3]; // Increase the size to accommodate '\0'
static int parentArray[N];
static int rankArray[N];

int disjointSetCount;

void MakeSet(int n) {
    for (int i = 0; i < n; ++i) {
        parentArray[i] = i;
        rankArray[i] = 0;
    }

    disjointSetCount = n;
}

int FindSet(int x) {
    if (x != parentArray[x])
        parentArray[x] = FindSet(parentArray[x]);
    return parentArray[x];
}

bool SameSet(int x, int y) {
    return FindSet(x) == FindSet(y);
}

void Link(int x, int y) {
    if (!SameSet(x, y)) {
        if (rankArray[x] > rankArray[y])
            parentArray[y] = x;
        else {
            parentArray[x] = y;
            if (rankArray[x] == rankArray[y])
                rankArray[y] = rankArray[y] + 1;
        }
        --disjointSetCount;
    }
}

void Union(int x, int y) {
    Link(FindSet(x), FindSet(y));
}

int main() {
    int n;
    scanf("%d\n\n", &n);

    bool blank = false;

    while (n--) {
        char c;
        cin >> c;
        cin.ignore();

        MakeSet(c - 'A' + 1);

while (true) {
    cin.getline(s, 3);
    if (strlen(s) == 0)
        break;
    Union(s[0] - 'A', s[1] - 'A');
}


        if ( )
            cout << endl;

        blank = true;
        cout << disjointSetCount << endl;
    }

    return 0;
}
