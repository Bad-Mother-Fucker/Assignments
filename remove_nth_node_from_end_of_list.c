listnode* remove_nth_node_from_end_of_list(listnode* param_1, int param_2) {


        Node *temp;


        Node *first = param_1;


        Node *second = param_1;
        for (int i = 0; i < param_2; i++)
        {

            if (second->next == NULL)
            {

                // If count = N i.e.
                // delete the head node
                if (i == param_2 - 1){
                    temp = param_1;
                    head = param_1->next;
                    free (temp);
                }
                return head;
            }
            second = second->next;
        }

        // Increment both the pointers by one until
        // second pointer reaches the end
        while (second->next != NULL)
        {
            first = first->next;
            second = second->next;
        }

        // First must be pointing to the
        // Nth node from the end by now
        // So, delete the node first is pointing to
        temp = first->next;
        first->next = first->next->next;
        free (temp);
        return head;
    }
}
