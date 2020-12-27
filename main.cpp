#include <bits/stdc++.h>

using namespace std;

void print_towers(int towers[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << towers[i] << " ";
    }
}

int next_step(int current, const int towers[], int size) {
    int next = towers[current + 1] + (current + 1);

    for (int i = current + 2; i < size; ++i) {
        if (towers[i] == 0) {
            continue;
        } else {
            if ((towers[i] + i) > next) {
                next = towers[i] + i;
            }
        }
    }

    return next;
}

bool is_hoppable(const int towers[], int size) {
    int current = 1;

    while (true) {
        if (current >= size) {
            return true;
        }

        if (towers[current] == 0) {
            return false;
        }

        current = next_step(current, towers, size);
    }
}

int main() {
//    int towers[] = {4, 2, 0, 0, 2, 0};
    int towers[] = {1, 3, 5, 3, 1, 0};

    int size = sizeof(towers) / sizeof(towers[0]);

    cout << "Given Towers array: ";
    print_towers(towers, size);

    if (is_hoppable(towers, size)) {
        cout << "\nHoppable";
    } else {
        cout << "\nNot hoppable";
    }

    return 0;
}
