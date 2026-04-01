#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief In các thống kê của mảng bao gồm: minimum, maximum, mean, và median.
 */
void print_statistics(unsigned char min, unsigned char max, unsigned char mean, unsigned char median);

/**
 * @brief In mảng ra màn hình.
 */
void print_array(unsigned char *array, unsigned int length);

/**
 * @brief Tìm giá trị trung vị (median) của mảng.
 */
unsigned char find_median(unsigned char *array, unsigned int length);

/**
 * @brief Tìm giá trị trung bình (mean) của mảng.
 */
unsigned char find_mean(unsigned char *array, unsigned int length);

/**
 * @brief Tìm giá trị lớn nhất (maximum) của mảng.
 */
unsigned char find_maximum(unsigned char *array, unsigned int length);

/**
 * @brief Tìm giá trị nhỏ nhất (minimum) của mảng.
 */
unsigned char find_minimum(unsigned char *array, unsigned int length);

/**
 * @brief Sắp xếp mảng từ lớn đến nhỏ.
 */
void sort_array(unsigned char *array, unsigned int length);

#endif /* __STATS_H__ */
