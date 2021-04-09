#!/bin/bash
rm -rf ./build/
mkdir ./build
gcc ./src/main.c ./src/lib/system.c ./src/lib/scene.c ./src/lib/player.c ./src/lib/map.c ./src/lib/item.c ./src/lib/enemy.c ./src/lib/battle.c -o ./build/cliquest -I ./include
#-o : 出力ファイル名を指定
#-I : インクルードディレクトリを指定
#-W : 警告メッセージを表示
#-v : 標準ライブラリの参照を表示

#実行
echo ">>>>>>>>>>cliquest run<<<<<<<<<<<"
./build/cliquest