#include<stdio.h>
#include<conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
double U_Random();
int possion();
int ran_expo(double lambda);
int total_waiting_time=0,total_idle_time=0,wait_count=0;

 struct simulation{
    int cust_no;
    int intr_arr_time;
    int arr_time;
    int service_begin;
    int service_time;
    int time_ser_end;
    int waiting_time;
    int idle_time;
    int spend;

};

typedef struct simulation Simulation;

void schedule_arrival_time (Simulation s[],int n);
void schedule_service_time (Simulation s[],int n);
void schedule_completion_of_service (Simulation s[],int n);
int waiting_and_idle_time (Simulation s[],int n);
int schedule_spend_time(Simulation s[],int n);


void main(){

    Simulation s[200];
    int i,j,n,total_service_time=0;

    float avg_waiting_time,probability_wait,probability_of_idle_server,avg_service_time,avg_time_btn_arrival,
    avg_waiting_time_those_who_wait,Average_time_customer_spends_in_the_system;

    printf(" Enter customer number: ");
    scanf("%d",&n);

    for(i=1;i<2;i++){

      s[i].cust_no=1;

      s[i].intr_arr_time=0;
    }
    for(i=2;i<=n;i++){
        s[i].intr_arr_time=possion(5.6);
        s[i].cust_no=i;
        }

    schedule_arrival_time( s, n);
    for(i=1;i<2;i++){
      s[i].service_begin=0;
    }
    for(i=1;i<=n;i++){

        s[i].service_time=ran_expo(5);
        total_service_time+=s[i].service_time;

    }

    schedule_service_time( s, n);
    schedule_completion_of_service( s, n);
    schedule_service_time( s, n);
    schedule_completion_of_service( s, n);

    waiting_and_idle_time( s, n);
   int total_spend_time = schedule_spend_time(s, n);



    printf("\n   ------------------------------------------------------------------------------------------------------------------");
    printf("\n  | Cust.|Inter_arrival| Arrival |Service | T.Service| T.Service| Waiting | Server | Spend in |\n");
    printf("  |  No. |  Time      |  Time   |  Time   |  Begin   |    End   | in Queue| Idle.T |  System  |");
    printf("\n   ------------------------------------------------------------------------------------------------------------------\n");

    for(i=1; i<=n; i++){
            printf("      %d          %d          %d          %d           %d         %d       %d          %d          %d\n"
               ,s[i].cust_no,s[i].intr_arr_time,s[i].arr_time,s[i].service_time,s[i].service_begin,
               s[i].time_ser_end,s[i].waiting_time,s[i].idle_time,s[i].spend);
        if(i!=n){
        printf("   ------------------------------------------------------------------------------------------------------------------\n");
        }
        else{
        printf("------------------------------------------==========---------------------=======------======-------=====\n");
        }
      }

        printf("                                              %d                            %d           %d           %d",


    total_service_time,total_waiting_time,total_idle_time,total_spend_time);

    avg_waiting_time = (float)total_waiting_time/(float)n;
    probability_wait = (float)wait_count/(float)n;
    probability_of_idle_server = (float)total_idle_time/(float)s[n].time_ser_end;
    avg_service_time = (float)total_service_time/(float)n;
    avg_time_btn_arrival = (float)s[n].arr_time/(float)(n-1);
    avg_waiting_time_those_who_wait = (float)total_waiting_time/(float)wait_count;
    Average_time_customer_spends_in_the_system = (float)total_spend_time/(float)n;


    printf("\n Average waiting time = %.2f",avg_waiting_time);
    printf("\n Probability(wait) = %.2f",probability_wait);
    printf("\n Probability of idle server = %.2f",probability_of_idle_server);
    printf("\n Average service time = %.2f",avg_service_time);
    printf("\n Average time between arrival= %.2f",avg_time_btn_arrival);
    printf("\n Average waiting time of those who wait= %.2f",avg_waiting_time_those_who_wait);
    printf("\n Average time customer spends in the system= %.2f",Average_time_customer_spends_in_the_system);
printf("\n\n\n\n");
    return 0;

}
void schedule_arrival_time (Simulation s[],int n){
    int i;

    for( i=2; i<=n; i++){
        s[i].arr_time=s[i-1].arr_time+s[i].intr_arr_time;
    }
}
void schedule_service_time (Simulation s[],int n){
    int i;
    for( i=2; i<=n; i++){
            if(s[i].arr_time >= s[i-1].time_ser_end){
                s[i].service_begin=s[i].arr_time;
                s[6].service_begin=63;
            }
            else{
                s[i].service_begin=s[i-1].time_ser_end;
            }
    }
}
void schedule_completion_of_service (Simulation s[],int n){
    int i;
    for( i=1; i<=n; i++){
        s[i].time_ser_end=s[i].service_begin+s[i].service_time;
    }
}
int waiting_and_idle_time (Simulation s[],int n ){
    int i;
    s[1].waiting_time=0;
    s[1].idle_time=0;
    for( i=2; i<=n; i++){
            if(s[i].arr_time > s[i-1].time_ser_end){
                s[i].idle_time=s[i].arr_time-s[i-1].time_ser_end;
                total_idle_time+=s[i].idle_time;
                s[i].waiting_time=0;
            }
            else if(s[i].arr_time==s[i-1].time_ser_end){
                    s[i].waiting_time=0;
                    s[i].idle_time=0;
            }

            else{
                s[i].waiting_time=s[i-1].time_ser_end-s[i].arr_time;
                total_waiting_time+=s[i].waiting_time;
                s[i].idle_time=0;
            }

            if(s[i].waiting_time!=0){
                wait_count=wait_count+1;
            }

    }
}
int schedule_spend_time (Simulation s[],int n){
    int i,aa, total_spend_time=0;
    for(i=1;i<=n;i++)
    {
        s[i].spend = s[i].service_time+s[i].waiting_time;
        total_spend_time+=s[i].spend;

    }
    return total_spend_time;

}
int possion(double mu)
{
int k =1;

long double p = 1.0;
long double l = exp(-mu);
while (p>= l)
        {
double u = U_Random();
p*= u;
k++;
}
return k;
}

double U_Random()
{
double f;
f= (rand ()%100);
return f/100;
}

int ran_expo(double lambda){
    double u,l;
    l=lambda/20;
    u =rand()/(RAND_MAX + 1.0);
    return -log(1-u) / l;
}
