
    Student* curr = head;

    while(curr != nullptr) {

        Student* temp = curr;

        curr = curr->next;

        delete temp;
    }

    head = nullptr;
}