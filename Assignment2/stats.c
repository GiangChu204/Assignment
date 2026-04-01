#include <stdio.h>
#include "stats.h"


void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median) {
    printf("\nThe minimum is: %d\n", min);
    printf("The maximum is: %d\n", max);
    printf("The mean is: %d\n", mean);
    printf("The median is: %d\n", median);
}

void print_array(unsigned char *array, unsigned int length) {
    for (int i = 0; i < length; i++) {
        printf("%-6d", array[i]);
        if ((i + 1) % 8 == 0) printf("\n"); // In 8 số trên một dòng như hình
    }
}

unsigned char find_median(unsigned char *array, unsigned int length) {
    // Lưu ý: Mảng đã được sắp xếp trước khi gọi hàm này
    if (length % 2 == 0) {
        return (array[length/2] + array[length/2 - 1]) / 2;
    } else {
        return array[length/2];
    }
}

unsigned char find_mean(unsigned char *array, unsigned int length) {
    unsigned int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += array[i];
    }
    return (unsigned char)(sum / length); // Tự động làm tròn xuống (integer division)
}

unsigned char find_maximum(unsigned char *array, unsigned int length) {
    unsigned char max = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] > max) max = array[i];
    }
    return max;
}

unsigned char find_minimum(unsigned char *array, unsigned int length) {
    unsigned char min = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < min) min = array[i];
    }
    return min;
}

void sort_array(unsigned char *array, unsigned int length) {
    unsigned char temp;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (array[i] < array[j]) { // Sắp xếp giảm dần (Large to Small)
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
