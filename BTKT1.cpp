#include <stdio.h>
#include <string.h>
#include <ctype.h>

void chuan_hoa(char *ho_ten) {
    int j = 0, start = 1;
    for (int i = 0; ho_ten[i]; i++) {
        if (ho_ten[i] != ' ' || (j > 0 && ho_ten[j - 1] != ' '))
            ho_ten[j++] = start ? toupper(ho_ten[i]) : tolower(ho_ten[i]);
        start = (ho_ten[i] == ' ');
    }
    if (j > 0 && ho_ten[j - 1] == ' ') j--;
    ho_ten[j] = '\0';
}

int main() {
    int t;
    printf("So lan test: ");
    scanf("%d", &t);
    getchar();

    for (int i = 0; i < t; ++i) {
        printf("Nhap xau ho ten: ");
        char ho_ten[81];
        fgets(ho_ten, sizeof(ho_ten), stdin);
        size_t len = strlen(ho_ten);
        if (len > 0 && ho_ten[len - 1] == '\n') ho_ten[len - 1] = '\0';
        chuan_hoa(ho_ten);
        printf("Xau chuan hoa: %s\n", ho_ten);
    }

    return 0;
}
