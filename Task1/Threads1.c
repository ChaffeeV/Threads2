#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

void *print_hello(void *num)
{
	long t_num;
	t_num = (long) num;
	int i = 0;
	for (i=0; i<10;i++){
	printf("Номер потока: %ld\n", t_num);
	printf ("Идентификатор потока: %u\n\n", pthread_self());
	sleep(1);
	}
}

int main()
{
	pthread_t threads[NUM_THREADS];
	pthread_t abc;
	int rc;
	long t;

	for (t = 0; t < NUM_THREADS; t++) {
		printf ("Создан поток #%ld\n\n", t);
		rc = pthread_create (&threads[t], NULL, print_hello, (void *)t);
		if (rc) {
			printf ("ERROR; return code from pthread_create() is %d\n", rc);
			exit (-1);
 		}
 	}
	for(t = 0; t < NUM_THREADS; t++) {
		pthread_join(threads[t], NULL);
		printf("Поток #%ld завершен\n", t);
	}
 	return 0;
}
