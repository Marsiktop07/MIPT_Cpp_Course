struct subvector {
     int *mas;
     unsigned int top;
     unsigned int capacity;
};

bool init(subvector *qv);
bool push_back(subvector *qv, int d);
int pop_back(subvector *qv);
bool resize(subvector *qv, unsigned int new_capacity);
void shrink_to_fit(subvector *qv);
void clear(subvector *qv);
void destructor(subvector *qv);

bool init(subvector *qv) {
    qv->mas = nullptr;
    qv->top = 0;
    qv->capacity = 0;
    return true;
}

bool push_back(subvector *qv, int d) {
    if (qv->top == qv->capacity) {
        unsigned int new_capacity = qv->capacity * 2;
        if (new_capacity == 0) {
            new_capacity = 1;
        }
        resize(qv, new_capacity);
    }
    qv->mas[qv->top] = d;
    qv->top++;
    return true;
}

int pop_back(subvector *qv) {
    if (qv->top == 0) {
        return 0;
    }
    qv->top--;
    return qv->mas[qv->top];
}

bool resize(subvector *qv, unsigned int new_capacity) {
    if (new_capacity == 0) {
        destructor(qv);
        return true;
    }
    int *new_mas = new int[new_capacity];
    unsigned int k;
    if (new_capacity < qv->top) {
        k = new_capacity;
    }
    else {
        k = qv->top;
    }
    if (qv->mas != nullptr) {
        for (unsigned int i = 0; i < k; i++) {
            new_mas[i] = qv->mas[i];
        }
        delete[] qv->mas;
    }
    qv->mas = new_mas;
    qv->capacity = new_capacity;
    qv->top = k;
    return true;
}

void shrink_to_fit(subvector *qv) {
    resize(qv, qv->top);
}

void clear(subvector *qv) {
    qv->top = 0;
}

void destructor(subvector *qv) {
    delete[] qv->mas;
    init(qv);
}