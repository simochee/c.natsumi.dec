//
// ５個のサイコロを振った時、目の積が100を超える確率を求めるプログラム
//  = ひたすらランダムに５個のサイコロの積を求めて100を超えた回数をカウント
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int i, j;
  // 各試行でのトータルの積
  int total = 1;
  // 全体で100を超えた回数
  int count = 0;
  // 試行回数
  int max = 100000;

  // 乱数の種を初期化
  srand(time(NULL));

  for (i = 0; i < max; i++) {
    // 積の合計をリセット
    total = 1;
    for (j = 0; j < 5; j++) {
      // 乱数を使ってさいの目を決定
      // rand() : とても大きな整数（ex.1605031240（
      // rand()を６で割ったあまり（0~5）に1を足せばサイコロの目が出る
      total = total * (rand() % 6 + 1);
    }

    // 積の合計が100を超えていたらcountを増やす
    if (total > 100) {
      count++;
    }
  }

  // %にするために100をかけた
  printf("５個のサイコロの積が100を超える確率は%f％です", (double)count / max * 100);

  return 0;
}