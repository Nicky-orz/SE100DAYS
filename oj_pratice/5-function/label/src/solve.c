#include "solve.h"
#include<stdio.h>
#include "label.h"
#include "const.h"

/**
 * 为 nums 里的数字各贴一个标签，再按照出现的先后顺序逐行打印。
 *
 * @param nums     输入的 n 个数字。
 * @param n        数字的个数。
 * @param alphabet 字母表。
 */
void solve(const int nums[], int n, const char* alphabet) {
    bool num[MAX_NUM+5]={false};
    int ans[3005]={};
    char labels[MAX_LABELS][LABEL_LEN];
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(!num[nums[i]]){
            ans[cnt++] = nums[i];
            num[nums[i]] = true;
        }
    }
    compute_labels(alphabet,cnt,labels);
    for(int i=0;i<cnt;i++){
        printf("%d: ",ans[i]);
        print_label(labels[i]);
    }
}
