/* 스택을 함수의 매개 변수로 전달 */

#include <stdio.h>
#include <stdlib.h>

// ***** 스택 코드의 시작
#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

//스택 초기화 함수
void init_stack(StackType* s) {
    s->top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType* s) {
    return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE -1));
}

//삽입함수
void push(StackType* s, element item) {
    if (is_full(s)) {
        fprintf (stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

//삭제함수
element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf (stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

//피크함수
element peek(StackType* s) {
    if (is_empty(s)) {
        fprintf (stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)];
}
// ***** 스택 코드의 끝

int main(void) {
    StackType s;    //스택을 정적으로 생성

    init_stack(&s); //스택의 주소를 함수한테 전달
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    return 0;
}