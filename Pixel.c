#include <stdio.h>
#include <stdlib.h>

#define BIT 8
#define CH '0'
#define SIZE 2
#define ROW 16
#define COL 16

enum color
{
    bln,
    red,
    grn,
    ylw,
    blu,
    ppl,
    cyn,
    wit,
    blk
};


struct Pixel {
    int data;
    struct Pixel *next;
};

// Function to create a new pixel node
struct Pixel* createNode(int data) {
    struct Pixel* newNode = malloc(sizeof(struct Pixel));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push a new pixel node to the end of the list
void push(struct Pixel** head, int data) {
    struct Pixel* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Pixel* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print colored output based on data
void color(int no) {
    switch (no) {
    case 0:
        printf("\e[0m  ");
        break;
    case 1:
        printf("\e[31m%c%c", CH, CH);
        break;
    case 2:
        printf("\e[32m%c%c", CH, CH);
        break;
    case 3:
        printf("\e[33m%c%c", CH, CH);
        break;
    case 4:
        printf("\e[34m%c%c", CH, CH);
        break;
    case 5:
        printf("\e[35m%c%c", CH, CH);
        break;
    case 6:
        printf("\e[36m%c%c", CH, CH);
        break;
    case 7:
        printf("\e[37m%c%c", CH, CH);
        break;
    case 8:
        printf("\e[30m%c%c", CH, CH);
        break;
    default:
        break;
    }
}

// Function to print the linked list of pixels
void printPixels(struct Pixel *head) {
    struct Pixel *ptr = head;
    while (ptr != NULL) {
        for (int j = 0; j < SIZE; j++) {
            color(ptr->data);
        }
        ptr = ptr->next;
    }
}

// Function to free the linked list
void freePixels(struct Pixel *head) {
    struct Pixel *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int main()
{
    struct Pixel *pix[ROW];
    for (int i = 0; i < ROW; i++)
    {
        pix[i] = NULL;
    }
    printf("|done|\n");

    int arr[ROW][COL] = {{bln, bln, bln, bln, bln, red, red, red, red, red, bln, bln, bln, bln, bln, bln},
        {bln, bln, bln, bln, red, red, red, red, red, red, red, red, red, bln, bln, bln},
        {bln, bln, bln, bln, ppl, ppl, ppl, ylw, ylw, blk, ylw, bln, bln, bln, bln, bln},
        {bln, bln, bln, ppl, ylw, ppl, ylw, ylw, ylw, blk, ylw, ylw, ylw, bln, bln, bln},
        {bln, bln, bln, ppl, ylw, ppl, ppl, ylw, ylw, ylw, blk, ylw, ylw, ylw, bln, bln},
        {bln, bln, bln, bln, ppl, ylw, ylw, ylw, ylw, blk, blk, blk, blk, bln, bln, bln},
        {bln, bln, bln, bln, bln, ylw, ylw, ylw, ylw, ylw, ylw, ylw, bln, bln, bln, bln},
        {bln, bln, bln, bln, red, red, blu, red, red, red, blu, bln, bln, bln, bln, bln},
        {bln, bln, bln, red, red, red, blu, red, red, blu, red, red, red, bln, bln, bln},
        {bln, bln, red, red, red, red, blu, red, red, blu, red, red, red, red, bln, bln},
        {bln, bln, ylw, ylw, red, red, blu, blu, blu, blu, red, red, ylw, ylw, bln, bln},
        {bln, bln, ylw, ylw, ylw, blu, ylw, blu, blu, ylw, blu, ylw, ylw, ylw, bln, bln},
        {bln, bln, bln, bln, blu, blu, blu, blu, blu, blu, blu, blu, bln, bln, bln, bln},
        {bln, bln, bln, bln, blu, blu, blu, bln, bln, blu, blu, blu, bln, bln, bln, bln},
        {bln, bln, bln, ppl, ppl, ppl, bln, bln, bln, bln, ppl, ppl, ppl, bln, bln, bln},
        {bln, bln, ppl, ppl, ppl, ppl, bln, bln, bln, bln, ppl, ppl, ppl, ppl, bln, bln}
    };

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
            push(&pix[i],arr[i][j]);
    }

    printf("\n\n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j=0; j<SIZE; j++) {
            printPixels(pix[i]);
            printf("\n");
        }
    }


    for (int i = 0; i < ROW; i++)
        freePixels(pix[i]);

    printf("\n\n");
    printf("\e[41m  \e[42m  \e[43m  \e[44m  \e[45m  \e[46m  \e[47m  ");
    return 0;
}
