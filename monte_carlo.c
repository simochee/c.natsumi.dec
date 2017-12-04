//
// モンテカルロ法を用いて円周率の近似値を求めるプログラム
// モンテカルロ法：https://mathtrain.jp/montecarlo
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int i;
  int count = 0;
  int max = 100000;
  double x, y, z, pi;

  // 乱数の種を初期化
  srand(time(NULL));

  // [0, 1]の乱数を生成、出力
  for (i = 0; i < max; i++) {
    // x, y平面にランダムな座標を決める
    x = (double)rand() / RAND_MAX;
    y = (double)rand() / RAND_MAX;
    
    // 座標の中心からの距離を計算
    z = x * x + y * y;
    
    // zが1より小さい＝円の内側なのでカウント
    if (z < 1) {
      count++;
    }
  }

  // 円周率を計算 (4X/N)
  pi = (double)count / max * 4;

  printf("%f\n", pi);

  return 0;
}