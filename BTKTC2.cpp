#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    int ma;
    char ten[101];
    char ngay_sinh[11];
    float diem[3];
    float tong_diem;
} ThiSinh;

void nhap_thi_sinh(ThiSinh *ts, int ma) {
    ts->ma = ma;
    printf("Nhap ten thi sinh: ");
    fgets(ts->ten, sizeof(ts->ten), stdin);
    ts->ten[strcspn(ts->ten, "\n")] = '\0';

    printf("Nhap ngay thang nam sinh : ");
    fgets(ts->ngay_sinh, sizeof(ts->ngay_sinh), stdin);
    ts->ngay_sinh[strcspn(ts->ngay_sinh, "\n")] = '\0';

    printf("Nhap diem mon 1: ");
    scanf("%f", &ts->diem[0]);
    printf("Nhap diem mon 2: ");
    scanf("%f", &ts->diem[1]);
    printf("Nhap diem mon 3: ");
    scanf("%f", &ts->diem[2]);
    ts->tong_diem = ts->diem[0] + ts->diem[1] + ts->diem[2];
    getchar(); 
}

ThiSinh* tim_thu_khoa(ThiSinh ds[], int n, int *so_thu_khoa) {
    float diem_cao_nhat = 0;
    *so_thu_khoa = 0;
    
    // Tim diem cao nhat
    for (int i = 0; i < n; i++) {
        if (ds[i].tong_diem > diem_cao_nhat) {
            diem_cao_nhat = ds[i].tong_diem;
        }
    }

    static ThiSinh thu_khoa[MAX];
    for (int i = 0; i < n; i++) {
        if (ds[i].tong_diem == diem_cao_nhat) {
            thu_khoa[*so_thu_khoa] = ds[i];
            (*so_thu_khoa)++;
        }
    }

    return thu_khoa;
}

int main() {
    int n;
    ThiSinh ds[MAX];

    printf("Nhap so thi sinh: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        nhap_thi_sinh(&ds[i], i + 1);
    }

    int so_thu_khoa = 0;
    ThiSinh* ds_thu_khoa = tim_thu_khoa(ds, n, &so_thu_khoa);

    printf("Thu khoa:\n");
    for (int i = 0; i < so_thu_khoa; i++) {
        printf("%d %s %s %.1f\n", ds_thu_khoa[i].ma, ds_thu_khoa[i].ten, ds_thu_khoa[i].ngay_sinh, ds_thu_khoa[i].tong_diem);
    }

    return 0;
}

