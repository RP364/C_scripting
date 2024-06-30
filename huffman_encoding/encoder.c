#include<stdlib.h>
#include<stdio.h>


struct node {

    char data;

    struct node *next;

};


struct huffman_node {

    char data;

    unsigned frequency;

    struct huffman_node *left, *right;

};

struct huffman_heap
{
    
    unsigned size;
    
    unsigned capacity;
    
    struct huffman_node** array;

};

struct huffman_node* newNode(char data, unsigned freq)
{
    struct huffman_node *node_pointer = malloc(sizeof(struct huffman_node));

    node_pointer->left = NULL;
    node_pointer->right = NULL;
    node_pointer->data = data;
    node_pointer->frequency = freq;
};

struct huffman_heap* newHeap(unsigned size, unsigned capacity)
{
    struct huffman_heap *heap_pointer = malloc(sizeof(struct huffman_heap));

    heap_pointer -> size = 0;
    heap_pointer -> capacity = capacity;

    heap_pointer -> array = malloc(heap_pointer->capacity * sizeof(struct huffman_node*));

    return heap_pointer;

};


// void* compress(FILE * filestream){

// };

int main()
{

    printf("Allocating Hashmap\n\n");

    int*** hash_map = newHashMap();
    

    printf("These are the contents of the input file huffman_test.txt:\n\n");

    FILE * file_pointer = fopen("huffman_test.txt", "r");
    char ch = fgetc(file_pointer);
    struct node* key = malloc(sizeof(struct node*));
    struct node* key_init = key;
    int keys_length = 0;

    while (ch != EOF) {
        printf("Character %c\n", ch);
        
        int* ptr = getValue(hash_map, ch);
        if (ptr == NULL){
            assignValue(hash_map, ch, 1);
            key->data=ch;
            key->next = malloc(sizeof(struct node));
            key = key->next;
            keys_length++;
        }
        else{
            int value = *ptr + 1;
            assignValue(hash_map, ch, value);
        }
        ch = fgetc(file_pointer);
    }
    printf("\n\n");

    fseek(file_pointer, 0, SEEK_SET);

    // compress(file_pointer);

    printf("Printing List of Frequencies\n\n");

    int frequencies[keys_length];
    char characters[keys_length];

    key = key_init;
    struct node* prev_key = key;

    for (int i = 0; i < keys_length; i++){
        frequencies[i] = *getValue(hash_map, key->data);
        characters[i] = key->data;
        printf("Character: %c\nFrequency: %d\n\n", key->data, frequencies[i]);
        
        prev_key = key;
        key = key->next;
        free(prev_key);
        
    }

    int tmp;
    char tmp_c;

    for (int i = 0; i < keys_length; i++){
        sort_characters(&frequencies[0], &characters[0], 0, keys_length-i);
        tmp = frequencies[0];
        frequencies[0] = frequencies[keys_length-i-1];
        frequencies[keys_length-i-1] = tmp;

        tmp_c = characters[0];
        characters[0] = characters[keys_length-i-1];
        characters[keys_length-i-1] = tmp_c;

    }

    // for (int i = 0; i < keys_length; i++){

    //     assignValue(hash_map, char)

    // }

    compress();

}
