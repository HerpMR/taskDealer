# taskDealer
For doing my assignment of Operating System class.


## 実装等の環境
* Sublime Text 3 for Windows
* cmd.exe  
* MinGW GCC 6.3.0  
学情の `$ gcc` はバージョンが古くコンパイル時にエラーが発生するので `$ gcc -std=c99 ...` でのコンパイルを強く推奨します。


## 同梱のテストケースについて
配布されたレジュメ、講義用ページに提出不要課題として掲載されていたものなどを使用しています。
なおテストケースNo.2とNo.3は自作のデータです。
`testcases` ディレクトリに入っているテストケースを用いる場合は全体をコピペしてターミナルでペーストしてください。 

テストケースは以下の形式で標準入力からスペース1つ、改行により与えられるものに限ります。

N：テストケースの数  
name：タスク名称  
t_arrival：タスクの到着時間  
t_cost：そのタスクを処理するのに必要な時間  
```
N
TASK[1].name  TASK[1].t_arrival  TASK[1].t_cost  
TASK[2].name  TASK[2].t_arrival  TASK[2].t_cost  
TASK[3].name  TASK[3].t_arrival  TASK[3].t_cost  
			：  
```
