#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct lưu thông tin sinh viên
typedef struct {
    char fn[50];   // firstname (tên)
    char ln[50];   // lastname (họ)
    int age;       // tuổi
} SV;

// hàm so sánh theo tên (dùng cho qsort)
int cmpFN(const void *a, const void *b) {
    // ép kiểu void* về SV*
    SV *s1 = (SV*)a;
    SV *s2 = (SV*)b;

    // so sánh chuỗi tên
    return strcmp(s1->fn, s2->fn);
}

// hàm so sánh theo họ
int cmpLN(const void *a, const void *b) {
    SV *s1 = (SV*)a;
    SV *s2 = (SV*)b;

    // so sánh chuỗi họ
    return strcmp(s1->ln, s2->ln);
}

// hàm xử lý: in nếu tuổi > 20
void isolder(SV s) {
    if (s.age > 20)                    // kiểm tra điều kiện
        printf("%s %s %d\n", s.fn, s.ln, s.age); // in ra
}

// hàm apply: áp dụng 1 hàm cho từng phần tử
void apply(SV a[], int n, void (*f)(SV)) {
    for (int i = 0; i < n; i++)   // duyệt mảng
        f(a[i]);                  // gọi hàm f cho từng phần tử
}

int main() {
    // khởi tạo mảng dữ liệu
    SV a[] = {
        {"An","Nguyen",19},
        {"Binh","Tran",22},
        {"Cuong","Le",25},
        {"Dung","Pham",18}
    };

    int n = sizeof(a)/sizeof(a[0]); // tính số phần tử

    // sắp xếp theo tên
    qsort(a, n, sizeof(SV), cmpFN);

    // sắp xếp theo họ (ghi đè kết quả trước)
    qsort(a, n, sizeof(SV), cmpLN);

    // áp dụng hàm isolder cho từng phần tử
    apply(a, n, isolder);

    return 0;
}
