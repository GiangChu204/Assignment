#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 101   // số bucket của bảng băm

// Node của danh sách liên kết
typedef struct node {
    char *w;              // từ (string)
    int c;                // số lần xuất hiện
    struct node *next;    // con trỏ tới node tiếp theo
} Node;

// Bảng băm: mỗi phần tử là đầu của 1 linked list
Node *t[N] = {0};

// Hàm băm: chuyển chuỗi thành chỉ số [0..N-1]
unsigned hash(char *s) {
    unsigned h = 0;
    while (*s)                 // duyệt từng ký tự
        h = *s++ + 31*h;       // công thức hash
    return h % N;              // đưa về phạm vi mảng
}

// lookup: tìm từ hoặc tạo mới nếu chưa có
Node *lookup(char *s, int create) {
    unsigned h = hash(s);   // tính vị trí trong bảng băm
    Node *p = t[h];         // lấy danh sách tại bucket đó

    // duyệt linked list để tìm
    for (; p; p = p->next)
        if (strcmp(p->w, s) == 0)   // nếu trùng từ
            return p;               // trả về node

    // không tìm thấy
    if (!create) return NULL;

    // tạo node mới
    p = malloc(sizeof(Node));   // cấp phát bộ nhớ
    p->w = strdup(s);           // copy chuỗi
    p->c = 0;                   // số lần ban đầu = 0

    // chèn vào đầu danh sách
    p->next = t[h];
    t[h] = p;

    return p;
}

// giải phóng toàn bộ bảng băm
void cleartable() {
    for (int i = 0; i < N; i++) {   // duyệt từng bucket
        Node *p = t[i];

        while (p) {                 // duyệt linked list
            Node *tmp = p;
            p = p->next;
            free(tmp->w);           // giải phóng chuỗi
            free(tmp);              // giải phóng node
        }

        t[i] = NULL;                // reset lại bucket
    }
}

int main() {
    char w[100];                       // buffer lưu từ đọc vào
    FILE *f = fopen("book.txt", "r");  // mở file

    if (!f) {                          // kiểm tra lỗi
        printf("Loi mo file\n");
        return 1;
    }

    // đọc từng từ trong file
    while (fscanf(f, "%s", w) != EOF) {
        Node *p = lookup(w, 1);  // tìm hoặc tạo từ
        p->c++;                  // tăng số lần xuất hiện
    }

    fclose(f);  // đóng file

    // in kết quả
    for (int i = 0; i < N; i++) {
        Node *p = t[i];
        while (p) {
            printf("%s: %d\n", p->w, p->c);
            p = p->next;
        }
    }

    cleartable();   // giải phóng bộ nhớ
    return 0;
}
