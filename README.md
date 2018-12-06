# taskScheduler
For doing my assignment of Operating System class.
  

## 実装等の環境
* Sublime Text 3 for Windows
* cmd.exe  
* MinGW GCC-6.3.0  
学情の `$ gcc` はバージョンが古くコンパイル時にエラーが発生するので `$ gcc -std=c99 ...` でのコンパイルを強く推奨します。
  

## ソースファイルのファイル名について
ファイル名の拡張子を除いた部分が `"○○○_×××"` である場合については、  
`○○○` が  
* `Clang` ：C言語（MinGW GCC-6.3.0）  
* `Python` ：Python（Python 3.5.2, Anaconda 4.2.0 (64-bit)）  
* `Ruby` ： ~最新版Ruby（Rubyわからん、というよりは環境構築する気が起きない）~  
  
`×××` が  
* `arrival` ：到着順  
* `dealtime` ：処理時間順  
* `roundrobin` ：ラウンドロビン方式  
  
のようにしてあります。
  

## 同梱のテストケースについて
配布されたレジュメ、講義用ページに提出不要課題として掲載されていたものなどを使用しています。
なおテストケースNo.2とNo.3は自作のデータです。
`testcases` ディレクトリに入っているテストケースを用いる場合は全体をコピーしてターミナルでペーストしてください。 
なお、 ラウンドロビン方式の実行ファイルに関してはペースト後、 **定時間を整数型数値で入力して** ください。  

テストケースは以下の形式・制約を満たした上で標準入力からスペース1つ、改行により与えられるものに限ります。  

(char* [20]) name：タスク名称  
(int) N：テストケースの数  
(int) t_arrival：タスクの到着時間  
(int) t_cost：そのタスクを処理するのに必要な時間  
(int) lim：（ラウンドロビン方式のみ）定時間

```
N
TASK[1].name  TASK[1].t_arrival  TASK[1].t_cost  
TASK[2].name  TASK[2].t_arrival  TASK[2].t_cost  
TASK[3].name  TASK[3].t_arrival  TASK[3].t_cost  
			：  
TASK[N - 1].name  TASK[N - 1].t_arrival  TASK[N - 1].t_cost  
lim // ←ラウンドロビン方式のみ入力  
```
  
## 出力
基本的には各タスク名と到着時間、処理完了時間が表示されます。  
最後の整数値はすべてのタスクが完了した時の時間が表示されます。  
void関数 `printstatus(...){...}` の内の `printf(...)` をコメントアウトすると詳細の表示が省略されます。
