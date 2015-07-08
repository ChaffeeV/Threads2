#include <stdio.h>
#include <pthread.h>


int k=0;
void *change(void *num)
{
	long t_num;
	t_num = (long) num;
	int i=0;
	sleep(1);
	for(i=0; i<10; i++){
	printf("Номер потока: %ld\n", t_num);
	k = k+2*(i+1);
	printf("Поток %ld совершил увеличение переменной на %d\n\n", t_num, 2*(i+1));
	sleep(2);
	}
}
void *show(void *num)
{
	int i = 0;
	long t_num;
	t_num = (long) num;
	for(i=0; i<11; i++){ 
	printf("Номер потока: %ld\n", t_num);
	printf("Поток %ld выводит значение переменной: %d\n\n", t_num, k);
	sleep(2);
	}
}	

int main()
{
	pthread_t threads[2];
	int rc;
	long t;
	t=0;
	rc = pthread_create (&threads[t], NULL, change, (void *)t);
	if (rc) {
		printf ("ERROR; return code from pthread_create() is %d\n", rc);
		exit (-1);
 	}
	t = 1;
	rc = pthread_create (&threads[t], NULL, show, (void *)t);
	if (rc) {
		printf ("ERROR; return code from pthread_create() is %d\n", rc);
		exit (-1);
 	}
	for(t = 0; t < 2; t++) {
		pthread_join(threads[t], NULL);
		printf("Поток %ld завершен\n", t);
	}
 	return 0;
}
