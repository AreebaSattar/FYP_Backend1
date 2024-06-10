#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;
class the_small_node {
public:
    int location;
    the_small_node* prev=nullptr;
    the_small_node* next=nullptr;
    the_small_node* up=nullptr;
    the_small_node* down=nullptr;
    int cost;
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
    string line = "";
    getline(fin, line);
     int total_loc = stoi(line);


    const int numCols = total_loc;
    int arr[3][numCols] = {0}; // Initialize the 2D array with 0s

    ifstream file("Q1T2.txt"); // Open the file for reading
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }

    // Loop through each line in the file
    for (int i = 0; i < 4; i++) {
        string line;
        getline(file, line); // Read a line from the file
        istringstream iss(line);
        int j = 0; // Column index
        if(i==0)
        continue;
        // Parse each number and store it in the array
        while (j < numCols && iss >> arr[i-1][j]) {
            j++;
        }
    }

    file.close(); // Close the file

	cout<<"MARI";
	 for (int i = 0; i < 3; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    // ...
    columns = numCols; // Update the columns member variable

    // Dynamically allocate memory for st_array
    st_array = new int*[3]; // Allocate memory for 3 rows
    for (int i = 0; i < 3; i++) {
        st_array[i] = new int[columns]; // Allocate memory for each row (columns columns)
    }
    	 for (int i = 0; i < 3; i++) {
        for (int j = 0; j < numCols; j++) {
            st_array[i][j]=arr[i][j];
        }
        cout << endl;
    }
    
    cout<<"MARI";
	 for (int i = 0; i < 3; i++) {
        for (int j = 0; j < numCols; j++) {
            cout << st_array[i][j];
        }
        cout << endl;
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

//for layer 1
for (int i = 0; i < columns; i++) {
    the_small_node* newNode = new the_small_node;
    newNode->layer = 1;
    newNode->cost = st_array[0][i];
    newNode->location = i+1;

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
    newNode->cost = st_array[1][i];
    newNode->location = i+1;
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
    newNode->cost = st_array[2][i];
    newNode->location = i+1;

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
			
//idhar will put count number of zeros baad main
//delete_node(1, 0)	;
//
//delete_node(3, 0)	;

cout<<"all paths";
the_small_node * one=LL1_head;
while(one){
	cout<<one->layer<<"is the layer"<<one->cost<<"location\n";
	one=one->next;
}
one=LL2_head;
while(one){
	cout<<one->layer<<"is the layer"<<one->cost<<"location\n";
	one=one->next;
}
 one=LL3_head;
while(one){
	cout<<one->layer<<"is the layer"<<one->cost<<"location\n";
	one=one->next;
}
//get_path(1,6);
	get_min_cost(4, 5);
		
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
		int back_visited=0;
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
			      	back_visited=1;
			      	cout<<"we are going next";
			      		path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
				  }
				   //checkif back is not visited toh phir you can go back 
				
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
				else if(s_point->prev){
					s_point=s_point->prev;
					cout<<"we are going prev";
			      		path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
			      		s_point=s_point->down;
			      		path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
			      		if(s_point->next){
			      		s_point=	s_point->next;
			      		path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
			      			break;
						  }
						  else if(s_point->down){
						  	s_point=s_point->down;
						  	path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
						  	if(s_point->next){
			      		s_point=	s_point->next;
			      		path=path+to_string(s_point->layer)+"-"+to_string(s_point->location)+"->";
						  }
				}
				
			}
			}
		}
	}
	cout<<path;
	return path;
	get_min_cost(4, 5);
}
  
  
int get_min_cost(int start, int end) {
		the_small_node* start_node = LL1_head;
		int cost = 0;

		//agar upar se neechay aaya hai last toh waapis nhi ayaa
		int curr_cost;
		int last_upar = 0;
		int last_down = 0;
		//if they are two consecutive numbers
		if(abs(start-end)==1){
			cout<<"THIS IS ITTT";
			the_small_node* locc=LL1_head;
			int c1,c2,c3;
		    //for layer 1
		    while(locc->location!=start){
		    	locc=locc->next;
		    	c1=locc->cost;
			}
		    locc=locc->down;
		    //for layer 2
		    c2=locc->cost;
		    locc=locc->down;
		    c3=locc->cost;
		    if(c1<=c2 && c1<=c3){
		    	return c1;
			}
			else if(c2<=c1 && c2<=c3){
				return c2;
				
			}
			else{
				return c3;
			}
		    
		    // for layer3
		}
		
		while (start_node->location != end) 
		{
			if (start_node->location == end) {
				return cost;
			}
			cout << "whiling";
			cout << start_node->location;
			cout << start_node->next->location;
			int up_cost = 10000;
			int down_cost = 1222220;
			int next_cost = 122222220;

			if (start_node->next) {
				next_cost = start_node->cost; // Compare with start_node->next->cost
			}

			if (start_node->up) {
				up_cost = 5;
			}

			if (start_node->down) {
				down_cost = 5;
			}
			//cout<<"the cost of ,,next is lse";
			cout << "\nthe next cost" << next_cost << "the up cost" << up_cost << "the down cost" << down_cost << "\n";
			cout << "\n\nnext cost" << cost;
			bool is = start_node->next->location == end;
			bool ss = next_cost < down_cost;
			if (start_node->next->location == end && next_cost < down_cost) {
				start_node = start_node->next;
				cost += next_cost;
				return cost;
				//break;

			}
			
			if ((next_cost <= up_cost && next_cost <= down_cost)) {
				//cout<<"\nthe current cost next_cost added:"<<next_cost<<" the total cost"<<cost<<"\n";
				cost += next_cost;
				// cout<<"the cost of next is lse";
				cout << "heree we goo";
				start_node = start_node->next;; // Update start_node->next
				cout << start_node->layer << ": this is the next layer " << start_node->cost << "this is the cost\n";
				last_upar = 0;
			}
			else if (up_cost <= down_cost && up_cost <= next_cost && last_upar != 1 && start_node->up) {
				//	cout<<"\nthe current up_cost cost added:"<<up_cost<<" the total cost"<<cost<<"\n";
				cost += up_cost;
				start_node = start_node->up; // Update start_node->up
				cout << start_node->layer << ": this is the layer " << start_node->cost << "this is the cost\n";
				last_upar = 0;
			}
			else {
				///	cout<<"\nthe current down_cost cost added:"<<down_cost<<" the total cost"<<cost<<"\n";
				cost += down_cost;
				start_node = start_node->down; // Update start_node->down
				cout << start_node->layer << ": this is the layer " << start_node->cost << "this is the cost\n";
				last_upar = 1;
			}

			if (start_node == nullptr) {
				// Handle the case when start_node becomes nullptr (if no valid paths)
				cout << "No valid path to the 'end' node." << endl;
				break;
			}
		}

		cout << "THE FINAL COST:" << cost;
		return cost;
	}

};

int main() {
Main_LL	obj ;
   obj.Read_file();// Read_file();
    return 0;
}
