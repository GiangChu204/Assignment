#include <stdio.h>
#include "stats.h"  // File header từ Assignment 1 của bạn

/* Dữ liệu mẫu để test (giống Assignment 1) */
unsigned char test_array[40] = { 34, 201, 190, 154, 8, 194, 2, 6, 114, 88,
                                 45, 76, 123, 87, 25, 23, 200, 122, 150, 90,
                                 92, 87, 177, 244, 201, 6, 12, 60, 8, 2,
                                 5, 67, 7, 87, 250, 230, 99, 3, 100, 90};
int main() {
    // 1. Tính toán các giá trị trước
    unsigned char min = find_minimum(test_array, 40);
    unsigned char max = find_maximum(test_array, 40);
    unsigned char mean = find_mean(test_array, 40);
    unsigned char median = find_median(test_array, 40);

    // 2. Truyền 4 kết quả vào hàm print_statistics theo đúng khai báo trong stats.h
    print_statistics(min, max, mean, median);

    return 0;
}
