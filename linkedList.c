



/*adding the typeR node to the linked list*/
void addNode(TypeR* newNode, TypeR** head) {
	TypeR* temp = *head;
	while (temp->next)
		temp = temp->next;
		temp->next = newNode;
		newNode->next = NULL;
		return;
}

/*adding the typeI node to the linked list*/
void addNode(TypeI* newNode, TypeI** head) {
	TypeI* temp = *head;
	while (temp->next)
		temp = temp->next;
		temp->next = newNode;
		newNode->next = NULL;
		return;
}



/*adding the typeI node to the linked list*/
void addNode(TypeJ* newNode, TypeJ** head) {
	TypeJ* temp = *head;
	while (temp->next)
		temp = temp->next;
		temp->next = newNode;
		newNode->next = NULL;
		return;
}

/*looking for value in symbol list*/
int searchSymbolValue(symboList **head,char value[70])
{
	symboList* temp;
	if((*head)==NULL)
	{
	    printf(stderr, "\nERROR - The list is empty\n");
	}
	else
	{
	    temp = (*head);
	    while(temp!=NULL)
	    {
	        if(strcpy(temp->symbolName, last_tok) == 0)
	        {
	            return 1;
	        }
	    }
	    return 0;
	}
}

/*Adds a new TypeR node to the list*/
void addNode(TypeR* newNode, TypeR** head) {
	TypeR* temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = newNode;
	newNode->next = NULL;
	return;
}

/*Adds a new TypeI node to the list*/
void addNode(TypeI* newNode, TypeI** head) {
	TypeI* temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = newNode;
	newNode->next = NULL;
	return;
}

/*Adds a new TypeJ node to the list*/
void addNode(TypeJ* newNode, TypeJ** head) {
	TypeJ* temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = newNode;
	newNode->next = NULL;
	return;
}


