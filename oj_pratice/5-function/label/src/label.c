#include "label.h"
#include<string.h>
#include<stdio.h>
/**
 * 为 count 个数字生成一张标签表。
 *
 * 规则如下：
 * 设要生成 m 个标签，字母表 alphabet 的长度为 A。
 * 1. 起初，alphabet 的每个字符都是一个可用的单字符标签，共 A 个。
 * 2. 若不够，就从字母表的最后一个字符开始，逐个把字符升级为双字符标
 *    签的前缀, 得到 A 个双标签。重复该步骤，直到标签数不少于 m 个。
 * 3. 最后一次升级可能会得到过量的标签数。对于最后一次被升级的标签，
 *    只保留字母表开头若干个作为其后缀，使得所有标签凑够 m 个。
 *
 * @param alphabet 字母表，1..52 个互不相同的大小写字母。
 * @param count    需要的标签数。
 * @param labels   输出用的二维字符数组。
 * @return 生成的标签个数。
 */
int compute_labels(const char* alphabet, int count, char labels[][LABEL_LEN]) {
    int len = strlen(alphabet);
    int cnt = 0;
    for(int i=0;i<len && cnt < count;i++){
        labels[i][0] = alphabet[i];
        labels[i][1] = '\0';
        cnt++;
    }
    int sta = len-1;
    int end = len;
    while(cnt < count){
        int addlen = len<(count-cnt+1)?len:(count-cnt+1);
        for(int i=end-1;i>sta;i--){
            labels[i+addlen-1][1] = labels[i][1];
            labels[i+addlen-1][0] = labels[i][0];
        }
        for(int i=sta,j=0;i<sta+addlen;i++,j++){
            labels[i][0] = alphabet[sta];
            labels[i][1] = alphabet[j];
        }
        cnt += addlen-1;
        end += addlen-1;
        sta--;
    }
    return cnt;
}

/**
 * 打印一个标签。
 *
 * @param label 要打印的标签
 */
void print_label(const char label[LABEL_LEN]) {
    if(label[1] != '\0')
        printf("%c%c\n",label[0],label[1]);
    else
        printf("%c\n",label[0]);
}
