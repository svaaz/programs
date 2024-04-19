typedef struct {
    // User defined data may be declared here.
   pthread_mutex_t lock1;
   pthread_cond_t cond1;
   pthread_cond_t cond2;
   
   int count;
} Foo;

Foo* fooCreate() {
    Foo* obj = (Foo*) malloc(sizeof(Foo));
    obj->count = 1;
    pthread_mutex_init (&obj->lock1, NULL); 
    // Initialize user defined data here.
    pthread_cond_init(&obj->cond1, NULL);
    pthread_cond_init(&obj->cond2, NULL);
    return obj;
}

void first(Foo* obj) {
     pthread_mutex_lock(&obj->lock1);
    // printFirst() outputs "first". Do not change or remove this line.
    printFirst();
    obj->count ++;
    pthread_cond_signal(&obj->cond1);
     pthread_mutex_unlock(&obj->lock1);
}

void second(Foo* obj) {
     pthread_mutex_lock(&obj->lock1);
    // printSecond() outputs "second". Do not change or remove this line.
     while(obj->count !=2)
            pthread_cond_wait(&obj->cond1, &obj->lock1);
    printSecond();
    obj->count ++;
    pthread_cond_signal(&obj->cond2);
    pthread_mutex_unlock(&obj->lock1);
}

void third(Foo* obj) {
     pthread_mutex_lock(&obj->lock1);
    // printThird() outputs "third". Do not change or remove this line.
     while(obj->count !=3)
            pthread_cond_wait(&obj->cond2, &obj->lock1);
    printThird();
    /*obj->count =1;*/
    //pthread_cond_signal(&obj->cond1);
    pthread_mutex_unlock(&obj->lock1);
}

void fooFree(Foo* obj) {
    // User defined data may be cleaned up here.
    free(obj);
}
