#include <stdio.h>

typedef struct {
    char languages[3][20];
    char discord[30];
} user;

void main() {
    user WOLF = {
        {"ESP", "ENG", "PTR"},
        "a"
    };
}
