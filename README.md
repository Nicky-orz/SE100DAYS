# SE100DAYS
This is a record about a new software engineering student, documenting his 100 days of programming experience


这是一个记录软工新生学习编程100天的仓库

> 文件按算法分类存放，命名规则为 `题目编号 + 简短英文描述`（如 `p2440.cpp`、`p1536villagepath.cpp`）。

---

## 总览

| Day | 日期 | 题目数 | 主要内容 | 状态 |
| --- | --- | ---: | --- | --- |
| Day01 | 08-26 | 2 | 模拟、统计 | 已完成 |
| Day02 | 08-27 | 2 | 字符串、枚举、质数 | 已完成 |
| Day03 | 08-28 | 2 | 高精度、模拟 | 已完成 |
| Day04 | 08-29 | 0 | 休息 | 休息爽 |
| Day05 | 08-30 | 1 | 高精度乘法 | 已完成 |
| Day06 | 08-31 | 1 | 递归、字符串解析 | 已完成 |
| Day07 | 09-01 | 2 | 贪心、递推 | 已完成 |
| Day08 | 09-02 | 4 | 逆序对、DP、分治、二分 | 已完成 |
| Day09 | 09-03 | 1 | 快速幂、栈 | 已完成 |
| Day10 | 09-04 | 1 | DFS / 连通块 | 已完成 |
| Day11 | 09-05 | 0 | 休息 | 休息爽 |
| Day12 | 09-06 | 3 | BFS、DFS、回溯 | 已完成 |
| Day13 | 09-07 | 1 | 数组 / STL | 已完成 |
| Day14 | 09-08 | 3 | 链表、栈、map | 已完成 |
| Day15 | 09-09 | 2 | 栈、队列 | 已完成 |
| Day16 | 09-10 | 1 | 二叉树 | 已完成 |
| Day17 | 09-11 | 4 | 二叉树遍历 | 已完成 |
| Day18 | 09-12 | 1 | 二叉树遍历计数 | 已完成 |
| Day19 | 09-13 | 1 | 二叉搜索树 | 已完成 |
| Day20 | 09-14 | 1 | 二叉树深度 / LCA | 已完成 |
| Day21 | 09-15 | 1 | 二叉树绘制 / 模拟 | 已完成 |
| Day22 | 09-16 | 1 | 并查集 | 已完成 |
| Day23 | 09-17 | 2 | 字符串哈希、并查集 | 已完成 |
| Day24 | 09-18 | 3 | map / set / 哈希 | 已完成 |
(一周写一次总览)

## Day01 - 08-26

- 题目：
  - [P5730](https://www.luogu.com.cn/problem/P5730) 【深基5.例10】显示屏
  - [P1554](https://www.luogu.com.cn/problem/P1554) [USACO06DEC] 梦中的统计 Dream Counting B
- 知识点：模拟、数组、统计
- 文件：`misc/p5730.cpp`、`misc/p1554.cpp`
- 状态：已完成

---

## Day02 - 08-27

- 题目：
  - [P1125](https://www.luogu.com.cn/problem/P1125) [NOIP 2008 提高组] 笨小猴
  - [P2141](https://www.luogu.com.cn/problem/P2141) [NOIP 2014 普及组] 珠心算测验
- 知识点：字符串、字符统计、质数判断、枚举
- 文件：`misc/p1125.cpp`、`misc/p2141.cpp`
- 状态：已完成

---

## Day03 - 08-28

- 题目：
  - [P1601](https://www.luogu.com.cn/problem/P1601) 高精度加法
  - [P1067](https://www.luogu.com.cn/problem/P1067) [NOIP 2009 普及组] 多项式输出
- 知识点：高精度、模拟、边界处理
- 文件：`misc/p1601.cpp`、`misc/p1067.cpp`
- 易错点：多项式系数为 0、1、-1 等特殊情况
- 状态：已完成

---

## Day04 - 08-29

- 休息，爽！

---

## Day05 - 08-30

- 题目：
  - [P1303](https://www.luogu.com.cn/problem/P1303) A*B Problem
- 知识点：高精度乘法
- 文件：`misc/p1303.cpp`
- 易错点：进位、前导零
- 状态：已完成

---

## Day06 - 08-31

- 题目：
  - [P1928](https://www.luogu.com.cn/problem/P1928) 外星密码
- 知识点：递归、字符串解析
- 文件：`misc/p1928.cpp`
- 易错点：括号嵌套、数字读取
- 状态：已完成

---

## Day07 - 09-01

- 题目：
  - [P1803](https://www.luogu.com.cn/problem/P1803) 凌乱的yyy / 线段覆盖
  - [P1990](https://www.luogu.com.cn/problem/P1990) 覆盖墙壁
- 知识点：贪心、区间调度、递推 / DP
- 文件：`greedy/p1803.cpp`、`dp/p1990.cpp`
- 易错点：贪心排序规则、递推边界
- 状态：已完成

---

## Day08 - 09-02

- 题目：
  - [P1908](https://www.luogu.com.cn/problem/P1908) 逆序对
  - [P1115](https://www.luogu.com.cn/problem/P1115) 最大子段和
  - [P1228](https://www.luogu.com.cn/problem/P1228) 地毯填补问题
  - [P2440](https://www.luogu.com.cn/problem/P2440) 木材加工
- 知识点：归并排序、DP、分治、二分答案
- 文件：`dc/p1908.cpp`、`dc/p1115.cpp`、`search/p1228.cpp`、`binary_search/p2440.cpp`
- 易错点：二分边界、递归分治坐标
- 状态：已完成

---

## Day09 - 09-03

- 题目：
  - [P1226](https://www.luogu.com.cn/problem/P1226) 【模板】快速幂
- 知识点：快速幂、栈
- 文件：`dc/p1226.cpp`
- 易错点：取模
- 状态：已完成

---

## Day10 - 09-04

- 题目：
  - [P1596](https://www.luogu.com.cn/problem/P1596) [USACO10OCT] Lake Counting S
- 知识点：DFS / BFS、连通块
- 文件：`search/p1596.cpp`
- 易错点：方向数组、边界判断
- 状态：已完成

---

## Day11 - 09-05

- 休息，爽！

---

## Day12 - 09-06

### 从今天开始正式建仓，题目按算法分类归档。

- 题目：
  - [P1825](https://www.luogu.com.cn/problem/P1825) [USACO11OPEN] Corn Maze S
  - [P1162](https://www.luogu.com.cn/problem/P1162) 填涂颜色
  - [P1219](https://www.luogu.com.cn/problem/P1219) [USACO1.5] 八皇后 Checker Challenge
- 知识点：BFS、DFS、回溯、迷宫、连通块
- 文件：`search/p1825CornMazeS.cpp`、`search/p1162fillcolor.cpp`、`search/p1219CheckerChallenge.cpp`
- 易错点：BFS 访问标记、八皇后对角线判断
- 状态：已完成

---

## Day13 - 09-07

- 题目：
  - [P3156](https://www.luogu.com.cn/problem/P3156) 【深基15.例1】询问学号
- 知识点：数组、STL
- 文件：`linealist/p3156requestnumber.cpp`
- 易错点：下标从 1 开始
- 状态：已完成

---

## Day14 - 09-08

- 题目：
  - [P1160](https://www.luogu.com.cn/problem/P1160) 队列安排
  - [P1449](https://www.luogu.com.cn/problem/P1449) 后缀表达式
  - [P3613](https://www.luogu.com.cn/problem/P3613) 【深基15.例2】寄包柜
- 知识点：链表、栈、map / vector
- 文件：`linealist/p1160queuearrangement.cpp`、`linealist/p1449postfixexpression.cpp`、`linealist/p3613parcellocker.cpp`
- 易错点：链表插入删除、后缀表达式读入
- 状态：已完成

---

## Day15 - 09-09

- 题目：
  - [P1241](https://www.luogu.com.cn/problem/P1241) 括号序列
  - [P1540](https://www.luogu.com.cn/problem/P1540) [NOIP 2010 提高组] 机器翻译
- 知识点：栈、队列、模拟
- 文件：`linealist/p1241bracketsequence.cpp`、`linealist/p1540machinetranslate.cpp`
- 易错点：括号匹配规则、队列容量
- 状态：已完成

---

## Day16 - 09-10

- 题目：
  - [P4715](https://www.luogu.com.cn/problem/P4715) 【深基16.例1】淘汰赛
- 知识点：二叉树、模拟
- 文件：`tree/p4715knockoutcompetition.cpp`
- 易错点：节点编号与比赛轮次
- 状态：已完成

---

## Day17 - 09-11

### 二叉树专题集中训练

- 题目：
  - [P1305](https://www.luogu.com.cn/problem/P1305) 新二叉树
  - [P1030](https://www.luogu.com.cn/problem/P1030) [NOIP 2001 普及组] 求先序排列
  - [P1827](https://www.luogu.com.cn/problem/P1827) [USACO3.4] 美国血统 American Heritage
  - [P4913](https://www.luogu.com.cn/problem/P4913) 【深基16.例3】二叉树深度
- 知识点：二叉树遍历、先序 / 中序 / 后序、深度
- 文件：`tree/p1305newtree.cpp`、`tree/p1030forpre.cpp`、`tree/p1827AmericanHeritage.cpp`、`tree/p4913treedepth.cpp`
- 易错点：遍历区间划分、递归边界
- 状态：已完成

---

## Day18 - 09-12

- 题目：
  - [P1229](https://www.luogu.com.cn/problem/P1229) 遍历问题
- 知识点：二叉树遍历、计数
- 文件：`linealist/p1229orderproblem.cpp`
- 易错点：只有一个子节点时的不确定性
- 状态：已完成

---

## Day19 - 09-13

- 题目：
  - [P5076](https://www.luogu.com.cn/problem/P5076) 【深基16.例7】普通二叉树（简化版）
- 知识点：二叉搜索树、STL
- 文件：`tree/p5076simpletree.cpp`
- 易错点：前驱后继查询、重复元素
- 状态：已完成

---

## Day20 - 09-14

- 题目：
  - [P3884](https://www.luogu.com.cn/problem/P3884) [JLOI2009] 二叉树问题
- 知识点：二叉树深度、宽度、LCA
- 文件：`tree/p3884treeproblem.cpp`
- 易错点：层宽统计、最近公共祖先
- 状态：已完成

---

## Day21 - 09-15

- 题目：
  - [P1185](https://www.luogu.com.cn/problem/P1185) 绘制二叉树
- 知识点：二叉树、模拟、递归绘制
- 文件：`tree/p1185drawtree.cpp`
- 易错点：字符坐标、递归层次
- 状态：已完成

---

## Day22 - 09-16

- 题目：
  - [P1551](https://www.luogu.com.cn/problem/P1551) 亲戚
- 知识点：并查集
- 文件：`set/p1551relative.cpp`
- 易错点：路径压缩、合并方向
- 状态：已完成

---

## Day23 - 09-17

- 题目：
  - [P3370](https://www.luogu.com.cn/problem/P3370) 【模板】字符串哈希
  - [P1536](https://www.luogu.com.cn/problem/P1536) 村村通
- 知识点：字符串哈希、并查集
- 文件：`set/p3370stringhash.cpp`、`set/p1536villagepath.cpp`
- 易错点：哈希冲突、连通块计数
- 状态：已完成

---

## Day24 - 09-18

### 今天开始把C语言OJ的作业也上传上来

- 题目：
  - [P5266](https://www.luogu.com.cn/problem/P5266) 【深基17.例6】学籍管理
  - [P5250](https://www.luogu.com.cn/problem/P5250) 【深基17.例5】木材仓库
  - [P3405](https://www.luogu.com.cn/problem/P3405) [USACO16DEC] Cities and States S
- 知识点：map、set、哈希、STL
- 文件：`set/p5266managefile.cpp`、`set/p5250woodwarehouse.cpp`、`set/p3405CitiesandStates.cpp`
- 易错点：map 查找、set 前驱后继、字符串组合哈希
- 状态：已完成

---
## Day25 - 09-19

### 从今天开始写README!

- 题目：
  - [P1102](https://www.luogu.com.cn/problem/P1102) A-B 数对
  - [P1918](https://www.luogu.com.cn/problem/P1918) 保龄球
- 知识点：哈希表开放寻址法
- 文件：`set/p1102aminusb.cpp`、`set/p1918bowling.cpp`
- 易错点：哈希键类型选用
- 状态：已完成

---