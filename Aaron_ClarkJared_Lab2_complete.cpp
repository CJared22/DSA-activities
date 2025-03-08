#include <iostream>

using namespace std;

typedef struct Node{
    string songName;
    Node  *link;
}Node;

Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data;
    newNode->link = NULL;

    return newNode;
}

void traverse(Node *head){
    Node *temp = new Node;
    temp = head;
    
    cout << "My Playlist" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }
        
        temp = temp->link;
    }
}

Node *insertAtEnd(string data, Node *head){
    if(head == NULL){
        Node *newNode = createNode(data);
        head = newNode;
        cout << "A new node has been inserted at the end \n" << endl;
        return head;
    }
    Node *temp = new Node;
    temp = head;
    
    while(temp->link != NULL){
        temp = temp->link;
    }
    
    Node *newNode = createNode(data);
    temp->link = newNode;
    
    cout << "A new node has been inserted at the end \n" << endl;
    return head;
}

Node *insertAtBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;
    
    head = newNode;
    
    cout << "A new node has been inserted at the beginning \n" <<endl;
    
    return head;
}

string insertAfter(string after, string data, Node *head){
    Node *temp = new Node;
    temp = head;
    
    while(temp->songName.compare(after) != 0){
        if(temp == NULL){
            return "No such exist, please try again later.";
        }
        
        temp = temp->link;
    }
    Node *newNode = createNode(data);
    newNode->link = temp->link;
    temp->link = newNode;
    
    return "An new node has been inserted after " + after + "\n";
}

int main(){
    Node *head = createNode("Multo by Cup of Joe");
    
    head = insertAtEnd("Sino by Unique Salonga", head);
    head = insertAtEnd("Isip by Healy After Dark", head);
    head = insertAtEnd("Mirrors by Justin Timberlake", head);
    head = insertAtEnd("Blue by yung kai", head);
    
    head = insertAtBeginning("Let Me Go by Daniel Caesar", head);
    head = insertAtBeginning("Ikaw Lang Patutunguhan by Amiel Sol", head);
    head = insertAtBeginning("Loose by Daniel Caesar", head);
    head = insertAtBeginning("Hiwaga by Tatin DC", head);
    traverse(head);
    
    insertAfter ("Sigurado by Zack Tabudlo", "Let Me Go by Daniel Caesar", head);
    insertAfter ("Mahika by TJ Monterde", "Ikaw Lang Patutunguhan by Amiel Sol", head);
    insertAfter ("Sa Bawat Sandali by Amiel Sol", "Hiwaga by Tatin DC", head);
    traverse(head);
    
    

    return 0;
}