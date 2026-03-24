#include <stdio.h>
#include <stdlib.h>

// Định nghĩa node của cây
struct tnode {
    int data;
    struct tnode* left;
    struct tnode* right;
};

// (a) cấp phát node mới
struct tnode* talloc(int data) {
    struct tnode* p = (struct tnode*)malloc(sizeof(struct tnode));
    if (p == NULL) return NULL;

    p->data = data;
    p->left = NULL;
    p->right = NULL;

    return p;
}

// (b) thêm node vào cây (BST)
struct tnode* addnode(struct tnode* root, int data) {
    // nếu cây rỗng → tạo node mới
    if (root == NULL) {
        return talloc(data);
    }

    // nếu nhỏ hơn → sang trái
    if (data < root->data) {
        root->left = addnode(root->left, data);
    }
    // nếu lớn hơn → sang phải
    else {
        root->right = addnode(root->right, data);
    }

    return root;
}

// (c) duyệt preorder (root-left-right)
void preorder(struct tnode* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// (d) duyệt inorder (left-root-right) → ra sorted
void inorder(struct tnode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// (e) xóa toàn bộ cây (post-order)
int deltree(struct tnode* root) {
    if (root == NULL) return 0;

    int count = 0;

    // xóa trái và phải trước
    count += deltree(root->left);
    count += deltree(root->right);

    free(root); // xóa node hiện tại
    return count + 1;
}

// (f) test
int main() {
    struct tnode* root = NULL;

    // thêm theo đề: 3,1,0,2,8,6,5,9
    int arr[] = {3,1,0,2,8,6,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        root = addnode(root, arr[i]);
    }

    printf("Preorder: ");
    preorder(root);
    printf("\n");

    printf("Inorder (sorted): ");
    inorder(root);
    printf("\n");

    int deleted = deltree(root);
    printf("Deleted nodes: %d\n", deleted);

    return 0;
}
