#include<stdio.h>
#include<string.h>
#include<mysql.h>
#include<errno.h>
#include<stdlib.h>
#include<time.h>

void connect_db();
void errPrint1(MYSQL *);
void errPrint2(int);
void execQuery(char *);
void printResult();
void printResult1();
void main_menu();
void select_menu(int);
void print_error();
void execQuery(char *);
void store_result();
char *resultArray();
char *resultArray1(); //phone 출력
char *Rand(); //랜덤함수
char GetR();
int GetR1();
void checkcode();
void mem_pwd();
void mem_pwi();//char *str)
char *member_cnum(char *);
//관리자 부함수
void acheck();
void manager_print();
int manager_input();
char *manager_input1(); //없어도 된다.

void manager_sel(int); //관리자 메뉴 선택
void manager_deal(int);
void manager_dlist(); //관리자 판매내역 구매내역 보여주기
void manager_bInfo(); //구매 테이블 디비에서 보여주기
void manager_slist();//판매 리스트 조작할 수 있는 항목 보여주기
void manager_sel_slist(int); //
void manager_sInfo(); //판매테이블 리스트 보기
void manager_sregister(char *); //판매 테이블에 차량 가격입력
void manager_cartInfo(); //차 테이블을 보여준다.
void manager_mpriceshow(); //정비 메뉴 보여주기
void manager_cartregister(); //차 테이블에 새로운 차를 추가
void manager_mainten(int);  //정비 선택 메뉴
void manager_mlist(); //정비관련  리스트 보여주기
void manager_mInfo(); //정비 업체 보여주기
void manager_maintenregi(); //정비 후 가격 등록
void manager_stlist(); //직원 리스트 선택
void manager_staff(); //선택 스위치
void manager_stregister(); //직원 등록
void manager_stfire(); //직원 해고
void manager_stchange(); //직원 정보 변경


//손님 부함수
void member_into();
void member_Signup();
char *member_Signup1();
void member_login();
void member_print();
int member_input();
void member_sel(int,int);
void member_blist();
void member_sel_blist();
void member_search_all();
void member_search_com();
void member_search_mod();
void member_search_col();

void member_slist();

void member_custser();
void member_sel_clist(int);
void member_ephone();
void member_elist();

void member_event();//경
void member_event_list(int);//경
void member_event_ran();//경
void member_event_go(char a);//경
void member_event_check();//경
void member_event_input();//경
  

void member_deal(int);
void member_sel_dlist(int,int);
void member_sellshow(int);
void member_buyshow(int);
void just_buy();
int count_buy();//민
  
 //테이블 보여주기
void showEmployee(); //전체직원보여주기
 //전역변수

MYSQL mysql;
MYSQL_RES *res;
MYSQL_ROW row;
MYSQL_FIELD *field;
char q2[100] ="select * from Automobile;";
char str[1000];
int fields, re_num, rows, note;
int pwd = 1234;
 
int main(void)
 {
     int menu_num;

     connect_db();
     //check();
     while(1)
     {
        main_menu();
         printf("메뉴 입력 :");
         scanf("%d",&menu_num);

         if(menu_num == 0)
         {
             printf("프로그램을 종료합니다.\n");
     //      mysql_free_result(res);
             mysql_close(&mysql);
             break;
         }
         select_menu(menu_num);
     }

     return 0;
 }

 void connect_db()
 {
     mysql_init(&mysql);
     errPrint1(mysql_real_connect(&mysql,"mydatabase.czfinfuiiju7.ap-northea     st-2.rds.amazonaws.com","root","qlqjs5910!", "team",0,NULL,0));
 }
 
void errPrint1(MYSQL *p)
{
         if(!p){
                 fprintf(stderr,"%s\n",mysql_error(&mysql));
                 exit(1);
         }
 }

 void errPrint2(int n)
  {
        if(n == 0){
                 fprintf(stderr,"%s\n",mysql_error(&mysql));
                 exit(1);
         }
 }
 void execQuery(char *query)
 {
      errPrint2(!mysql_real_query(&mysql,query,strlen(query)));

      res = mysql_store_result(&mysql);
      fields = mysql_num_fields(res);
      rows = (int)mysql_num_rows(res);
 }
char *resultArray()
 {
         int i,j;
         for(i=0; i<rows;i++)
            row=mysql_fetch_row(res);
         return row[0];
 }

char *resultArray1()
{
         int i,j;
         for(i=0; i<rows;i++)
            row=mysql_fetch_row(res);
         return row[0];
 }


void printResult()
{
      int i,j;
     field = mysql_fetch_fields(res);

      for(i=0;i<fields;i++)
                 printf("%s\t",field[i].name);

      printf("\n------------------------------------------\n");

      for(i=0; i<rows; i++)
      {
          row = mysql_fetch_row(res);
          for(j=0; j<fields; j++)
              printf("%s\t",row[j]);
          printf("\n");
      }
 }
void printResult1(){

      int i,j;
       field = mysql_fetch_fields(res);
 
       for(i=0;i<fields;i++)
                  printf("%s\t",field[i].name);
 
       printf("\n------------------------------------------\n");
 
       for(i=0; i<rows; i++)
       {
           row = mysql_fetch_row(res);
          for(j=0; j<fields; j++)
              printf("%s\t",row[j]);
          printf("\n");
      }

 }


 void main_menu()
 {
     system("clear");
     printf("------------------메뉴------------------\n");
     printf("             1. 관리자                  \n");
     printf("             2. 고객                    \n");
     printf("             0. 종료                    \n");
     printf("----------------------------------------\n");
 }
 void select_menu(int n)
 {
    int num;

     switch(n)
     {
         case 1:
             acheck();
             break;

         case 2:

             member_into();
             break;
         case 0:
             exit(1);
         default:
             break;
     }

 }

                                                                      
 void manager_print()
 {
     system("clear");
     int num;

     printf("------------------------------\n");
     printf("       1. 거래      \n");
     printf("       2. 차량등록         \n");
     printf("       3. 정비업체 정비                \n");
     printf("       4. 직원                \n");
     printf("       0. 상위메뉴 이동       \n");
     printf("------------------------------\n");
     num=manager_input();
     manager_sel(num);
 }


 int manager_input()
 {
     int num;
     printf(" 메뉴입력 : ");
     scanf("%d",&num);
     return num;
 }

 void acheck()
 {
     int num;
     printf("관리자 패스워드를 입력하시오 ");
     scanf("%d",&pwd);
     while(1){
             if(pwd==1234){
             printf("로그인 완료!!\n");
              manager_print();
             break;
             }
             else{
                     printf("패스워드 오류!\n");
                     break;
             }
     }
 }

 void manager_sel(int n)
 {

     int num;
     switch(n)
     {
         case 1:
             manager_dlist(); //매매 메뉴보기manager_info_input
             break;
         case 2:
             manager_cartInfo();
             manager_cartregister();
             break;
         case 3:
             manager_mlist();
             break;
         case 4:
             manager_stlist();
             break;
         default:
             break;
     }

 }
 void manager_dlist()
 {
     int num;
     system("clear");

     printf("------------------------------\n");
     printf("       1. 구매내역       \n");
     printf("       2. 판매내역 및 등록         \n");
     printf("       0. 상위메뉴 이동       \n");
     printf("------------------------------\n");
     num = manager_input();
     manager_deal(num);
 }


 void manager_deal(int n)
 {

     int num;
     switch(n)
     {
         case 1:
             manager_bInfo();
             break;
         case 2:
             manager_slist();
             break;
         case 0:
             manager_print();
             break;
         default:
             break;
     }
 }

 void manager_bInfo()
 {
       int i,j;
       char query[] = "select * from Buy";
       execQuery(query);
       printf("=========================================\n");
       printResult();
       printf("=========================================\n");
       printf("%s",query);

       manager_print();
 }

 void manager_slist()
 {
     int num;
     system("clear");

     printf("------------------------------\n");
     printf("       1. 판매내역       \n");
     printf("       2. 판매 자동차 가격 등록         \n");
     printf("       0. 상위메뉴 이동       \n");
     printf("------------------------------\n");
     num = manager_input();
     manager_sel_slist(num);
 }

 void manager_sel_slist(int n)
 {
     int num;
     char *cnum;
     switch(n)
     {
         case 1:
             manager_sInfo();
             break;
         case 2:
             cnum = manager_input1();
             manager_sregister(cnum);
             break;
         default:
             break;
     }
 }

 char *manager_input1()
 {
     char *str1= malloc(sizeof(char) *100);
     char *cnum= malloc(sizeof(char) *100);
     //str1 = malloc(sizeof(char) *100);
     //printf(" 가격을 등록할 차량 번호를 입력하세요! : ");
     scanf("%s",cnum);
     strcpy(str1,cnum);
     return str1;
 }

 void manager_sInfo()
 {
         char query[] = "select * from Sell";

         execQuery(query);
         printf("--------------판매내역----------------\n");
         printResult();
     //  mysql_free_result(res);
         printf("--------------------------------------\n");
         manager_print();

 }
 
  void manager_sregister(char *cnum)
  {
      char query[] = "select * from Automobile";
 
          execQuery(query);
          printf("--------------자동차----------------\n");
          printResult();
          printf("-------------------------------------\n");
 
           char query2[200]="UPDATE Automobile SET a_price='";
           char qu1[100]="'";
           char qu2[100]="';";
           char query3[200]="WHERE a_num='";
 
           char num[100], pri[100];
 
           printf("가격을 등록할 차량 번호를 입력해주세요.\n");
           scanf("%s",num);
           strcat(query3,num);
           strcat(query3,qu2);
           printf("등록할 차량 가격을 입력해주세요.\n");
           scanf("%s",pri);

           strcat(query2,pri);
           strcat(query2,qu1);
           strcat(query2,query3);
           printf("등록이 완료되었습니다.");
 
           printf("%s\n",query2);
           errPrint2(!mysql_real_query(&mysql,query2,strlen(query2)));
           //execQuery(query2);
           //printResult();
           //mysql_free_result(res);
 
           //manager_cartInfo();
    }
  
 
  void manager_cartInfo()
  {
      execQuery(q2);
      printResult();
      mysql_free_result(res);
 
  }
  void manager_cartregister()
  {
      //char cupdate[100];
      //printf("자동차 테이블에 insert하는 쿼리");
      //scanf("%s",cupdate);
      //printf("입력값:%s\n",cupdate);
      //printf("자동차 테이블을 전체를 보여주는 쿼리다시보여줘서 확인\n");

          char query[200]="insert into Automobile values('";
          char qu1[100]="'";
          char qu2[100]=",";
          char qu3[100]="','";
          char qu4[100]="',";
          char qu5[100]=",'";
          char qu6[100]=");";
          char query2[100]="'입고'";
 
 
          char num[100],com[100],mod[100],col[100],leg[100],pri[100];
 
          printf("번호판을 입력해주세요.\n");
          scanf("%s",num);
          strcat(query,num);
          strcat(query,qu3);

          printf("제조사를 입력해주세요.\n");
          scanf("%s",com);
          strcat(query,com);
          strcat(query,qu3);

          printf("모델명을 입력해주세요.\n");
          scanf("%s",mod);
          strcat(query,mod);
          strcat(query,qu3);

          printf("색상을 입력해주세요.\n");
          scanf("%s",col);
          strcat(query,col);
          strcat(query,qu4);

          printf("주행거리를 입력해주세요.(km)\n");
          scanf("%s",leg);
          strcat(query,leg);
          strcat(query,qu2);

          printf("가격을 입력해주세요.\n");
          scanf("%s",pri);
          strcat(query,pri);
          strcat(query,qu2);
          strcat(query,query2);
          strcat(query,qu6);

          printf("차량번호: %s, 제조사: %s, 모델명: %s, 색상: %s, 주행거리: %     s(km) %s원",num,com,mod,col,leg,pri);
  //      printf("%s\n",query);
          errPrint2(!mysql_real_query(&mysql,query,strlen(query)));
 
          manager_print();
 
  }
 void manager_mlist()
  {
      system("clear");
      int num;
 
      printf("------------------------------\n");
      printf("       1. 정비업체       \n");
     printf("       2. 정비금액 등록         \n");
     printf("       0. 상위메뉴 이동       \n");
     printf("------------------------------\n");
     num = manager_input();
     manager_mainten(num);
 }
 
 
 void manager_mainten(int n)
 {
 
     int num;
     switch(n)
     {

         case 1:
             manager_mInfo();
             break;
         case 2:
             manager_maintenregi();
             break;
         case 0:
             manager_print();
         default:
             break;
     }
 }
