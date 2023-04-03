/**
 * C패밀리 경쟁상태 문제 해결을 위한 mutex
 * mutex를 사용하여 전역변수에 대한 접근을 동시에 여러 쓰레드가 접근하지 못하게 동기화 한다.
 * 만약 공유 메모리 sum에 여러 쓰레드가 동시에 접근한다면 동기화 문제가 생긴다.
 * ex) sum+=1 -> 한줄로 보이지만 어셈블리로 본다면 3줄이다.
 * int t=sum //sum is global
 * t=t+1
 * sum=1
 * 만약 중간에 컨텍스트 변경이 일어난다면 해당 스냅샷이 공유메모리를 덮어 씌어서 문제가 생긴다.
 * 밑 코드는 mutex를 이용하여 10개 쓰레드와 공유 메모리를 동기화 해본 코드이다.
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ll long long

typedef struct {
    int from;
    int to;
} Point;        //포인트 구조체

void *calcThread(void *param);

ll sum = 0;
static __thread ll tsum = 0ll;  //로컬 스토리지
pthread_mutex_t sum_mutex = PTHREAD_MUTEX_INITIALIZER; // 뮤텍스 초기화

int main()
{
        pthread_t tid[10];
        pthread_attr_t attr;

        pthread_attr_init(&attr);
        for(int i=0;i<10;i++){
                Point* point = (Point*)malloc(sizeof(Point)); //1 ~ 100,000
                point->from = i*10000+1;   
                point->to = 10000*(i+1);
                pthread_create(&tid[i], &attr, calcThread, (void*)point);   //from ~ to 까지 합
        }

        for(int i=0;i<10;i++)    
                pthread_join(tid[i], NULL);

        printf("sum = %lld\n", sum);
        //테스트이므로 Point free는 생략
}

void *calcThread(void *param)
{
        printf("calcThread execute.....\n");

        Point* p = (Point*)param;

        int i;

        for (i = p->from; i <= p->to; i++)
                tsum += i;      //로컬 스토리지이므로 동기화하지 않음

        pthread_mutex_lock(&sum_mutex); //mutex lock
        sum+=tsum;      //sum은 전역변수이기 때문에 동기화 시킨다.
        pthread_mutex_unlock(&sum_mutex); //mutex unlock
}
