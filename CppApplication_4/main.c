/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: arjun
 *
 * Created on February 13, 2024, 6:49 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>


void * count(void *);
int globalNumber = 0;
//Create a mutex
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int main(void) {
    int i,j;
    pthread_t counterThread[5];


    //Create the 5 threads
    for(i=0; i < 5; i++)
   {
      pthread_create( &counterThread[i], NULL, count, NULL );
   }
    
    //Wait for all treads to finish
    
    for(j=0; j < 5; j++)
   {
      pthread_join( counterThread[j], NULL); 
   }
    
    printf("Global number: %d\n",  globalNumber);
    return (0);
}

void * count(void * junk) {
    int loopCount = 0;
    pthread_mutex_lock(&mutex1);
    while (loopCount < 10) {
        int tmpNumber = globalNumber;
        printf("counter: %d, Thread: %ld, PID: %d\n",  tmpNumber, pthread_self(), getpid());
        tmpNumber++;
        usleep(random() % 2);
        globalNumber = tmpNumber;
        loopCount++;
    }
    pthread_mutex_unlock(&mutex1);
    return (0);
}



