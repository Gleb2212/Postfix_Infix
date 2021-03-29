#include "math.trans/math_trans.h"

int main() {
    while (1) {
        char *s = getStr();
        transformation(&s);
        printf("%s\n", s);
        free(s);
        printf("Do you want to continue?\n0 - no\t1 - yes\n----->");
        if (!getInt()) {
            break;
        }
    }

    return 0;
}
