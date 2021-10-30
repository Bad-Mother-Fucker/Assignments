


#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    int val;
    struct s_listnode* next;
} listnode;
#endif


listnode* remove_nth_node_from_end_of_list(listnode* param_1, int param_2)
{
    // To store length of the linked list
    int len = 0;
    listnode tmp = param_1;
    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }


    if (param_2 > len)
    {
        printf("Can't remove %dth element, list is smaller", param_2);
        return head;
    }

        // We need to remove head node
    else if (param_2 == len) {

        // Return head->next
        return param_1->next;

    }
    else
    {
        // Remove len - B th node from starting
        int diff = len - param_2;
        listnode * prev= NULL;
        listnode * curr = param_1;
        for(int i = 0;i < diff;i++){
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        return param_1;
    }
}


