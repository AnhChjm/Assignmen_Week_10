#include <iostream>
#include <string>
#include <stack>

class Go {
public:
    std::string loai_go;
    int chieu_dai;

    Go(std::string loai, int dai) : loai_go(loai), chieu_dai(dai) {}
};

int dem_loai_go(std::stack<Go> ds_go, const std::string &loai) {
    int dem = 0;
    while (!ds_go.empty()) {
        Go go = ds_go.top();
        ds_go.pop();
        if (go.loai_go == loai) {
            dem++;
        }
    }
    return dem;
}

void nhap_danh_sach_go(std::stack<Go> &ds_go, int kich_thuoc) {
    for (int i = 0; i < kich_thuoc; i++) {
        std::string loai;
        int chieu_dai;

        std::cout << "Nhap loai go thu " << i + 1 << ": ";
        std::cin.ignore();
        std::getline(std::cin, loai);
        std::cout << "Nhap chieu dai go thu " << i + 1 << ": ";
        std::cin >> chieu_dai;

        ds_go.push(Go(loai, chieu_dai));
    }
}

int main() {
    std::stack<Go> ds_go;
    int kich_thuoc;

    std::cout << "Nhap so luong go: ";
    std::cin >> kich_thuoc;

    nhap_danh_sach_go(ds_go, kich_thuoc);

    std::cout << "Danh sach go: " << std::endl;
    std::stack<Go> temp_stack = ds_go;
    while (!temp_stack.empty()) {
        Go go = temp_stack.top();
        temp_stack.pop();
        std::cout << "Loai go: " << go.loai_go << ", Chieu dai: " << go.chieu_dai << std::endl;
    }

    std::string loai_dem = "Cam xe";
    int so_luong = dem_loai_go(ds_go, loai_dem);
    std::cout << "So luong thanh phan cung loai go \"" << loai_dem << "\": " << so_luong << std::endl;

    return 0;
}
