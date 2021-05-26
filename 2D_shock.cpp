// 2D_shock.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAIN_C_

#include "global.h"
#include "grid.h"
#include "initial.h"
#include "boundary.h"
#include "read.h"
#include "fds.h"
#include "rungekutta.h"
#include "calc.h"
#include "output.h"

int main(void) {

    for (int ina = 0; ina < 10; ina++) {
        //printf("Coded by Doraemon!!\n");
    }

    inputSetting();
    inputInitialValue();
    areaSet();
    makeGrid();
    defineGrid();
    defineGeneralGrid();
    initialValue();
    boundaryValue();
    calcInternalValues();
    setAssumedPotential();

    while (time <= time_max) {
        makePotential();
        //fdsXdir();
        //fdsYdir();
        fds(X_DIR);
        fds(Y_DIR);
        rungekutta();
        inversePotentialToParams();
        boundaryValue();
        time = time + time_step;
        printTimer();
        exportf();
        for (int k = 0; k < split; k++) {
            if (isnan(rho[k])) {
                printf("Not a number!\n");
                printf("%lf, %d\n", time, k);
                ErrorExport();
                exit(1);
            }
        }
    }
    printf("All calculation is finished.\n");
    exportf();
    releaseAssumedPotential();
    freeGrid();
    return 0;
}



// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
