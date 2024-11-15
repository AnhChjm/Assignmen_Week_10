#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Go {
    char loai[30];
    int kichThuoc;
    int tuoi;
    struct Go* next;
} Go;

typedef struct KhoGo {
    char loai[30];
    Go* top;
} KhoGo;

Go* taoGo(const char* loai, int kichThuoc, int tuoi) {
    Go* goMoi = (Go*)malloc(sizeof(Go));
    if (!goMoi) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    strcpy(goMoi->loai, loai);
    goMoi->kichThuoc = kichThuoc;
    goMoi->tuoi = tuoi;
    goMoi->next = NULL;
    return goMoi;
}

KhoGo* taoKhoGo(const char* loai) {
    KhoGo* khoGo = (KhoGo*)malloc(sizeof(KhoGo));
    if (!khoGo) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    strcpy(khoGo->loai, loai);
    khoGo->top = NULL;
    return khoGo;
}

void themGo(KhoGo* khoGo, int kichThuoc, int tuoi) {
    Go* goMoi = taoGo(khoGo->loai, kichThuoc, tuoi);
    goMoi->next = khoGo->top;
    khoGo->top = goMoi;
    printf("Da them go: Loai=%s, Kich thuoc=%d, Tuoi=%d\n", goMoi->loai, goMoi->kichThuoc, goMoi->tuoi);
}

Go* layGo(KhoGo* khoGo) {
    if (!khoGo->top) {
        printf("Kho go rong!\n");
        return NULL;
    }
    Go* goLayRa = khoGo->top;
    khoGo->top = khoGo->top->next;
    return goLayRa;
}

int demTuoi(KhoGo* khoGo, int tuoi) {
    int dem = 0;
    Go* hienTai = khoGo->top;
    while (hienTai) {
        if (hienTai->tuoi == tuoi) {
            dem++;
        }
        hienTai = hienTai->next;
    }
    return dem;
}

void hienThiKhoGo(KhoGo* khoGo) {
    if (!khoGo->top) {
        printf("Kho go loai %s hien tai rong.\n", khoGo->loai);
        return;
    }
    printf("Danh sach go trong kho (%s):\n", khoGo->loai);
    Go* hienTai = khoGo->top;
    while (hienTai) {
        printf("  Loai: %s, Kich thuoc: %d, Tuoi: %d\n", hienTai->loai, hienTai->kichThuoc, hienTai->tuoi);
        hienTai = hienTai->next;
    }
    printf("\n");
}

int main() {
    KhoGo* goKeo = taoKhoGo("Go Keo");
    KhoGo* goNghien = taoKhoGo("Go Nghien");
    KhoGo* goLim = taoKhoGo("Go Lim");

    themGo(goKeo, 4, 12);
    themGo(goKeo, 6, 20);
    themGo(goKeo, 3, 15);
    themGo(goNghien, 5, 10);
    themGo(goNghien, 2, 25);
    themGo(goLim, 7, 30);
    themGo(goLim, 5, 12);

    hienThiKhoGo(goKeo);
    hienThiKhoGo(goNghien);
    hienThiKhoGo(goLim);

    printf("So luong go co tuoi 12 trong Go Keo: %d\n", demTuoi(goKeo, 12));
    printf("So luong go co tuoi 25 trong Go Nghien: %d\n", demTuoi(goNghien, 25));

    Go* goLayRa = layGo(goKeo);
    if (goLayRa) {
        printf("Go da lay ra: Loai=%s, Kich thuoc=%d, Tuoi=%d\n", goLayRa->loai, goLayRa->kichThuoc, goLayRa->tuoi);
        free(goLayRa);
    }

    hienThiKhoGo(goKeo);
    hienThiKhoGo(goNghien);
    hienThiKhoGo(goLim);

    free(goKeo);
    free(goNghien);
    free(goLim);

    return 0;
}
