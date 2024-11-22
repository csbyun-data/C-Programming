## 01. Linked List
### Index
[참조: aticleworld.com](https://aticleworld.com/c-programming/#)
* 1.Linked List
  * 1.1 Linked List [Linked List](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/Linked_List_ex1.c)
  * <img src = "https://github.com/user-attachments/assets/9e41c1a5-84d0-47df-b274-862cd3f0c511" width="50%" height="50%">
  ```c
  int aiSallary[10] = { 400, 1200, 2000, 4500, 5000 };
  // Linked List를 사용하는 이유
  // 메모리 재할당이 없이 요소를 추가, 삭제하기 쉬움

  // Random하게 data를 access할 수 있음
  // Data를 찾기 위해 시간이 소요됨
  ```
  * 1.2 Linked List Insertion( 첫번째 순서에 Node를 추가)
  * <img src = "https://github.com/user-attachments/assets/ae695477-21b5-491d-b69c-ff20e882e3c5" width="60%" height="60%">
  ```c
  //Linked List에 Node를 insert하는 순서

  //1. new node를 메모리에 생성
  NodePointer pNewNode = malloc(sizeof(NodeType));

  //2. data field에 값을 입력
  if(pNewNode != NULL) {
    pNewNode->iData = Value;
  }

  //3. New Node에 첫번째 Node의 주소를 포인터에 할당
  pNewNode ->pNextNode = head;

  //4. Head 포인터에 생성된 Node의 주소를 할당
  Head = pNewNode;
  ```
  *  1.3 중간의 어느 지점에 node를 삽입하는 경우
  *  <img src = "https://github.com/user-attachments/assets/da235263-2577-4f6b-bbf1-3585e2f599f7" width="60%" height="60%">
  ```c
  // Insert a new node after a node
  //1. Head Pointer에 저장된 값을 Temp Node에 저장
  NodePointer pTmpNode = head;

  //2. New Node를 삽입할 위치를 Node의 주소를 get
  for( iPosition = 1 ; iPosition < specified_Position ; iPosition++)
    pTmpNode = pTmpNode ->pNextNode;

  //3.New Node 생성
  NodePointer pNewNode = malloc(sizeof(NodeType));

  //4. New Node에 Value 입력
  if(pNewNode != NULL) {
    pNewNode->iData = Value;
  }

  //5. New Node의 지시Pointer를 입력
  pNewNode->pNextNode = pTmpNode->pNextNode;

  //6. Temp Node의 지시Pointer에 New Node의 Pointer 할당
  pTmpNode->pNextNode = pNewNode;
  ```
  ([InsertNodeAfterNode()함수 구현](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/InsertNodeAfterNode_func1.c))
  
  *  1.4 마지막 node에 신규 node를 입력
  *  <img src = "https://github.com/user-attachments/assets/e34e3f33-9fc4-4c12-850b-1dc13fa3634e" width="60%" height="60%">
  ```c
  //1. Temp Node에 Head Pointer 할당
  NodePointer pTmpNode = head;

  //2. Last Node의 Pointer를 찾음
  While( pTmpNode ->pNextNode != NULL) {
    pTmpNode = pTmpNode ->pNextNode;
  }

  //3. New Node 메모리 할당
  NodePointer pNewNode = malloc(sizeof(NodeType));

  //4. New Node의 값을 입력
  if(pNewNode != NULL) {
    pNewNode->iData = Value;
  }

  //5. New Node의 POinter를 마지막 Node Pointer에 입력
  pTmpNode->pNextNode = pNewNode;

  //6. New Node의 Pointer는 NULL로 입력
  pNewNode->pNextNode = NULL;
  ```
  그림
  * 1.5 할당된 메모리 전체를 풀어줌
  ```c
  /* Paas the reference of the head pointer of a list. This function use
  to free the all allocated memory*/
  void FreeAllocatedMemory(NodePointer  *pHead) {
    NodePointer   pTmpNode = NULL;
    NodePointer   pFirstNode = NULL;

    //Assign  the Address of first node
    pFirstNode  = *pHead;

    /*check if pFirstNode is NULL, then now list is empty,
    so assign NULL to head and return.*/
    while (pFirstNode  != NULL) {
      /*Save the pFirstNode in a pTmpNode node pointer*/
      pTmpNode = pFirstNode  ;

      /*Assign the address of next on your list*/
      pFirstNode  = pFirstNode->pNextNode;

      //Free the allocated memory
      free(pTmpNode );
    }
    //Assign NULL to the head pointer
    *pHead = NULL;
  }
  
  ```
  1.6 예제를 구현한 Linked List [Ex1](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/Linked_List_ex2.c)
* 2.Delete a Linked List node
  *  2.1 시작 node 삭제 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/Delete_start_node.c)
  *  <img src = "https://github.com/user-attachments/assets/88e935fe-dab6-4c7b-b5b9-5d7c6e8b00a5" width="60%" height="60%">

  *  2.2 중간 node 삭제 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/Delete_middle_node.c)
  *  <img src = "https://github.com/user-attachments/assets/e28b4846-5541-490e-aca0-d4e8a0509f25" width="60%" height="60%">

  *  2.3 끝 node 삭제 [here](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/Delete_end_node.c)
  *  <img src = "https://github.com/user-attachments/assets/92c9ac1b-a9c2-4ab9-92e8-06ae243f31ca" width="60%" height="60%">

* 3.Generic Linked List in C
  *  3.1 Generic Linked List
  ```c
  //모든data type을 사용하여 Linked List를 만들어 놓은 프로그램
  //Creating a new type
  typedef void *  pVoid;
  // Creating Node
  struct Node {
    /*void pointer*/
    pVoid iData;
    /*Node Pointer*/
    struct Node *pNextNode;
  };

  // Define the new type Node type and Node pointer
  typedef  struct Node  NodeType, * NodePointer;
  ```
  *  3.2 Function to add a node at the end of the Generic Linked List [code](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/InsertNodeAfterNode_func1.c)
  *  3.3 Free the all allocated memory [code](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/FreeAllocatedMemory_func1.c)
  *  3.4 Driver program to create a Generic Linked List [code](https://github.com/csbyun-data/C-Programming/blob/main/chap04/Linked_List/Generic_linked_list1.c)