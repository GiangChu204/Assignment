#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc node
struct node {
    int data;              // dữ liệu
    struct node* next;     // con trỏ tới node tiếp theo
};

// (a) Hiển thị danh sách
void display(struct node* head) {
    struct node* p = head;         // bắt đầu từ head

    while (p != NULL) {            // duyệt đến cuối danh sách
        printf("%d -> ", p->data); // in dữ liệu
        p = p->next;               // sang node tiếp theo
    }
    printf("NULL\n");              // kết thúc danh sách
}

// (b) Thêm node vào cuối danh sách
struct node* addback(struct node* head, int data) {
    // cấp phát bộ nhớ cho node mới
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) return head;  // nếu cấp phát lỗi

    newnode->data = data;  // gán dữ liệu
    newnode->next = NULL;  // node cuối trỏ NULL

    // nếu danh sách rỗng
    if (head == NULL) return newnode;

    // duyệt đến node cuối
    struct node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    p->next = newnode; // nối node mới vào cuối

    return head;       // trả về head (không đổi)
}

// (c) Tìm node có giá trị data
struct node* find(struct node* head, int data) {
    struct node* p = head;

    while (p != NULL) {
        if (p->data == data)  // nếu tìm thấy
            return p;
        p = p->next;
    }

    return NULL; // không tìm thấy
}

// (d) Xóa node
struct node* delnode(struct node* head, struct node* pelement) {
    // nếu list rỗng hoặc node cần xóa NULL
    if (head == NULL || pelement == NULL) return head;

    // nếu xóa node đầu
    if (head == pelement) {
        struct node* temp = head;
        head = head->next; // cập nhật head
        free(temp);        // giải phóng bộ nhớ
        return head;
    }

    // tìm node đứng trước node cần xóa
    struct node* p = head;
    while (p->next != NULL && p->next != pelement) {
        p = p->next;
    }

    // nếu tìm thấy
    if (p->next == pelement) {
        p->next = pelement->next; // bỏ qua node cần xóa
        free(pelement);           // giải phóng
    }

    return head;
}

// (e) Giải phóng toàn bộ danh sách
void freelist(struct node* head) {
    struct node* p = head;

    while (p != NULL) {
        struct node* temp = p;
        p = p->next;
        free(temp);  // free từng node
    }
}

// (f) Hàm main để test
int main() {
    struct node* head = NULL;  // danh sách ban đầu rỗng

    // thêm phần tử
    head = addback(head, 10);
    head = addback(head, 20);
    head = addback(head, 30);
    head = addback(head, 40);

    printf("List: ");
    display(head);

    // tìm phần tử
    struct node* f = find(head, 20);
    if (f != NULL)
        printf("Found: %d\n", f->data);
    else
        printf("Not found\n");

    // xóa phần tử
    head = delnode(head, f);

    printf("After delete 20: ");
    display(head);

    // giải phóng bộ nhớ
    freelist(head);

    return 0;
}
