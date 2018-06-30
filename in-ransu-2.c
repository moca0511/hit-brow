#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int himitsu[4]={10,10,10,10};   //1回はループできるように初期１０   
    int ans[4]; //回答用
    int hin;    //入力方法指定用変数
    int f,j;    //ループ制御変数
    int hit,brow,ran,incount; //hit、brow、乱数、回答回数
    int ten;    //点数
    long stime,etime,ttime; //時間取得用変数
    char hyouka,end;    //評価用、終了用
    int gamecount=0;    //ゲーム継続回数用
    system("CLS");
    printf("\n\n                 HIT & BROW");
    printf("\n\n\n\n\n\n                Enterで開始");
    getchar();
    do{
        end=0;  //強制中断回避
        system("CLS");
        printf("\n秘密の数字の設定方法を選んでください。\n");
        for(;;){ //１か２を入力したら次処理へ
            printf("手入力：１　ランダム：２\n");    
            scanf("%d",&hin);
            if(hin==1||hin==2)break; 
            printf("もう一度\n");
        }

        switch(hin){
            case 1:
                if(gamecount>=1){   //1個前のhimitsuリセット
                    for(j=0;j<4;j++){       
                        himitsu[j]=10;
                    }
                }
                for(f=0;f<4;f++){       //入力ループ                   
                    brow=0;         //重複カウントリセット 
                do{
                    printf("数字%d:",f+1);
                    scanf("%d",&himitsu[f]);
                    if(himitsu[f]>9 || himitsu[f]<0){     //０～９のみ入力
                        printf("0-9を入力してください。\n");
                    }                                       
                }while(himitsu[f]>9 || himitsu[f]<0);     //０～９以外の時繰り返し
                    for(j=0;j<4;j++){                           //重複カウントループ
                        if(himitsu[f]==himitsu[j]&&f!=j){
                            brow++;                             //重複すれば＋１
                        }
                        if(brow!=0){        //重複すれば再入力
                            printf("%dはすでに使われています。違う数を入力してください。\n",himitsu[f]);                            
                            do{         //再度入力ループ
                                printf("数字%d:",f+1);
                                scanf("%d",&himitsu[f]);
                                if(himitsu[f]>9 || himitsu[f]<0){     //０～９のみ入力
                                    printf("0-9を入力してください。\n");
                                }                                       
                            }while(himitsu[f]>9 || himitsu[f]<0);     
                            j--;                                       //もう一度himitsu[0]から重複チェック
                        }
                        brow=0; //重複カウントリセット
                    }
                }
                system("CLS");
                break;
            case 2:
                srand((unsigned int)time(NULL));    //疑似乱数初期化

                for(f=0;f<4;f++){   //乱数入力ループ
                    do{
                        brow=0;         //重複カウント初期化
                        ran=rand()%9+1; //1~9までランダム
                        himitsu[f]=ran; //配列に代入
                        for(j=0;j<4;j++){   //重複カウントループ
                            if(himitsu[f]==himitsu[j]&&f!=j){
                                brow++; //重複すればカウント＋１
                            }
                        }
                    }while(brow!=0);    //重複しなくなくなるまで
                }
        }
        getchar();
        printf("Enterキーでスタート");
        getchar();
        stime=(long)time(NULL); //スタートタイム計測
        incount=0;                //カウント初期化
        system("CLS");
        printf("hit&brow start!\n\n");
        do{
            hit=0;      //hit brow初期化
            brow=0;     //
            for(f=0;f<4;f++){   //入力ループ
                do{
                    printf("数字%d:",f+1);
                    scanf("%d",&ans[f]);
                        if(ans[f]>=10 || ans[f]<0){
                            printf("0-9を入力してください。\n");
                        }
                }while(ans[f]>=10 || ans[f]<0);
                if(ans[f]==himitsu[f]){     //hit確認ループ
                    hit++;
                }
                for(j=0;j<4;j++){   //brow確認ループ
                    if(ans[f]==himitsu[j]&&f!=j){
                        brow++;
                    }
                }
            }
            incount++;    //回数カウント
            printf("hit:%d\n",hit);
            printf("brow:%d\n",brow);
            printf("%d回目\n\n",incount);
            if(incount%10==0&&hit!=4){    //１０回ごとに終了確認
                printf("諦めますか？y/n >:");
                scanf("%*c%c",&end);
                if(end=='y'){
                    return 0;
                }
                printf("\n");
            }   
        }while(hit<4);
        etime=(long)time(NULL);     //終了時間計測
        system("CLS");
        printf("終了！！\n");
        printf("Enterでスコア画面に移動");
        getchar();
        getchar();
                                //点数計算
        ttime=etime-stime;      //回答時間計算
        ttime=(100-ttime)/4;    //回答時間点数計算
        incount=(40-incount)*2;     //回答回数点数計算
        ten=ttime+incount;        //合計点数
        if(ten>100){            //０～１００点までに指定
            ten=100;
        }
        if(ten<0){
            ten=0;
        }
        if(ten>=95){                    //評価判断
            hyouka='S';
        }else{
            if(ten>=80){
                hyouka='A';
            }else{
                if(ten>=60){
                    hyouka='B';
                    }else{
                        if(ten>=40){
                            hyouka='C';
                        }else{
                            hyouka='D';
                    }
                }
            }
        }
        end=0;
        system("CLS");
        printf("答えは");
        for(f=0;f<4;f++){
            printf(" %d",himitsu[f]);
        }
        printf("\n%d点\n",ten);
        printf("評価：%c\n\n",hyouka);
        printf("続けて遊びますか？y/n >:");
        scanf("%c",&end);
        gamecount++;    //ゲーム回数＋１
        }while(end=='y');       //endにyを入力するまでゲーム実行
        printf("ゲームを終了します。");
        getchar();
        getchar();
        return 0;
    }