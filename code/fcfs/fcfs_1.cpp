#include <iostream>
using namespace std;
#include<iostream>
#include<list>
using namespace std;

int main(){
    int inp, pn, wtt, arr ,burst, bt[100], at[100], wt[100];
    int sum=0, avr=0;
    double tt[100];
    cout<<"Enter the precess number: ";
    //프로세스의 갯수를 입력받는다.
    cin>>pn;

    cout<<"Enter the burst time of each process: ";
    //각 프로세스별 버스트 타임을 입력받는다.
    for(int i=0;i<pn;i++){
        cin >> bt[i];
    }
    burst=0;
    //후의 대기시간 계산시 이용하기위한 변수생성

    cout<<"Enter the arrive time of each process(first one is fixed to 0):";
    //각 프로세스별 도착시간을 입력받는다.
    for(int i=0;i<pn;i++){
        cin>>arr;
        if(pn>0){
            //첫번째 입력값을 제외한 다른 프로세스의 도착시간.
            at[i]=at[i-1]+arr;
            //비선점이므로 이전의 도착값에 다음의 입력값을 더해 우선순위의 순서를 고정합니다.
        }
        else{
            //초기 대기시간은 0으로 고정합니다.
            at[i]=0;
        }

        if(i>0){
            burst+=bt[i-1];   
            wtt=burst-arr;
            wt[i]=abs(wtt);
            //대기시간은 '이전 버스트가 끝나는 시간-도착시간'이다.
        }
        else
            wt[0]=0;
    }

    for(int i=0;i<pn;i++){
        tt[i]=bt[i]+wt[i];
      //fcfs의 turnaround time은 '버스트시간+대기시간'이다.
    }


    bool run = true;
    while (run){ 

        cout<<"====select the menu===="<<endl;
        cout<<"1. check the bursttime"<<endl;
        cout<<"2. check the arrive time"<<endl;
        cout<<"3. print the waiting time "<<endl;
        cout<<"4. print the turnaround time"<<endl;
        cout<<"5. print the average waiting time"<<endl;
        cout<<"6. exit"<<endl;

        cin>>inp;
        switch(inp){
            case 1:
                cout<<"----1. BURST TIME----"<<endl;
                for(int i=0; i<pn;i++){
                    cout<<"p["<<i+1<<"]="<<bt[i]<<endl;                
                }
                cout<<"----return to menu----"<<endl;
            break;

            case 2:
                cout<<"----2. ARRIVE TIME----"<<endl;
                for(int i=0;i<pn;i++){
                    cout<<"p["<<i+1<<"]="<<at[i]<<endl;
                } 
                cout<<"----return to menu----"<<endl;
            break;

            case 3:
                cout<<"----3. WAITING TIME----"<<endl;
                for(int i=0;i<pn;i++){
                    cout<<"p["<<i+1<<"]="<<wt[i]<<endl;
                } 
                cout<<"----return to menu----"<<endl;
            break;

            case 4:
                cout<<"----4.TURNAROUND TIME----"<<endl;
                for(int i=0;i<pn;i++){
                    cout<<"p["<<i+1<<"]="<<tt[i]<<endl;
                } 
                cout<<"----return to menu----"<<endl;
            break;

          case 5:
              cout<<"----5.AVERAGE WAITING TIME----"<<endl;
              for(int i=0;i<pn;i++){
                  sum+=wt[i];
              }
              avr=sum/pn;
              //평균 대기시간은 모든 대기시간을 합쳐서 프로세스의 나눈 정수값만을 도출
              cout<<"average of waiting time: "<<avr<<endl;
          break;

          case 6:
                cout<<"----6. EXIT----"<<endl;
                run = false;
                cout<<"----EXIT----"<<endl;
          break;
        }
    }
}