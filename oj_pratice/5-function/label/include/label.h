#ifndef LABEL_H
#define LABEL_H

#include "const.h"

/** 标签的最大长度。 
 *
 * 标签的存储约定：标签使用一维字符数组存储，
 * 第二个字符是 '\0' 表明这个标签只有 1 个字符。
 *
 * {'a', '\0'}  ->  标签是 a
 * {'a', 's'}   ->  标签是 as
 */
#define LABEL_LEN 2

/** 标签个数的上限。 */
#define MAX_LABELS (MAX_A * MAX_A)

int compute_labels(const char* alphabet, int count, char labels[][LABEL_LEN]);

void print_label(const char label[LABEL_LEN]);

#endif
