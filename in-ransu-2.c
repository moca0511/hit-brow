#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int himitsu[4]={10,10,10,10};   //1��̓��[�v�ł���悤�ɏ����P�O   
    int ans[4]; //�񓚗p
    int hin;    //���͕��@�w��p�ϐ�
    int f,j;    //���[�v����ϐ�
    int hit,brow,ran,incount; //hit�Abrow�A�����A�񓚉�
    int ten;    //�_��
    long stime,etime,ttime; //���Ԏ擾�p�ϐ�
    char hyouka,end;    //�]���p�A�I���p
    int gamecount=0;    //�Q�[���p���񐔗p
    system("CLS");
    printf("\n\n                 HIT & BROW");
    printf("\n\n\n\n\n\n                Enter�ŊJ�n");
    getchar();
    do{
        end=0;  //�������f���
        system("CLS");
        printf("\n�閧�̐����̐ݒ���@��I��ł��������B\n");
        for(;;){ //�P���Q����͂����玟������
            printf("����́F�P�@�����_���F�Q\n");    
            scanf("%d",&hin);
            if(hin==1||hin==2)break; 
            printf("������x\n");
        }

        switch(hin){
            case 1:
                if(gamecount>=1){   //1�O��himitsu���Z�b�g
                    for(j=0;j<4;j++){       
                        himitsu[j]=10;
                    }
                }
                for(f=0;f<4;f++){       //���̓��[�v                   
                    brow=0;         //�d���J�E���g���Z�b�g 
                do{
                    printf("����%d:",f+1);
                    scanf("%d",&himitsu[f]);
                    if(himitsu[f]>9 || himitsu[f]<0){     //�O�`�X�̂ݓ���
                        printf("0-9����͂��Ă��������B\n");
                    }                                       
                }while(himitsu[f]>9 || himitsu[f]<0);     //�O�`�X�ȊO�̎��J��Ԃ�
                    for(j=0;j<4;j++){                           //�d���J�E���g���[�v
                        if(himitsu[f]==himitsu[j]&&f!=j){
                            brow++;                             //�d������΁{�P
                        }
                        if(brow!=0){        //�d������΍ē���
                            printf("%d�͂��łɎg���Ă��܂��B�Ⴄ������͂��Ă��������B\n",himitsu[f]);                            
                            do{         //�ēx���̓��[�v
                                printf("����%d:",f+1);
                                scanf("%d",&himitsu[f]);
                                if(himitsu[f]>9 || himitsu[f]<0){     //�O�`�X�̂ݓ���
                                    printf("0-9����͂��Ă��������B\n");
                                }                                       
                            }while(himitsu[f]>9 || himitsu[f]<0);     
                            j--;                                       //������xhimitsu[0]����d���`�F�b�N
                        }
                        brow=0; //�d���J�E���g���Z�b�g
                    }
                }
                system("CLS");
                break;
            case 2:
                srand((unsigned int)time(NULL));    //�^������������

                for(f=0;f<4;f++){   //�������̓��[�v
                    do{
                        brow=0;         //�d���J�E���g������
                        ran=rand()%9+1; //1~9�܂Ń����_��
                        himitsu[f]=ran; //�z��ɑ��
                        for(j=0;j<4;j++){   //�d���J�E���g���[�v
                            if(himitsu[f]==himitsu[j]&&f!=j){
                                brow++; //�d������΃J�E���g�{�P
                            }
                        }
                    }while(brow!=0);    //�d�����Ȃ��Ȃ��Ȃ�܂�
                }
        }
        getchar();
        printf("Enter�L�[�ŃX�^�[�g");
        getchar();
        stime=(long)time(NULL); //�X�^�[�g�^�C���v��
        incount=0;                //�J�E���g������
        system("CLS");
        printf("hit&brow start!\n\n");
        do{
            hit=0;      //hit brow������
            brow=0;     //
            for(f=0;f<4;f++){   //���̓��[�v
                do{
                    printf("����%d:",f+1);
                    scanf("%d",&ans[f]);
                        if(ans[f]>=10 || ans[f]<0){
                            printf("0-9����͂��Ă��������B\n");
                        }
                }while(ans[f]>=10 || ans[f]<0);
                if(ans[f]==himitsu[f]){     //hit�m�F���[�v
                    hit++;
                }
                for(j=0;j<4;j++){   //brow�m�F���[�v
                    if(ans[f]==himitsu[j]&&f!=j){
                        brow++;
                    }
                }
            }
            incount++;    //�񐔃J�E���g
            printf("hit:%d\n",hit);
            printf("brow:%d\n",brow);
            printf("%d���\n\n",incount);
            if(incount%10==0&&hit!=4){    //�P�O�񂲂ƂɏI���m�F
                printf("���߂܂����Hy/n >:");
                scanf("%*c%c",&end);
                if(end=='y'){
                    return 0;
                }
                printf("\n");
            }   
        }while(hit<4);
        etime=(long)time(NULL);     //�I�����Ԍv��
        system("CLS");
        printf("�I���I�I\n");
        printf("Enter�ŃX�R�A��ʂɈړ�");
        getchar();
        getchar();
                                //�_���v�Z
        ttime=etime-stime;      //�񓚎��Ԍv�Z
        ttime=(100-ttime)/4;    //�񓚎��ԓ_���v�Z
        incount=(40-incount)*2;     //�񓚉񐔓_���v�Z
        ten=ttime+incount;        //���v�_��
        if(ten>100){            //�O�`�P�O�O�_�܂łɎw��
            ten=100;
        }
        if(ten<0){
            ten=0;
        }
        if(ten>=95){                    //�]�����f
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
        printf("������");
        for(f=0;f<4;f++){
            printf(" %d",himitsu[f]);
        }
        printf("\n%d�_\n",ten);
        printf("�]���F%c\n\n",hyouka);
        printf("�����ėV�т܂����Hy/n >:");
        scanf("%c",&end);
        gamecount++;    //�Q�[���񐔁{�P
        }while(end=='y');       //end��y����͂���܂ŃQ�[�����s
        printf("�Q�[�����I�����܂��B");
        getchar();
        getchar();
        return 0;
    }