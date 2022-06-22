#include <iostream>

int main() {
    int* temp = new int(10);

    int* a = temp;
    delete temp;

    a = new int(6);

    return 0;
}
