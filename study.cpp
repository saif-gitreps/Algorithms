#include<bits/stdc++.h> 
#define newline() std::cout<<"\n";
#define debug(x) cout<< #x << " "<< x<<"\n";
#define endg "\n"
#define s(x) sizeof(x)/sizeof(x[0]);
using namespace std;
//============================================ STRINGs ======================================================//
string substring(string word,int pos,int len){
	string sub = "";
	for(int i=pos;i<pos+len;i++){
		sub = sub + word[i];}
	return sub; }

string inserting(string word,int pos,string sub){
	string first = substring(word,0,pos);
	first = first+sub;
	first = first + substring(word,pos,word.size()-pos);
return first;}

string deleting(string word,int pos,int len){
	string first = substring(word,0,pos);
	string full = substring(word,pos+len,word.size()-(pos+len));
return first + full;}

int indexing(string word,string pattern){
	int index = -1;
	int j;
	for(int i=0;i<word.size();i++){
		for(j=0;j<pattern.size();j++){
			if(word[i+j]!=pattern[j]){
				break; }
		}
		if(j==pattern.size()){
			index = i;} }
return index;}

string replacing(string word,string first,string second){
	if(indexing(word,first)!=-1){
		string before = deleting(word,indexing(word,first),first.size());
		string after = inserting(before,indexing(word,first),second);
		return after; }
	return "not found"; }

string del_all(string word,string pattern){
	while(indexing(word,pattern)!=-1){
		word = deleting(word,indexing(word,pattern),pattern.size());
	}
return word;}

string replace_all(string word,string pattern,string rep){
	while(indexing(word,pattern)!=-1){
		word = replacing(word,pattern,rep);
	}
return word;}

int par(string line){
	int count = 1;
	int n = line.size();
	string blank = "     ";
	int j;
	for(int i=0;i<n;i++){
		for(j=0;j<blank.size();j++){
			if(line[i+j]!=blank[j]){
				break;
			}
		}
		if(j==blank.size()){
			count++;
		}
	}
return count;}

string rotating(string word,int r){
	string first = "";
	for(int i=0;i<r;i++){
		first = first + word[i];
	}
	string new_word = deleting(word,0,r);
	new_word = inserting(new_word,word.size()-r,first);
	return new_word;
}
int pattern_matching(string t,string p){
	int s = t.size();
	int r = p.size();
	int max = s-r +1;
	int k =0;
	int l=0;
	int index = 0;
	while(k<max){
		while(l<r){
			if(p[l]!=t[k+l]){
				break;
			}
			l++;
		}
		if(l==r){
			index = k;
		}
		k++;
	}
return index;}

int word_count(string word){
	int count=0;
	for(int i=0;i<word.size();i++){
		if(word[i]==' ' || word[i]=='.'){
		count++;
		}
	}
return count;}

int sen_count(string word){
	int count=0;
	for(int i=0;i<word.size();i++){
		if(word[i]=='.'){
			count++;
		}
	}
return count;}

//================================================= ARRAY ==================================================//

int arr_insert(int a[],int n,int pos,int num){
	for(int i=n-1;i>=pos;i--){
		a[i+1]=a[i];
	}
	a[pos]=num;
return n+1;}

int arr_deleting(int a[],int n,int pos){
	for(int i=pos;i<=n;i++){
		a[i]=a[i+1];
	}
return n-1;}
int linear_search(int a[],int n,int num){
	for(int i=0;i<n;i++)
		if(a[i]==num)
			return i;
return -1;}

int bin_search_recursive(int a[],int lb,int ub,int num){
	int mid;
	if(lb>ub){
		return -1;
	}
	else{
		mid = (lb+ub)/2;
		if(a[mid]==num){
			return mid;
		}
		else if(num>a[mid]){
			return bin_search_recursive(a,mid+1,ub,num);
		}
		else{
			return bin_search_recursive(a,lb,mid-1,num);
		}
	}
}
int bin_search_while(int a[],int lb,int ub,int num){
	int mid;
	while(lb<=ub){
		mid = (lb+ub)/2;
		if(a[mid]==num){
			return mid;
		}
		else if(num>a[mid]){
			lb = mid + 1;
		}
		else{
			ub = mid-1;
		}
	}
return -1;}

int bubble_sort(int a[],int n){
	int temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
return 0;}
int second_pattern(string text,string pat){
	int n = text.size();
	int m = pat.size();

	int i=0,j=0;
	while((n-i)>=(m-j)){
		if(text[i]==pat[j]){
			i++;
			j++;
		}
		else{
			i++;
		}
		if(j==m){
			return i-j;
			j = 0;
		}
	}
return -1;}

void merge_two_array(int a[],int n1,int b[],int n2){
	vector<int> final;
   int i=0;int j =0;
   while(i<=n1 && j<n2){
      if(a[i]<=b[j]) final.push_back(a[i++]);
      else final.push_back(b[j++]);
   }
   while(i<n1){
      final.push_back(a[i++]);
   }
   while(j<n2){
      final.push_back(b[j++]);
   }
   for(auto &x: final)cout<<x<<" ";
}

//========================================== SINGLE LINKED LIST  ============================================//

struct Node{
	int data;
	Node* next;
};

int search_linked(Node *head,int num){
	Node *temp = head;
	int i=0;
	Node *loc = NULL;
	while(temp!=NULL){
		if(temp->data==num){
		 	return i;
		}
		temp= temp->next;
		i++;
	}
	return -1; }

Node *create_single_tail(Node *head,int n){
	Node *temp = NULL;
	Node *ptr = NULL;
	while(n--){
		temp=new Node();
		cin>>temp->data;
		if(head==NULL){
			head = temp;
		}
		else{
		ptr = head;
		while(ptr->next!=NULL){
			ptr=ptr->next;
		}
		ptr->next = temp;
		temp->next=NULL;
		}
	}
	return head;
}
Node* create_single_head(Node *head,int n){
	Node *temp;
	while(n--){
		temp = new Node();
		cin>>temp->data;
		temp ->next =head;
		head = temp;
	}
return head;}

Node* insert_single_nth(Node *head,int n,int num){
	Node *temp = new Node();
	temp->data = num;
	Node *ptr;
	if(n==0){
		temp->next = head;
		head=temp;
	}
	else{
		ptr=head;
		for(int i=0;i<n-1;i++){
			ptr=ptr->next;
		}
		if(ptr==NULL){
			cout<<"INDEX OUT OF RANGE"<<"\n";
		}
		else if(ptr->next==NULL){
			ptr->next =temp;
			temp->next = NULL;
		}
		else{
			temp->next=ptr->next;
			ptr->next = temp;
		}
	}
return head;
}

void print_linked(Node *head){
	Node *temp = head;
	while(temp->next!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
	cout<<temp->data;
}
Node* add_tail(Node *head,int value){
	Node *temp = new Node();
	Node *ptr;
	temp->data = value;
	if(head==NULL){
		head = temp;
	}
	else{
		ptr = head;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
return head;}
Node *add_head(Node *head,int value){
	Node *temp = new Node();
	temp->data = value;
	temp->next = head;
	head = temp;
return head;}

Node *insert_single_sorted(Node *head,int num){
	Node *temp = new Node();
	temp->data = num;
	Node *ptr;
	ptr = head;
	if(head->data>=num){
		temp->next = head;
		head = temp;
	}
	else{
		for(ptr=head;ptr->next!=NULL && ptr->next->data<=num;ptr=ptr->next);
		if(ptr->next==NULL && ptr->data>=num){
			ptr->next=temp;
			temp->next = NULL;
		}
		else{
			temp->next=ptr->next;
			ptr->next = temp;
		}
	}
return head;}

Node *bubblesort_single_linked(Node *head){
	Node *i;
	Node *j;
	int small;
	int large;
	for(i=head;i!=NULL;i=i->next){
		for(j=head;j->next!=NULL;j=j->next){
			if(j->data > j->next->data){
				large = j->data;
				small = j->next->data;
				j->next->data = large;
				j->data = small;
			}
		}
	}
return head;}

Node* delete_single_head(Node *head){
	Node *temp = head;
	head = temp->next;
	delete temp;
return head;
}
Node *delete_single_tail(Node *head){
	Node *ptr = head;
	Node *temp;
	while(ptr->next->next!=NULL){
		ptr= ptr->next;
	}
	temp = ptr->next;
	delete temp;
	ptr->next = NULL;
return head;}

Node *delete_single_nth(Node *head,int n){
	Node *ptr = head;
	Node *temp;
	if(n==0){
		temp=head;
		head = head->next;
		delete temp;
	}
	else{
		ptr=head;
		for(int i=0;i<n-1;i++){
			ptr=ptr->next;
		}
		if(ptr->next->next==NULL){
			temp=ptr->next;
			delete temp;
			ptr->next=NULL;
		}
		else{
			temp=ptr->next;
			ptr->next=temp->next;
			delete temp;
		}
	}
return head;}

Node *delete_single_value(Node *head,int value){
	Node *ptr = head;
	Node *temp;
	if(head->data==value){
		temp=head;
		head=head->next;
		delete temp;
	}
	else{
		for(ptr=head;ptr->next!=NULL && ptr->next->data!=value;ptr=ptr->next);
		if(ptr->next->next==NULL && ptr->next->data==value){
			temp=ptr->next;
			ptr->next= NULL;
			delete temp;
		}
		else{
			temp=ptr->next;
			ptr->next=temp->next;
			delete temp;
		}
	}

return head;}

int search_single_sorted(Node *head,int value){
	Node *ptr = head;
	int i =0;
	while(ptr!=NULL && ptr->data<=value){
		ptr = ptr->next;
		if(ptr->data==value){
			return i;
		}
		i++;
	}
return -1;}


Node *reverse_single_node(Node *head){
	Node *curr=head,*nex,*prev=NULL;
	while(curr!=NULL){
		nex = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nex;
	}
	head = prev;
return head;}



Node *merge_single_sorted(Node *head1,Node *head2){
	Node *merge=NULL,*ptr1=head1,*ptr2=head2;
	while(ptr1->next!=NULL){
		ptr1=ptr1->next;
	}
	ptr1->next = head2;
	head1 = bubblesort_single_linked(head1);
return head1;}

Node *merge_single_sorted_2(Node *head1,Node *head2){
	Node *merge=NULL,*ptr1=head1,*ptr2=head2,*new_head;
	if(ptr1==NULL){
		return head2;
	}
	if(ptr2==NULL){
		return head1;
	}

	if(ptr1->data<ptr2->data){
		merge = ptr1;
		ptr1 = ptr1->next;
	}
	else{
		merge = ptr2;
		ptr2 = ptr2->next;
	}
	new_head = merge;
	while(ptr1!=NULL && ptr2!=NULL){
		if(ptr1->data<=ptr2->data){
			merge->next = ptr1;
			merge = ptr1;
			ptr1=merge->next;
		}
		else if(ptr1->data>=ptr2->data){
			merge->next = ptr2;
			merge = ptr2;
			ptr2=merge->next;
		}
	}
	if(ptr1==NULL){
		merge->next = ptr2;
	}
	if(ptr2==NULL){
		merge->next = ptr1;
	}
return new_head;}

Node* removeDuplicates(Node* llist) {
    Node *ptr,*temp;
    if(llist->data==llist->next->data){
    	while(llist->data!=llist->next->data){
    		temp = llist;
    		llist = llist->next;
    		delete temp;
    	}
    }
    ptr = llist;
    while(ptr->next!=NULL){
       	if(ptr->data==ptr->next->data){
       		if(ptr->data==ptr->next->data && ptr->next->next==NULL){
       			temp = ptr->next;
       			ptr->next = NULL;
       			delete temp;
       			return llist;
        		}
        	else{
            	temp = ptr->next;
            	ptr->next=temp->next;
            	delete temp;
        	}
        }
        if(ptr->data!=ptr->next->data){
        	ptr=ptr->next;
        }
    }
return llist;}

Node *someone_else_dup_remov(Node *llist){
	Node *head = llist, *prev = llist;
    llist = llist->next;
    while(llist != NULL){
        if(llist->data == prev->data){
            prev->next = llist->next;
            delete llist;
            llist = prev->next;
        }
        else{
            prev = prev->next;
            llist = llist->next;
        }
    }
    return head;
}


Node *reverse_single_node_stack(Node *head){
	stack<Node*> s;
	Node *ptr=head,*newHead;
	while(ptr!=NULL){
		s.push(ptr);
		ptr=ptr->next;
	}
	newHead = s.top();
	Node *newPtr = newHead;
	s.pop();
	while(!s.empty()){
		newPtr->next = s.top();
		newPtr = s.top();
		s.pop();
	}
	newPtr->next = NULL;
return newHead;
}

Node *print_single_recursive(Node *head){
	if(head==NULL){
		return head;
	}
	else{
		cout<<head->data<<" ";
		return print_single_recursive(head->next);
	}
}

bool detectLoop(Node* head)
    {   
        map<Node*,bool> detector;
        Node *ptr=head;
        while(ptr!=NULL){
            if(detector[ptr]==true){
                return true;
            }
            else{
            detector[ptr] = true;
            ptr=ptr->next;
            }
        }
        return false;
    }


//============================================== DOUBLE LINKED LIST ===============================================//

class Node2{
//node for double linked list.
public:
	Node2 *next;
	int data;
	Node2 *prev;
};

Node2 *add_double_head(Node2 *head,int num){
	Node2 *temp = new Node2();
	temp->data = num;
	Node2 *ptr = NULL;
	if(head==NULL){
		head = temp;
		head->prev = NULL;
	}
	head->prev=temp;
	temp->next = head;
	head = temp;
return head;}

Node2 *add_double_tail(Node2 *head,int num){
	Node2 *temp = new Node2();
	temp->data = num;
	Node2 *ptr = NULL;
	Node2 *lastptr;
	if(head==NULL){
		head = temp;
		head->prev = NULL;
	}
	else{
		ptr= head;
		while(ptr->next!=NULL){
			ptr = ptr->next;
		}
		ptr->next = temp;
		temp->prev = ptr;
	}
return head;
}

void print_double_link(Node2 *head){
	Node2 *temp = head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

Node2 * create_node(){
	Node2 *newnode = new Node2();
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode = NULL;
return newnode;}

Node2 *add_double_nth(Node2 *head,int n,int num){
	Node2 *temp = new Node2();
	Node2 *lastptr;
	temp->data = num;
	Node2 *ptr;
	if(n==0){
		head->prev = temp;
		temp->next = head;
		head=temp;
		head->prev = NULL;
	}
	else{
		ptr=head;
		for(int i=0;i<n-1;i++){
			ptr= ptr->next;
		}
		if(ptr->next==NULL){
			ptr->next = temp;
			temp->next = NULL;
			temp->prev = ptr;
		}
		else{
			lastptr = ptr->next;
			ptr->next = temp;
			lastptr->prev = temp;
			temp->next = lastptr;
			temp->prev = ptr;
		}
	}
return head;}

void reverse_print_double_link(Node2 *head){
	Node2 *front;
	Node2 *ptr = head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	front = ptr;
	while(front!=NULL){
		cout<<front->data<<" ";
		front = front->prev;
	}
}
Node2* create_double_linked(Node2 *head,int n){
	Node2 *temp;
	Node2 *ptr;
	Node2 *lastptr;
	while(n--){
		temp = new Node2();
		cin>>temp->data;
		if(head==NULL){
			head = temp;
			head->prev = NULL;
			head->next = NULL;
		}
		else{
			ptr=head;
			while(ptr->next!=NULL){
				ptr=ptr->next;
			}
			ptr->next = temp;
			temp->prev = ptr;
			temp->next = NULL;
		}
	}
return head;}

Node2 *insert_double_sorted(Node2 *head,int num){
	Node2 *temp;
	temp = new Node2;
	temp->data = num;
	Node2 *lastptr;
	Node2 *ptr = head;
	if(head->data>=num){
		temp->next = head;
		head->prev = temp;
		head = temp;
		head->prev =NULL;
		return head;
	}
	while(ptr->next!=NULL && ptr->next->data<=num){
		ptr=ptr->next;
	}
	if(ptr->next==NULL){
		ptr->next = temp;
		temp->prev = ptr;
		temp->next = NULL;
	}
	else{
		lastptr = ptr->next;
		temp->next = lastptr;
		lastptr->prev = temp;
		temp->prev = ptr;
		ptr->next = temp;
	}
return head;}

Node2 *delete_double_head(Node2 *head){
	Node2 *temp = head;
	head = head->next;
	head->prev= NULL;
	delete temp;
return head;}

Node2 *delete_double_tail(Node2* head){
	Node2 *temp;
	Node2 *ptr = head;
	while(ptr->next->next!=NULL){
		ptr=ptr->next;
	}
	temp = ptr->next;
	ptr->next = NULL;
	delete temp;
return head;}

Node2 *delete_double_nth(Node2* head,int n){
	Node2 *temp;
	Node2 *ptr;
	Node2 *lastptr;
	if(n==0){
		temp = head;
		lastptr= head->next;
		head = head->next;
		lastptr->prev= NULL;
		delete temp;
	}
	else{
		ptr = head;
		for(int i=0;i<n-1;i++){
			ptr=ptr->next;
		}
		if(ptr->next->next==NULL){
			temp = ptr->next;
			ptr->next = NULL;
			delete temp;
		}
		else{
			temp = ptr->next;
			ptr->next =temp->next;
			delete temp;
			lastptr = ptr->next;
			lastptr->prev = ptr;
		}
	}
return head;}

Node2 *delete_double_value(Node2 *head,int value){
	Node2 *temp;
	Node2 *ptr;
	Node2 *lastptr;
	if(head->data==value){
		temp = head;
		head = head->next;
		delete temp;
		head->prev = NULL;
	}
	else{
		for(ptr=head;ptr->next!=NULL && ptr->next->data!=value;ptr=ptr->next);
		if(ptr->next->next==NULL && ptr->next->data==value){
			temp = ptr->next;
			delete temp;
			ptr->next = NULL;
		}
		else{
			temp = ptr->next;
			delete temp;
			ptr->next = temp->next;
		}
	}
return head;}

int search_double_sorted(Node2 *head,int value){
	int count=0;
	for(Node2 *ptr=head;ptr!=NULL && ptr->data<=value;ptr=ptr->next){
		if(ptr->data==value){
			return count;
		}
		count++;
	}
	return -1;
}

Node2 *reverse_double_node(Node2 *head){
 	Node2 *curr=head,*nex=NULL;
	nex = curr->next;
	curr->next = NULL;
	curr->prev = nex;
	while(nex!=NULL){
		nex->prev=nex->next;
		nex->next=curr;
		curr = nex;
		nex = nex->prev;
	}
	head = curr;
return head;
}



//============================================= CIRCULAR LINKED LIST ================================================//

class Node3{
public:
	char data;
	Node3 *next;
};

Node3 *add_circular_head(Node3 *head,char value){
	Node3 *temp = new Node3();
	temp->data=value;
	Node3 *ptr;
	for(ptr=head;ptr->next!=head;ptr=ptr->next);
	temp->next = head;
	head = temp;
	ptr->next=head;
return head;}

Node3 *add_circular_tail(Node3 *head,char value){
	Node3 *temp = new Node3();
	temp->data= value;
	Node3 *ptr;
	for(ptr=head;ptr->next!=head;ptr=ptr->next);
	ptr->next = temp;
	temp->next =head;
return head;}

Node3 *create_circular_tail(Node3 *head,int n){
	Node3 *temp;
	Node3 *ptr;
	while(n--){
		temp = new Node3();
		cin>>temp->data;
		if(head==NULL){
			head = temp;
			head->next = head;
		}
		else{
			ptr = head;
			while(ptr->next!=head){
				ptr = ptr->next;
			}
			ptr->next = temp;
			temp->next = head;
		}
	}
return head;}

Node3 *create_circular_head(Node3 *head,int n){
	Node3 *temp;
	while(n--){
		temp = new Node3();
		cin>>temp->data;
		temp->next = head;
		head = temp;
	}
	Node3 *ptr = head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next = head;
return head;}

Node3 *insert_circular_nth(Node3 *head,int n,char value){
	Node3 *temp = new Node3();
	temp->data = value;
	Node3 *ptr;
	if(n==0){
		ptr = head;
		while(ptr->next!=head){
			ptr= ptr->next;
		}
		temp->next = head;
		head = temp;
		ptr->next = head;
	}
	else{
		ptr= head;
		for(int i=0;i<n-1;i++){
			ptr = ptr->next;
		}
		if(ptr->next==head){
			ptr->next=temp;
			temp->next = head;
		}
		else{
			temp->next = ptr->next;
			ptr->next = temp;
		}
	}
return head;}

Node3 *insert_circular_sorted(Node3 *head,char value){
	Node3 *temp = new Node3();
	//making a special case here for the capital letters;
	bool cap =false;
	if(value>=65 && value<=90){
		cap = true;
		value = value+32;
	}
	temp->data = value;
	Node3 *ptr = head;
	if(head->data>=value){
		while(ptr->next!=head){
			ptr = ptr->next;
		}
		if(cap==true){
			value = value-32;
		}
		temp->data=value;
		temp->next = head;
		head = temp;
		ptr->next= head;
	}
	else{
		while(ptr->next!=head && ptr->next->data<=value){
			ptr= ptr->next;
		}
		if(ptr->next==head && ptr->data<=value){
			if(cap==true){
				value = value-32;
			}
			temp->data=value;
			ptr->next =temp;
			temp->next = head;
		}
		else{
			if(cap==true){
				value = value-32;
			}
			temp->data=value;
			temp->next = ptr->next;
			ptr->next = temp;
		}
	}
return head;}

Node3 *delete_circular_tail(Node3 *head){
	Node3 *temp;
	Node3 *ptr= head;
	while(ptr->next->next!=head){
		ptr = ptr->next;
	}
	temp = ptr->next;
	delete temp;
	ptr->next = head;
return head;}

Node3 *delete_circular_head(Node3 *head){
	Node3 *temp;
	Node3 *ptr=head;
	while(ptr->next!=head){
		ptr = ptr->next;
	}
	temp = head;
	head = head->next;
	delete temp;
	ptr->next = head;
return head;}

Node3 *delete_circular_nth(Node3 *head,int n){
	Node3 *ptr;
	Node3 *temp;
	ptr =head;
	if(n==0){
		while(ptr->next!=head){
			ptr = ptr->next;
		}
		temp = head;
		head = head->next;
		delete temp;
		ptr->next = head;
	}
	else{
		ptr = head;
		for(int i =0;i<n-1;i++){
			ptr = ptr->next;
		}
		if(ptr->next->next==head){
			temp = ptr->next;
			delete temp;
			ptr->next = head;
		}
		else{
			temp = ptr->next;
			ptr->next = temp->next;
			delete temp;
		}
	}
return head;}
Node3 *delete_circular_value(Node3 *head,char value){
	Node3 *ptr=head;
	Node3 *temp;
	if(value==head->data){
		while(ptr->next!=head){
			ptr=ptr->next;
		}
		temp = head;
		head = head->next;
		delete temp;
		ptr->next = head;
	}
	else{
		bool found = false;
		for(ptr=head;ptr->next!=head;ptr=ptr->next){
			if(ptr->next->data==value){
				found = true;
				break;
			}
		}
		if(found==true){
			temp = ptr->next;
			ptr->next = temp->next;
			delete temp;
		}
		else if(ptr->next->next==head && ptr->next->data==value){
			temp = ptr->next;
			delete temp;
			ptr->next = head;
		}
	}
return head;}

void print_circle(Node3 *head){
	Node3 *ptr = head;
	while(ptr->next!=head){
		cout<<ptr->data<<" ";
		ptr = ptr->next;
	}
	//if you ask me why this cout at the end?
	//because the loop goes till n-2.
	//we wanna print the n-1th value aswell.
	cout<<ptr->data;
}

//========================================== DOUBLE CIRCULAR LINKED ===============================================//

class Node4{
public:
	Node4 *prev;
	int data;
	Node4 *next;
};
void print_double_circular(Node4 *head){
	Node4 *ptr = head;
	while(ptr->next!=head){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
	cout<<ptr->data;
}
void reverse_print_double_circular(Node4 *head){
	Node4 *ptr = head;
	Node4 *lastptr;
	while(ptr->next!=head){
		ptr=ptr->next;
	}
	lastptr = ptr;
	while(lastptr!=head){
		cout<<lastptr->data<<" ";
		lastptr=lastptr->prev;
	}
	cout<<head->data;
}
Node4 *create_double_circular_node(){
	Node4 *head;
	head = NULL;
return head;}

Node4 *create_double_circular_tail(Node4 *head,int n){
	Node4 *temp;
	Node4 *ptr;
	while(n--){
		temp = new Node4();
		cin>>temp->data;
		if(head==NULL){
			head = temp;
			head->next = head;
			head->prev = head;
		}
		else{
			ptr = head;
			while(ptr->next!=head){
				ptr= ptr->next;
			}
			ptr->next = temp;
			temp->prev = ptr;
			temp->next = head;
		}
	}
return head;}

Node4 *create_double_circular_head(Node4 *head,int n){
	Node4 *temp;
	Node4 *ptr;
	while(n--){
		temp = new Node4();
		cin>>temp->data;
		if(head==NULL){
			temp->next = head;
			head = temp;
		}
		else{
			temp->next =head;
			head->prev = temp;
			head = temp;
		}
	}
	ptr=head;
	while(ptr->next!=NULL){
		ptr=ptr->next;
	}
	ptr->next = head;
	head->prev= ptr;
return head;}

Node4 *insert_circular_double_nth(Node4 *head,int n,int value){
	Node4 *temp = new Node4();
	temp->data=value;
	Node4 *ptr;
	Node4 *lastptr;
	if(n==0){
		ptr = head;
		while(ptr->next!=head){
			ptr=ptr->next;
		}
		temp->next = head;
		head->prev = temp;
		head = temp;
		head->prev = ptr;
		ptr->next = head;
	}
	else{
		ptr = head;
		for(int i=0;i<n-1;i++){
			ptr = ptr->next;
		}
		if(ptr->next==head){
			ptr->next = temp;
			temp->prev = ptr;
			temp->next = head;
			head->prev = temp;
		}
		else{
			lastptr = ptr->next;
			temp->next = ptr->next;
			ptr->next = temp;
			lastptr->prev = temp;
			temp->prev=ptr;
		}
	}
return head;}

Node4 *insert_circular_double_sorted(Node4 *head,int value){
	Node4 *temp = new Node4();
	temp->data = value;
	Node4 *i,*ptr;
	if(head->data>=value){
		for(ptr=head;ptr->next!=head;ptr=ptr->next);
		temp->next=head;
		head->prev = temp;
		head = temp;
		head->prev = ptr;
		ptr->next = head;
		return head;
	}
	for(i=head;i->next!=head && i->next->data<=value;i=i->next);
	if(i->next==head){
		i->next = temp;
		temp->prev= i;
		temp->next=head;
	}
	else{
		Node4 *lastptr = i->next;
		temp->next = lastptr;
		lastptr->prev = temp;
		i->next = temp;
		temp->prev =i;
	}
return head;}

Node4 *delete_double_circular_tail(Node4* head){
	Node4 *temp;
	Node4 *ptr;
	while(ptr->next->next!=head){
		ptr=ptr->next;
	}
	temp=ptr->next;
	delete temp;
	ptr->next = head;
	head->prev = ptr;
return head;}

Node4 *delete_double_circular_head(Node4* head){
	Node4 *temp;
	Node4 *ptr;
	while(ptr->next!=head){
		ptr=ptr->next;
	}
	temp = head;
	head = head->next;
	delete temp;
	head->prev = ptr;
	ptr->next = head;
return head;}

Node4 *delete_double_circular_nth(Node4 *head,int n){
	Node4 *temp;
	Node4 *ptr;
	Node4 *lastptr;
	if(n==0){
		for(ptr=head;ptr->next!=head;ptr = ptr->next);
		temp = head;
		head = head->next;
		delete temp;
		head->prev =ptr;
		ptr->next = head;
	}
	else{
		ptr=head;
		for(int i=0;i<n-1;i++){
			ptr=ptr->next;
		}
		if(ptr->next->next==head){
			temp = ptr->next;
			delete temp;
			ptr->next = head;
			head->prev = ptr;
		}
		else{
			temp = ptr->next;
			ptr->next = temp->next;
			delete temp;
			lastptr = ptr->next;
			lastptr->prev = ptr;
		}
	}
return head;}

Node4 *delete_double_circular_value(Node4 *head,int value){
	Node4 *temp,*ptr,*lastptr;
	if(head->data==value){
		for(ptr=head;ptr->next!=head;ptr=ptr->next);
		temp=head;
		head=head->next;
		delete temp;
		head->prev=ptr;
		ptr->next=head;
	}
	else{
		bool found = false;
		for(ptr=head;ptr->next!=head;ptr=ptr->next){
			if(ptr->next->data==value){
				found = true;
				break;
			}
		}
		if(found==true){
			temp=ptr->next;
			ptr->next = temp->next;
			delete temp;
			lastptr=ptr->next;
			lastptr->prev=ptr;
		}
		else if(ptr->next==head && ptr->data==value){
			lastptr = ptr->prev;
			temp = ptr;
			delete temp;
			lastptr->next = head;
		}
	}
return head;}


//============================================== STACK WITH ARRAY =============================================//

int push_(int a[],int top,int n,int num){
	if(top==n-1){
		return n;
	}
	else{
		top++;
		a[top] = num;
	}
return top;}

int pop_(int a[],int top){
	if(top<0){
		return -1;
	}
	else{
		top--;
	}
return top;}

void show_top_(int a[],int top){
	cout<<a[top];
}

void print_all(int a[],int top){
	for(int i=top;i>=0;i--){
		cout<<a[i]<<" ";
	}
}

//======================================== STACK WITH LINKED LIST ===============================================//

class stack_linked{
public:
	int data;
	stack_linked *next;
};
#define MAX 10
int nodes =0;

stack_linked *push(stack_linked *top,int num){
	int count=0;
	if(nodes==MAX-1){
		cout<<"stack overflow";
	}
	stack_linked *temp,*ptr;
	temp = new stack_linked();
	temp->data = num;
	temp->next = top;
	top = temp;
	nodes++;
return top;}

stack_linked *pop(stack_linked *top){
	if(top==NULL){
		cout<<"stack underflow";
	}
	else{
		stack_linked *temp;
		temp = top;
		top = top->next;
		delete temp;
		return top;
	}
	nodes--;
return top;}

void show_top(stack_linked *top){
	cout<<top->data<<"\n";
}


void hanoi(int n,char a,char b,char c){
	if(n>=1){
		hanoi(n-1,a,c,b);
		printf("%d moving %c to %c\n",n,a,c);
		hanoi(n-1,b,a,c);
	}
}

//================================== STACK WITH ARRAY AND STACK APPLICATIONS(CLASS)=================================//


class Stack{
private:
	int top;
	int a[100] = {};
public:
	Stack(){
		top = -1;
		//the constructor.
	}
	void push(int num){
		if(top==99){
			cout<<"stack overflow"<<"\n";
			return;
		}
		else{
			top++;
			a[top] = num;
		}
	}

	void pop(){
		if(top<0){
			cout<<"stack underflow"<<"\n";
			return;
		}
		else{
			top--;
		}
	}
	int Top(){
		return a[top];
	}
	int isEmpty(){
		if(top==-1){
			return 1;
		}
		return 0;
	}
	int isFull(){
		if(top==99){
			return 1;
		}
		return 0;
	}
	void print_stack(){
		for(int i=top;i>=0;i--){
			cout<<a[i]<<"\n";
		}
	}
};

int result(char op,int a,int b){
	switch(op){
	case '+':
		return a+b;
	case '-':
		return a-b;
	case '/':
		return a/b;
	case '*':
		return a*b;
	default:
		return -404;
	}
}
int isOp(char a){
	if(a=='+' || a=='/' || a=='-' || a=='*'){
		return 1;
	}
return 0;}

int isNum(char a){
	if(a>='0' && a<='9'){
		return 1;
	}
	if(a>='A' && a<='Z'){
		return 1;
	}
	if(a>='a' && a<='z'){
		return 1;
	}
	return 0;
}
int precedent(char a){
	int prec;
	if(a=='-' || a=='+'){
		return 1;
	}
	if(a=='/' || a=='*'){
		return 2;
	}
	if(a=='^'){
		return 3;
	}
return prec;}

int PostfixEvaluate(string eq){
	int op1,op2,res;
	Stack a;
	for(int i=0;i<eq.size();i++){
		if(eq[i]==' ' || eq[i]==','){
			continue;
		}
		if(isNum(eq[i])){
			int num = 0;
			while(i<eq.size() && isNum(eq[i])){
				//checking for digits more than ones
				//we dont have to worry about next operand
				//cuz it is separated by ' ' || ','
				num = num*10 + (eq[i] - 48);
				i++;
			}
			//the while loop becomes false only if there
			//exists empty spaces or operator.
			//if we dont decrement by 1, the operator
			//Or empty spaces will be ingored.
			i--;
			a.push(num);
		}
		else if(isOp(eq[i])){
			op2 = a.Top(); a.pop();
			op1 = a.Top(); a.pop();
			res = result(eq[i],op1,op2);
			a.push(res);
		}
	}
return a.Top();}

int PrefixEvaluate(string eq){
	int op1,op2,res=0;
	Stack a;
	for(int i=eq.size()-1;i>=0;i--){
		if(eq[i]==' ' || eq[i]==','){
			continue;
		}
		else if(isNum(eq[i])){
			int num =0;
			int k=0,original = i;
			while(isNum(eq[i])){
				i--;
			}
			i++;
			for(k=i;k<=original;k++){
				num= num*10 + (eq[k]-48);
			}
			a.push(num);
			//current step is for preventing reverse of more than 1 digits.
			//12 will be taken as 21 in stack.
			//to prevent it, we have to traverse till
			//non zero,and reverse traverse and take num.
		}
		else if(isOp(eq[i])){
			op1 = a.Top();
			a.pop();
			op2 = a.Top();
			a.pop();
			res = result(eq[i],op1,op2);
			a.push(res);
		}
	}
return a.Top();}

string infixToPost(string exp){
	stack<char> op;
	string all = "";
	for(int i=0;i<exp.size();i++){
		if(exp[i]==' ' || exp[i]==','){
			continue;
		}
		if(isNum(exp[i])){
			while(isNum(exp[i]) && i<exp.size()){
				all = all + exp[i];
				i++;
			}
			i--;
			all = all+' ';
		}
		else if(isOp(exp[i])){
			while(!op.empty() && precedent(exp[i])<=precedent(op.top())){
				all = all + op.top() + ' ';
				op.pop();
			}
			op.push(exp[i]);
		}
		else if (exp[i]=='('){
			op.push(exp[i]);
		}
		else if (exp[i]==')'){
			while(!op.empty() && op.top()!='('){
				all = all + op.top() + ' ';
				op.pop();
			}
			op.pop();
		}
	}
	while(!op.empty()){
		all = all + op.top() + ' ';
		op.pop();
	}
return all;}

string infixToPre(string e){
	string all = "";
	string exp = "";
	stack<char> op;
	for(int i=e.size()-1;i>=0;i--){
		exp = exp + e[i];
	}
	for(int i=0;i<exp.size();i++){
		if(exp[i]==' ' || exp[i]==','){
			continue;
		}
		else if(isNum(exp[i])){
			while(isNum(exp[i])){
				all = all + exp[i];
				i++;
			}
			i--;
			all = all + ' ';
		}
		else if(isOp(exp[i])){
			while(!op.empty() && precedent(exp[i])<=precedent(op.top())){
				all = all + op.top() + ' ';
				op.pop();
			}
			op.push(exp[i]);
		}
		//if you ask me why ')' is taken first
		//this is reverse right so ) means ( here.
		else if(exp[i]==')'){
			op.push(exp[i]);
		}
		else if(exp[i]=='('){
			while(!op.empty() && op.top()!=')'){
				all = all+op.top()+' ';
				op.pop();
			}
			op.pop();
		}
	}
	while(!op.empty()){
		all = all + op.top() + ' ';
		op.pop();
	}
	string final = "";
	for(int i=all.size()-1;i>=0;i--){
		final = final + all[i];
	}
return final;}

//=========================================== STANDARD QUEUE(ARRAY) ==============================================//
class Standard_Queue{
private:
	int a[20] = {};
	int front;
	int rear;
public:
	Standard_Queue(){
		//constructor
		rear = -1;
		front = -1;
	}
	void Enq(int num){
		if(front==0 && rear==20-1){
			cout<<"Queue full!"<<"\n";
			return;
		}
		else if(rear==-1 && front==-1){
			front = 0;
			rear = 0;
			a[rear] = num;
		}
		else{
			rear++;
			a[rear] = num;
		}
	}
	void Deq(){
		if(rear==-1 && front==-1){
			cout<<"Underflow!"<<"\n";
		}
		if(front==0 && rear==0){
			front = -1;
			rear = -1;
		}
		else{
			front++;
		}
	}
	int Front(){
		return a[front];
	}
	int isFull(){
		if(rear==(20-1) && front== 0){
			return 1;
		}
		return 0;
	}
	int isEmpty(){
		if(rear==-1 && front == -1){
			return 1;
		}
		return 0;
	}
	void print_que(){
		for(int i=front;i<=rear;i++){
			cout<<a[i]<<" ";
		}
	}
};

//============================================= Circular Queue(class) ===================================================//
#define circular_max 25
class Circular_Queue{
private:
	int a[circular_max] = {};
	int front;
	int rear;
public:
	Circular_Queue(){
		front = -1;
		rear=-1;
	}
	void Enq(int num){
		if(front==(rear+1)%circular_max){
			cout<<"overflow"<<"\n";
			return;
		}
		if(front==-1 && rear==-1){
			front=0;
			rear=0;
			a[rear] = num;
		}
		else{
			rear=(rear+1)%circular_max;
			a[rear] = num;
		}
	}
	void Deq(){
		if(rear==-1 && front==-1){
			cout<<"underflow"<<"\n";
			return;
		}
		else if(front==circular_max){
			front = -1;
			rear = -1;
		}
		else{
			front++;
		}
	}
	void print_que(){
		cout<<"\n";
		for(int i=front;i!=rear;i=(i+1)%circular_max){
			cout<<a[i]<<" ";
		}
		cout<<a[rear];
		cout<<"\n";
	}

	int Front(){
		return a[front];
	}

	int isFull(){
		if(front==(rear+1)%circular_max){
			return 1;
		}
		return 0;
	}
	int isEmpty(){
		if(rear==-1 && front == -1){
			return 1;
		}
		return 0;
	}
};

//====================================== QUEUE (LINKED LIST) ==========================================//

class linkque{
public:
	int data;
	linkque *next;
};

#define max_linkq 10
int link_count = 0;

linkque *front = NULL;
linkque *rear = NULL;

void enque(int num){
	linkque *ptr,*temp = new linkque();
	temp->data = num;
	if(front==NULL && rear ==NULL){
		front = temp;
		rear = temp;
	}
	else{
		rear->next = temp;
		rear = temp;
	}
}
void deque(){
	linkque *temp = front;
	if(front==NULL){
		cout<<"underflow"<<"\n";
	}
	else{
		front = front->next;
		delete temp;
	}
}
void print_linkque(){
	if(front==NULL){
		cout<<"que empty!"<<"\n";
		return;
	}
	linkque *ptr = front;
	while(ptr!=NULL){
		cout<<ptr->data<<" ";
		ptr=ptr->next;
	}
}
void Front(){
	cout<<front->data<<" ";
}
int isEmpty(){
	if(front==NULL){
		return 1;
	}
	return 0;
}
//=============================== Priority Queue (linked list) ===============================//


//=============================== Binary search tree  ===============================//
class tree{
public:
	//bs for binary search
	int data;
	tree *left;
	tree *right;
};

tree *get_root(int data){
	tree *newnode = new tree();
	newnode->data =data;
	newnode->left = NULL;
	newnode->right = NULL;
return newnode;}

tree *insert_bs_tree(tree* root,int data){
	if(root==NULL){
		root = get_root(data);
	}
	else if(data<=root->data){
		root->left = insert_bs_tree(root->left,data);
	}
	else{
		root->right= insert_bs_tree(root->right,data);
	}
return root;}

void inorder_trav(tree *root){
	if(root==NULL){
		return;
	}
	inorder_trav(root->left);
	cout<<root->data<<" ";
	inorder_trav(root->right);
}

void preorder_trav(tree *root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preorder_trav(root->left);
	preorder_trav(root->right);
}

void postorder_trav(tree *root){
	if(root==NULL){
		return;
	}
	postorder_trav(root->left);
	postorder_trav(root->right);
	cout<<root->data<<" ";
}

int find_height_tree(tree *root){
	  if(root==NULL){
	  	return -1;
	  }
	  int left_height = find_height_tree(root->left);
	  int right_height = find_height_tree(root->right);
	  return std::max(left_height,right_height)+1;
	}

int minimum_bs_tree_recursive(tree *root){
	if(root==NULL){
		cout<<"emtpy tree"<<"\n";
		return -1;
	}
	if(root->left==NULL){
		return root->data;
	}
	else{
		return minimum_bs_tree_recursive(root->left);
	}
}
int minimum_bs_tree_while(tree *root){
	tree *ptr = root;
	if(ptr==NULL){
		cout<<"emtpy tree";
		return -1;
	}
	while(ptr->left!=NULL){
		ptr=ptr->left;
	}
	return ptr->data;
}

int max_bs_tree_recursive(tree *root){
	if(root==NULL){
		cout<<"emtpy tree"<<"\n";
		return -1;
	}
	if(root->right==NULL){
		return root->data;
	}
	else{
		return max_bs_tree_recursive(root->right);
	}
}

int max_bs_tree_while(tree *root){
	if(root==NULL){
		cout<<"emtpy tree"<<"\n";
		return -1;
	}
	tree *ptr = root;
	while(ptr->right!=NULL){
		ptr=ptr->right;
	}
	return ptr->data;
}

void level_order_trav(tree* root){
	//also known breadth first search(bfs). 
	if(root==NULL)return;
	tree *ptr=NULL;
	std::queue<tree*> q;
	q.push(root);
	while(!q.empty()){
		ptr = q.front();
		cout<<ptr->data<<" ";
		if(ptr->left!=NULL)
			q.push(ptr->left);
		if(ptr->right!=NULL)
			q.push(ptr->right);
		q.pop();
	}
}

void inorder_trav_using_stack(tree *root){
	stack<tree*> s;
	tree *temp,*ptr=root;
	s.push(root);
	ptr=ptr->left;
	while(ptr!=NULL){
		if(ptr==NULL && !s.empty()){
			temp = s.top();
			cout<<temp->data<<" ";
			ptr=temp->right;
			s.pop();

		}
	}
//incomplete
}


tree *insert_bs_tree_while(tree *root,int num){
	tree *ptr;
	if(root==NULL)
		root= get_root(num);
	else{
		ptr=root;
		while(ptr!=NULL && ptr->data!=num){
			if(num<ptr->data){
				if(ptr->left!=NULL){
					ptr = ptr->left;
				}
				else{
					ptr->left = get_root(num);
				}
			}
			if(num>ptr->data){
				if(ptr->right!=NULL){
					ptr = ptr->right;
				}
				else{
					ptr->right = get_root(num);
				}
			}
		}
	}
return root;}


tree *find_min(tree *root){
   if(root->left==NULL){
      return root;
   }
   else{
       return find_min(root->left);
   }
}

tree *delete_bs_tree(tree* root,int data){
   if(root==NULL) return root;
   else if(data<root->data) {
      root->left = delete_bs_tree(root->left,data);}
   else if(data>root->data) {
      root->right = delete_bs_tree(root->right,data);}
   else{
      //this condition for leaf node.
      if(root->left==NULL && root->right==NULL){
         delete root;
         root = NULL;
      }
      //the next two else if's are of root containing just one child.
      else if(root->right==NULL){
         tree *temp = root;
         root = root->left;
         delete temp;
      }
      else if(root->left==NULL){
         tree *temp= root;
         root = root->right;
         delete temp;
      }
      else{
         //finding the min value from the right sub-tree.
         tree *temp = find_min(root->right);
         //replacing the root(the one the wanna del)with the min value from the right sub-tree.
         root->data = temp->data;
         //since the data is replaced, now there is a duplicate , one with the root and other down at the bottom of the rigth sub-tree , so we pass in the delete function to find the right sub-tree and delete it. 
         root->right = delete_bs_tree(root->right,temp->data);
      }
   }
return root;
}

tree *find_root(tree *root,int child){
   while(root!=NULL){
      if(root->data==child){
         return root;
      }
      if(root->data>=child){
         root = root->left;
      }
      else{
         root= root->right;
      }
   }
   return root;
}

tree* inorder_successor(tree *root,int n){
   tree *curr = find_root(root,n);
   if(curr==NULL)return root;
   if(curr->right!=NULL){
      return find_min(root->right);
   }
   else{
      tree *ancestor = root;
      tree *successor = NULL;
      while(curr!=ancestor){
         if(curr->data<ancestor->data){
            successor = ancestor;
            ancestor = ancestor->left;
         }
         else{
            ancestor = ancestor->right;
         }
      }
      return successor;  
   }
}
tree *array_to_bst(int a[],int L,int R){
	int mid = (L+R)/2;
	tree *root = get_root(a[mid]);
	for(int i=0;i<R;i++){
		if(a[i]==a[mid]) continue;
		root=insert_bs_tree(root,a[i]);
	}
	return root;
}
partition(int a[],int L,int R){
	int pivot = a[L];
	int leftwall = L;
	for(int i=L+1;i<R;i++){
		if(a[i]<pivot){
			swap(a[i],a[leftwall]);
			leftwall++;
		}
	}
	swap(pivot,a[leftwall]);
	return leftwall;
 }
void quicksort(int a[],int L,int R){
	if(L<R){
		int piv_loc = partition(a,L,R);
		quicksort(a,L,piv_loc);
		quicksort(a,piv_loc+1,R);
	}
}

int GCD(int a,int b){return b==0?a:GCD(b,a%b);}
int LCM(int a,int b){return (a*b)/GCD(a,b);}
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MAIN ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
main(){
    int x = 4;
    int y = 2;
    swap(x,y);
    cout<<x<<" "<<y;
//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
return 0;}      
