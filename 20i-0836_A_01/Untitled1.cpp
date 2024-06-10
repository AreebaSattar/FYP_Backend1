#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class the_small_node {
public:
    int location;
    the_small_node* prev=nullptr;
    the_small_node* next=nullptr;
    the_small_node* up=nullptr;
    the_small_node* down=nullptr;
    int layer=0;
};

void Read_file() {
    std::ifstream fin("Q1T2.txt");
    std::string line = "";
    getline(fin, line);
    int metro = stoi(line.substr(0, 1));
    int bus = stoi(line.substr(2, 3));
    int walking = stoi(line.substr(4, 5));
    std::cout << "Metro: " << metro << " Bus: " << bus << " Walking: " << walking << std::endl;
    
    
}
class Main_LL {
public:
    the_small_node* LL1_head=nullptr;
    the_small_node* LL2_head=nullptr;
    the_small_node* LL3_head=nullptr;
    int bus_t,metro_t,walking_t;
    int columns=0;
      int** st_array = new int*[3];
    void Read_file() {
        ifstream fin("Q1T2.txt");
        string line="";
        getline(fin, line);
        int metro = stoi(line.substr(0, 1));
        int bus = stoi(line.substr(2,3 ));
        int walking = stoi(line.substr(4, 5));
        metro_t=metro;
        bus_t=bus;
        walking_t=walking;
        std::cout << "Metro: " << metro << " Bus: " << bus << " Walking: " << walking << std::endl;
        int max;
        if (metro>=bus and metro>= walking){
        	max=metro;
		}
		else if (walking>=metro and walking>= bus) {
				max=walking;
		}
		else{
			max=bus;
		}
		
        int stops_array[3][max];
        columns=max;
        //int all_stops=0;
        int second_word=1;
        string one_word;
        for (int i=0;i<max;i++){
        	//idhar you will read a word and you will check the index agar previous walay se +1 nhi hai toh put a 0 you keep incrementing all_stops and keep putting 0 until 
        	//all_stops is equal to the number that is just read
        	
        	if(second_word==1 )
        	fin>>one_word;
        	//idhar we need to check if the number we have read is one bigger than the previous number and if the starting number is 1
        	cout<<"i+1:  "<<i+1<<"one word"<<one_word<<"\n";
        	if(i+1==stoi(one_word)){
        		stops_array[0][i]=stoi(one_word);
        		second_word=1;
        		int s=i;
        		int count=0;
        		while(s>=0){
        			if(stops_array[0][s]!=0)
        			count++;
        			s=s-1;
        			
				}
				if(count==metro)
				second_word=0;
			}
			else{
				stops_array[0][i]=0;
				second_word=0;
			}
			if(i== metro and metro<max){
				second_word=0;
			}
        
        
//        	if(i+1==metro and metro<max){
//        		int something=i+1;
//        		while(something<max){
//				
//        		stops_array[0][something]=0;
//        		something++;
//        	}
//			}
		
		}
		cout<<"the one word"<<one_word<<"\n";
		int all_stops1=0;
        int second_word1=1;
        string one_word1;
        int first=0;
		 for (int i=0;i<max;i++){
        	//idhar you will read a word and you will check the index agar previous walay se +1 nhi hai toh put a 0 you keep incrementing all_stops and keep putting 0 until 
        	//all_stops is equal to the number that is just read
        	if(second_word1==1)// and first!=0 )
        	fin>>one_word;
            first=1;
        //	cout<<"teh second one one is"<<one_word1;
        	//idhar we need to check if the number we have read is one bigger than the previous number and if the starting number is 1
        	cout<<"i+1:  "<<i+1<<"one word"<<one_word<<"\n";
        	if(i+1==stoi(one_word)){
        		stops_array[1][i]=stoi(one_word);
        		second_word1=1;
			}
			else{
				stops_array[1][i]=0;
				second_word1=0;
			}
			if(i== bus and bus<max){
				second_word1=0;
			}
        
		}
		cout<<"wer out";
		int all_stops2=0;
        int second_word2=1;
        string one_word2;
        int first2=0;
		for (int i=0;i<max;i++){
        	//idhar you will read a word and you will check the index agar previous walay se +1 nhi hai toh put a 0 you keep incrementing all_stops and keep putting 0 until 
        	//all_stops is equal to the number that is just read
        	if(second_word2==1 )//and first2!=0 )
        	fin>>one_word;
        	first2=1;
        	//idhar we need to check if the number we have read is one bigger than the previous number and if the starting number is 1
        	cout<<"i+1:  "<<i+1<<"one word"<<one_word<<"\n";
        	if(i+1==stoi(one_word)){
        		stops_array[2][i]=stoi(one_word);
        		second_word2=1;
			}
			else{
				stops_array[2][i]=0;
				second_word2=0;
			}
			if(i== walking and walking<max){
				second_word2=0;
			}
		}
		
          for (int i=0;i<3;i++){
        	//idhar you will read a word and you will check the index agar previous walay se +1 nhi hai toh put a 0 you keep incrementing all_stops and keep putting 0 until 
        	//all_stops is equal to the number that is just read
        	for(int j=0;j<max;j++){
        		cout<<stops_array[i][j];	
			}
			cout<<"\n";
        	//=stoi(one_word);
		}
		for (int i = 0; i < 3; i++) {
        st_array[i] = new int[columns]; // Allocate an array of integers for each row
    }
     for (int i=0;i<3;i++){
        	//idhar you will read a word and you will check the index agar previous walay se +1 nhi hai toh put a 0 you keep incrementing all_stops and keep putting 0 until 
        	//all_stops is equal to the number that is just read
        	for(int j=0;j<max;j++){
        	st_array[i][j] =stops_array[i][j];	
			}
		
        	//=stoi(one_word);
		}
		making_the_LL();
}
  void making_the_LL(){
   //we will start with making the first layer
   // for the first layer let's start by going through the first row and inserting simply
     for (int i = 0; i < 3; i++) {
        int maxVal = st_array[i][0]; // Initialize maxVal with the first element of the row
        for (int j = 1; j < columns; j++) {
            if (st_array[i][j] > maxVal) {
                maxVal = st_array[i][j]; // Update maxVal if a larger value is found
            }
        }
        if(i==0)
        metro_t=maxVal;
        if(i==1)
        bus_t=maxVal;
        if(i==2)
        walking_t=maxVal;
    }
		//for layer 1
		the_small_node* previous=nullptr;
//	    for(int i=0;i<columns;i++){
//	    	the_small_node* newNode= new the_small_node ;
//	    	newNode->layer=1;
//	    	newNode->location=st_array[0][i];
//	    	
//	    	if(i==0){
//	    		//previous will be null pointer
//	    		LL1_head=newNode;
//	    		previous=LL1_head;
//			}
//			previous->next=newNode;
//			newNode->prev=previous;
//		}
//for layer 1
for (int i = 0; i < columns; i++) {
    the_small_node* newNode = new the_small_node;
    newNode->layer = 1;
    newNode->location = st_array[0][i];

    if (i == 0) {
        // First node in the list
        newNode->prev = nullptr;
        newNode->next = nullptr;
        LL1_head = newNode;
        previous = LL1_head;
    } else {
        // Subsequent nodes in the list
        newNode->prev = previous;
        newNode->next = nullptr;
        previous->next = newNode;
        previous = newNode;
    }
}

 previous=LL1_head;
		while(previous){
			cout<<previous->location<<"->";
			previous=previous->next;
			
		}
//for layer 2


for (int i = 0; i < columns; i++) {
    the_small_node* newNode = new the_small_node;
    newNode->layer = 2;
    newNode->location = st_array[1][i];

    if (i == 0) {
        // First node in the list
        newNode->prev = nullptr;
        newNode->next = nullptr;
        LL2_head = newNode;
        previous = LL2_head;
    } else {
        // Subsequent nodes in the list
        newNode->prev = previous;
        newNode->next = nullptr;
        previous->next = newNode;
        previous = newNode;
    }
}
cout<<"layer 2\n";
		 previous=LL2_head;
		while(previous){
			cout<<previous->location<<"->";
			previous=previous->next;
			
		}
		
		
		
		for (int i = 0; i < columns; i++) {
    the_small_node* newNode = new the_small_node;
    newNode->layer = 3;
    newNode->location = st_array[2][i];

    if (i == 0) {
        // First node in the list
        newNode->prev = nullptr;
        newNode->next = nullptr;
        LL3_head = newNode;
        previous = LL3_head;
    } else {
        // Subsequent nodes in the list
        newNode->prev = previous;
        newNode->next = nullptr;
        previous->next = newNode;
        previous = newNode;
    }
}
cout<<"layer 3\n";
	 the_small_node*	 layer1=LL1_head;
	 the_small_node*	 layer2=LL2_head;
	 the_small_node*	 layer3=LL3_head;
		while(layer1){
			layer1->down=layer2;
			layer2->up=layer1;
			layer2->down=layer3;
			layer3->up=layer2;
			layer1=layer1->next;
			layer2=layer2->next;
			layer3=layer3->next;
			
			
		}
	
//		cout<<"socho";
//		previous=LL1_head;
//		while(previous){
//			cout<<previous->location<<"->";
//			if(previous->next->location==0)
//				break;
//			previous=previous->next;
//			
//		}
//		
//		if(previous->up){
//						cout<<"it  has an up";
//				}
//			
//			     if(previous->next){
//			      	cout<<"ot jas a next";
//				  }
//				
//			 if(previous->down){
//					cout<<"ot jas a down;";
//				  
//				}
			
delete_node(1, 0);
delete_node(1, 0);			

delete_node(2, 0)	;
delete_node(2, 0)	;
delete_node(2, 0)	;
the_small_node * one=LL1_head;
while(one){
	cout<<one->layer<<"is the layer"<<one->location<<"location\n";
	one=one->next;
}
one=LL2_head;
while(one){
	cout<<one->layer<<"is the layer"<<one->location<<"location\n";
	one=one->next;
}
 one=LL3_head;
while(one){
	cout<<one->layer<<"is the layer"<<one->location<<"location\n";
	one=one->next;
}
//cout<<"all paths";
//get_path(4,6);
		
}

void delete_node(int layer, int location){
	
	//now we know the layer and we need to konw the location so let's start with 
	//ONE FINAL THING FOR LAYER 1 AND 2 IF YOU HAVE TO REMOVE 3

	int found=0;
	if(layer==1){
		cout<<"we are in layer 1";
		the_small_node*	 s_point=LL1_head;
		int f1,f2,f3,f4=0;
		f1=f2=f3=f4=0;
		while(found==0){
			cout<<"found";
			 if(s_point->layer==1 and s_point->next==nullptr and s_point->up==nullptr and s_point->down==nullptr){
				   	cout<<"not found in layer 1";
				   	return;
				   }
				   
				    if(s_point->layer==2 and s_point->next==nullptr and s_point->up==nullptr ){
				    	cout<<"not found in layer 1";
				   	return;
					}
			while(s_point->next){
				  
				    
				  
			      	s_point=s_point->next;
			      	if(s_point->location==location){
			      		cout<<"foundddd";
			      		found=1;
			      		break;
					  }
			      		cout<<"we are going next TO FIND";
				  }
				  if(found==1)
				  break;
				  if(s_point->down)
				  s_point=s_point->down;
				  cout<<"we are going next TO FIND2";
				  if(s_point->next){
				  	f2=1;
				  	s_point=s_point->next;
				  }
				  cout<<"we are going next TO FIND3";
				  while(!s_point->up){
				  	f3=1;
				  	s_point=s_point->next;
				  }
				  s_point=s_point->up;
				  cout<<"we are going next TO FIND4";
				  if(s_point->location==location){
				  	 cout<<"we are going next TO FIND6";
				  	found=1;
				  	break;
				  }
				  if(found==1)
				  break;
				  cout<<"we are going next TO FIND5";
				
		}
		
		cout<<"down up\n layer:"<<s_point->layer<<" location"<<s_point->location;
		if(s_point->down->up){
			s_point->down->up=nullptr;
		}
		cout<<"down up\n";
		if(s_point->down){
			s_point->down=nullptr;
		}
		cout<<"down up\n";
		
		;
		if(s_point->prev){
			if(s_point->prev->next)
			s_point->prev->next=nullptr;
		}
		if(s_point->prev){
			s_point->prev=nullptr;
		}
		cout<<"down up\n";
		if(s_point->next){
			if(s_point->next->prev)
			s_point->next->prev=nullptr;
		}
		cout<<"down up\n";
		if(s_point->next){
			s_point->next=nullptr;
		}
		cout<<"successful!!";
		return;
	}
	if(layer==2){
		cout<<"we are in layer 2";
		the_small_node*	 s_point=LL2_head;
		while(found==0){
			if(s_point->layer==3 and s_point->next==nullptr and s_point->up==nullptr ){
				    	cout<<"not found in layer 2";
				   	return;
					}
				   //return;
				    if(s_point->layer==2 and s_point->next==nullptr and s_point->up==nullptr and s_point->down==nullptr ){
				    	cout<<"not found in layer 2";
				   	return;
					}
				    //return;
			
			while(s_point->next){
			      	s_point=s_point->next;
			      	if(s_point->location==location){
			      		cout<<"foundddd";
			      		found=1;
			      		break;
					  }
					  cout<<to_string(s_point->layer)<<"-"<<to_string(s_point->location)<<"->";
			      		cout<<"we are going next TO FIND";
				  }
				  if(found==1)
				  break;
				  if(s_point->down)
				  s_point=s_point->down;
				  if(s_point->next){
				  	s_point=s_point->next;
				  }
				  while(!s_point->up){
				  	s_point=s_point->next;
				  }
				  	cout<<"wccccc";
				  s_point=s_point->up;
				  cout<<"wcccccddddddddddd";
				  if(s_point->location==location){
				  	found=1;
				  	break;
				  }
				  if(found==1)
				  break;
				
		}
		cout<<"down up\n";
		if(s_point->up){
			if(s_point->up->down)
			s_point->up->down=nullptr;
		}
		cout<<"down up\n";
		if(s_point->up){
			s_point->up=nullptr;
		}
		cout<<"down up\n";
		if(s_point->down){
			if(s_point->down->up)
			s_point->down->up=nullptr;
		}
		cout<<"down up\n";
		if(s_point->down){
			s_point->down=nullptr;
		}
		cout<<"down up\n";
		
		;
		if(s_point->prev){
			if(s_point->prev->next)
			s_point->prev->next=nullptr;
		}
		if(s_point->prev){
			s_point->prev=nullptr;
		}
		cout<<"down up\n";
		if(s_point->next){
			if(s_point->next->prev)
			s_point->next->prev=nullptr;
		}
		cout<<"down up\n";
		if(s_point->next){
			s_point->next=nullptr;
		}
		cout<<"successful!!";
	}
	if(layer==3){
			the_small_node*	 s_point=LL3_head;
		while(found==0){
			cout<<"found";
			if(s_point->layer==3 and s_point->next==nullptr and s_point->up==nullptr )
				   return;
				    if(s_point->layer==2 and s_point->next==nullptr and  s_point->down==nullptr )
				    return;
			while(s_point->next){
			      	s_point=s_point->next;
			      	if(s_point->location==location){
			      		cout<<"foundddd";
			      		found=1;
			      		break;
					  }
			      		cout<<"we are going next TO FIND";
				  }
				  if(found==1)
				  break;
				  s_point=s_point->up;
				  if(s_point->next){
				  	s_point=s_point->next;
				  }
				  while(!s_point->down){
				  	s_point=s_point->next;
				  }
				  s_point=s_point->down;
				  if(s_point->location==location){
				  	found=1;
				  	break;
				  }
				  if(found==1)
				  break;
				
		}
		cout<<"down up\n";
		if(s_point->up->down){
			s_point->up->down=nullptr;
		}
		cout<<"down up\n";
		if(s_point->up){
			s_point->up=nullptr;
		}
		
		if(s_point->prev->next){
			s_point->prev->next=nullptr;
		}
		if(s_point->prev){
			s_point->prev=nullptr;
		}
		cout<<"down up\n";
		if(s_point->next->prev){
			s_point->next->prev=nullptr;
		}
		cout<<"down up\n";
		if(s_point->next){
			s_point->next=nullptr;
		}
		cout<<"successful!!";
	}
}
string get_path(int start, int finish){
		string path;
	the_small_node*	 s_point=LL1_head;
	if(finish>start){
		//first we find the location
		int found=0;
		while(!found){
			if(s_point->location==start)
			break;
			else{
				if(s_point->up){
					s_point=s_point->up;
						cout<<"we are going UP TO FIND";
				}
				
			      else if(s_point->next){
			      	s_point=s_point->next;
			      		cout<<"we are going next TO FIND";
				  }
				
				else if(s_point->down){
					s_point=s_point->down;
						cout<<"we are going DOWN TO FIND";
					if(s_point->next){
			      	s_point=s_point->next;
			      	cout<<"we are going next TO FIND";
			      		path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
				  }
				}
				
				
				
			}
		}
		//now that it is found
		cout<<"found";
	 path=to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
	 if(s_point->up){
						cout<<"it  has an up";
				}
			
			       if(s_point->next){
			      	cout<<"ot jas a next";
				  }
				
			 if(s_point->down){
					cout<<"ot jas a down;";
				  
				}
		int end_found=0;
		while(!end_found){
			int loc=s_point->location;
			if(loc==finish)
			break;
			else{
				cout<<"checking for up";
				if(s_point->up){
					cout<<s_point->location<<"from layer"<<s_point->layer;
						s_point=s_point->up;
						cout<<"we are going up";
						cout<<to_string(s_point->layer)<<"-"<<to_string(s_point->location)<<"->";
						path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
				}
			
			      else if(s_point->next){
			      	s_point=s_point->next;
			      	cout<<"we are going next";
			      		path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
				  }
				
				else if(s_point->down){
					s_point=s_point->down;
					cout<<"we are going down";
					cout<<to_string(s_point->layer)<<"-"<<to_string(s_point->location)<<"->";
						path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
					if(s_point->next){
			      	s_point=s_point->next;
			      	cout<<"we are going next";
			      		path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
				  }
				  else{
				  	if(s_point->down){
					s_point=s_point->down;
					cout<<"we are going down";
					cout<<to_string(s_point->layer)<<"-"<<to_string(s_point->location)<<"->";
						path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
					if(s_point->next){
			      	s_point=s_point->next;
			      	cout<<"we are going next";
			      		path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
				  }}
				  }
				}
				
				
			}
		}
	}
	cout<<path;
	return path;
}
  
  
  

};

int main() {
Main_LL	obj ;
   obj.Read_file();// Read_file();
    return 0;
}

