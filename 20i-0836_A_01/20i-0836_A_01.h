#pragma once
#pragma once
#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class mini_node {// the class with each item
public:
    char s_data[40];
    mini_node* s_next;
};
class node {// the transactionll class
public:
    mini_node* data;
    node* next;
    // string datas;

    void linked_list(int thing, int index) {


    }
};
class frequency {
public:
    int freq = 0;// the frequency 
    char item[40];// the item name
    frequency* nex;


};
class itemset3 {
public:
    char item1[40];
    char item2[40];
    char item3[40];
    itemset3* next;
    int fr;
};
class itemset2 {
public:
    char item1[40];
    char item2[40];
    itemset2* next;
    int fr;

};

node* mainlist = new node;// global node 
float no_transactions;
float support;
node* mainhead = mainlist;
void writingTransactionLLToFile(char* outputfile) {
    ofstream file(outputfile, ios::trunc);

    node* No = mainhead;
    mini_node* s = mainhead->data;
    while (No != NULL) {
        s = No->data;
        while (s != NULL) {
            file << s->s_data;
            if (s->s_next != NULL)
                file << ',';
            s = s->s_next;
        }
        if (No->next != NULL)
            file << '\n';
        No = No->next;
    }



}
void convertUpperToLowerCase() {//changing case
    //  cout<<Node->data->s_data;
    //  cout<<Node->data->s_next->s_data;
    //  cout<<Node->data->s_next->s_next->s_data;
    //  cout<<Node->data->s_next->s_next->s_next->s_data;
    // cout<<Node->data;
    node* No = mainlist;
    char word[40];
    int index = 0;
    fstream file;
    file.open("some.txt");
    cout << "\n";
    mini_node* s = No->data;
    while (No != NULL) {
        s = No->data;
        while (s != NULL) {
            index = 0;
            int ind = 0;
            for (int i = 0; i < 40; i++) {
                word[i] = '\0';
            }
            while (s->s_data[ind] != '\0') {
                word[ind] = s->s_data[ind];
                ind++;
            }


            while (word[index] != '\0') {
                if (word[index] >= 'A' && word[index] <= 'Z')
                    word[index] = word[index] + 32;
                index++;
            }
            ind = 0;
            while (s->s_data[ind] != '\0') {
                s->s_data[ind] = word[ind];
                ind++;
            }
            for (int i = 0; i < 40; i++) {
                word[i] = '\0';
            }

            cout << s->s_data;
            file << s->s_data;
            if (s->s_next != NULL)
                file << ',';
            s = s->s_next;
        }
        file << "\n";
        No = No->next;
    }

    //    cout<<"ssss";

    // Node=Node->next;
    //removepunc();

}
void readInputFile(char* filename) {// reading input file
    char a[500];
    cout << "we here";
    char word[50];
    fstream fil;
    int semm = 0;
    fil.open(filename);
    if (fil.is_open()) {
        cout << "file toh open hogayee";
    }
    else {
        cout << "nahin hui open";
    }
    node* something;

    node* big_head = mainlist;
    node* big_current = mainlist;
    mini_node* head;
    mini_node* current_node;
    int index = 0;
    mainlist->next = NULL;
    int ind = 0;
    int counter = 0;
    int checking = 0;
    bool next_line = false;
    int f = 0;
    fil >> support;
    fil >> no_transactions;
    while (fil >> a) {
        // fil>>word;

        cout << a;
        for (int i = 0; i < 50; i++) {
            word[i] = '\0';
        }
        ind = 0;
        //semm=0;
        while (a[counter] != '\0') {

            while (a[counter] != ',') {

                word[ind] = a[counter];

                if (a[counter + 1] == '\0') {
                    break;
                }
                counter++;
                ind++;
                cout << word << "\n";
            }

            cout << word << "\n";
            counter++;
            mini_node* newnode = new mini_node;
            if (index == 0)
            {

                head = newnode;
                current_node = head;
                int in = 0;
                while (word[in] != '\0') {
                    newnode->s_data[in] = word[in];
                    in++;
                }
                newnode->s_data[in] = '\0';
                ind = 0;
                for (int i = 0; i < 50; i++) {
                    word[i] = '\0';
                }
                index++;
                if (semm == 0) {
                    cout << word;
                    cout << "checkingggggggggggggg\n";
                    cout << checking << "\n";
                    checking++;
                    mainlist->data = head;
                    // mainlist->datas=head->s_data;
                    mainlist->next = NULL;

                    semm++;
                }
                else {
                    big_current = big_head;
                    while (big_current->next != NULL) {
                        big_current = big_current->next;
                    }

                    node* mainlist = new node;
                    mainlist->next = NULL;
                    mainlist->data = head;
                    // mainlist->datas=head->s_data;
                    big_current->next = mainlist;
                    big_current = mainlist;

                }

            }
            else {
                current_node = head;
                while (current_node->s_next != NULL) {
                    current_node = current_node->s_next;
                }
                current_node->s_next = newnode;
                int in = 0;
                while (word[in] != '\0') {
                    newnode->s_data[in] = word[in];
                    in++;
                }
                newnode->s_data[in] = '\0';
                for (int i = 0; i < 50; i++) {
                    word[i] = '\0';
                    ind = 0;
                }
                current_node = newnode;

            }
            current_node->s_next = NULL;
            if (a[counter] == '\0')
            {
                index = 0;
                ind = 0;
                next_line = true;
                break;

            }




        }
        counter = 0;
        ind = 0;

        next_line = false;
    }
    cout << "idhar bhi agaye";

    //printlist();
    // converttolower(big_head);
   // writingTransactionLLToFile("output.txt");

}
void removePunctuationMarks() {// removing punctuation marks
    node* No = mainlist;
    char word[40];
    int index = 0;
    fstream file;
    file.open("sip.txt");
    cout << "\n";
    mini_node* s = mainlist->data;
    cout << "hereeeeeee";
    while (No != NULL) {
        s = No->data;
        while (s != NULL) {
            index = 0;
            int ind = 0;
            for (int i = 0; i < 40; i++) {
                word[i] = '\0';
            }
            while (s->s_data[ind] != '\0') {
                word[ind] = s->s_data[ind];
                ind++;
            }


            while (word[index] != '\0') {
                // cout<<word[index]<<endl;
                if ((word[index] >= '!' && word[index] <= '@') || (word[index]>='[' && word[index]<='`') || (word[index] >= '{' && word[index] <= '~')) {
                    //   if(word[index+1]=='\0'){
                    //       cout<<"end main";
                    //       word[index]='\0';
                    //       break;
                    //   }
                    //   else{
                    //       int i=0;
                    //       index=i;
                    //       while(word[i+1]!='\0'){
                    //           word[i]=word[i+1];
                    //           i++;
                    //       }
                    //       word[i]='\0';
                    //   }
                    cout << "comeoneeee";
                    while (word[index] != '\0') {
                        word[index] = word[index + 1];
                        index++;
                    }
                    index = 0;
                }
                index++;
            }
            ind = 0;
            while (s->s_data[ind] != '\0') {
                s->s_data[ind] = word[ind];
                ind++;
            }

            cout << s->s_data;
            file << s->s_data;
            if (s->s_next != NULL)
                file << ',';
            s = s->s_next;
        }
        file << "\n";
        No = No->next;
    }

    //    cout<<"ssss";

    // Node=Node->next;
   //Frequency();


}



void writingthefrequency(char* filename, frequency* head) {//writing the first itemset in a file
    ofstream file(filename);
    frequency* current_freq = head;
    while (current_freq != NULL) {
        file << current_freq->item << "(" << current_freq->freq << ")";
        if (current_freq->nex != NULL)
            file << endl;
        current_freq = current_freq->nex;
    }

}



frequency* f = new frequency;
frequency* frequency_head = f;

void generateFirstItemSet(char* filename) {
    cout << "wassssss";
    float support_threshold = no_transactions * support;
    mini_node* mini = mainlist->data;
    node* main = mainlist;

    frequency* current_frequency;
    frequency_head->nex = NULL;
    int counter = 0;
    bool present = false;

    int first_el = 0;
    int iter = 0;
    int first_element = 0;
    while (main != NULL) {
        mini = main->data;

        while (mini != NULL) {

            //cout<<"ew"<<endl;
           //current_frequency=frequency_head;
            // cout<<"ffffff";

            if (iter == 0) {
                // cout<<"tttttttt";
                int t = 0;
                cout << endl << iter << mini->s_data << endl;
                while (mini->s_data[t] != '\0') {
                    frequency_head->item[t] = mini->s_data[t];
                    t++;
                }
                frequency_head->item[t] = '\0';
                frequency_head->nex = NULL;
                iter = iter + 1;
            }
            else {
                // cout<<endl<<"we in else"<<endl;
                current_frequency = frequency_head;
                //cout<<endl<<"we after"<<endl;
                 //current_frequency=frequency_head;

                while (current_frequency != NULL) {

                    //cout<<"frequency item:"<<current_frequency->item<<endl;
                   // cout<<"mini node:"<<mini->s_data<<endl;
                    int t = 0;
                    while (current_frequency->item[t] != '\0') {
                        if (current_frequency->item[t] != mini->s_data[t]) {
                            break;
                        }

                        if (current_frequency->item[t + 1] == '\0')
                            present = true;
                        t++;

                    }
                    if (present == true)
                        break;
                    current_frequency = current_frequency->nex;

                }
                if (present == true) {
                    current_frequency = frequency_head;
                    //  cout<<"FREQUENCY MAIN KYA HAI";
                    while (current_frequency->nex != NULL) {
                        // cout<<current_frequency->item<<endl;
                        current_frequency = current_frequency->nex;
                    }
                    //   cout<<"FREQUENCY MAIN KYA HAI";
                   // cout<<"trueeeee";
                    present = false;
                    mini = mini->s_next;
                    continue;
                }
                else {
                    current_frequency = frequency_head;
                    // cout<<"FREQUENCY MAIN KYA HAI";
                    while (current_frequency->nex != NULL) {
                        //    cout<<current_frequency->item<<endl;
                        current_frequency = current_frequency->nex;
                    }
                    //      cout<<"FREQUENCY MAIN KYA HAI";
                    //   cout<<"storeinggggg";
                    frequency* f = new frequency;
                    current_frequency->nex = f;
                    f->nex = NULL;
                    int q = 0;
                    //     cout<<".............mini_sdata..........."<<endl<<mini->s_data<<endl;
                    while (mini->s_data[q] != '\0') {
                        f->item[q] = mini->s_data[q];
                        q++;
                    }
                    f->item[q] = '\0';
                    present = false;

                }

            }

            //  cout<<"\n/////////////////incrementttttttttttt\n";
            mini = mini->s_next;

        }
        //   cout<<"\n\n\nhere lies the issue\n\n\n";

        main = main->next;

    }
    cout << "\n\n\nFINALLLLLLL";
    current_frequency = frequency_head;
    while (current_frequency != NULL) {

        cout << current_frequency->item << "\t" << current_frequency->freq << endl;
        current_frequency = current_frequency->nex;
    }

    //////NOW CALCULATING FREQUENCY
    current_frequency = frequency_head;
    main = mainhead;
    int itr = 0;
    while (current_frequency != NULL) {
        counter = 0;
        main = mainhead;
        itr = itr + 1;
        //cout<<"iteration................"<<itr;
        while (main != NULL) {
            mini = main->data;
            while (mini != NULL) {
                int p = 0;
                while (mini->s_data[p] != '\0') {
                    if (current_frequency->item[p] != mini->s_data[p]) {
                        break;
                    }
                    if (mini->s_data[p + 1] == '\0') {
                        cout << current_frequency->item;
                        counter++;
                        break;
                    }
                    p++;
                }


                mini = mini->s_next;

            }
            main = main->next;
        }
        current_frequency->freq = counter;
        current_frequency = current_frequency->nex;
    }

    cout << "\n\n\nFINALLLLLLL";
    current_frequency = frequency_head;
    while (current_frequency != NULL) {

        cout << current_frequency->item << "\t" << current_frequency->freq;
        if (current_frequency->nex != NULL)
            cout << endl;
        current_frequency = current_frequency->nex;
    }
    ///now we delete frequency ki linked list main store ki hui  frequency dekh kar we will delte nodes and then we will delete them form TransactionsLLw
    current_frequency = frequency_head;
    frequency* prev = NULL;
    frequency* to_delete;
    cout << support;
    cout << no_transactions;
    cout << support_threshold;
    while (current_frequency != NULL) {
        if (current_frequency->freq < support_threshold) {
            //cout << endl;
            //cout << current_frequency->item;
            //cout << "tisss trueee";
            if (prev != NULL) {
                to_delete = current_frequency;
                prev->nex = current_frequency->nex;
                current_frequency = current_frequency->nex;
                delete to_delete;
            }
            else {
                frequency_head = frequency_head->nex;
                to_delete = current_frequency;
                current_frequency = current_frequency->nex;
                delete to_delete;
            }
            continue;
        }
        prev = current_frequency;
        current_frequency = current_frequency->nex;
    }
    //sorting the frequency
    current_frequency = frequency_head;
    prev = NULL;
    frequency* temp;
    char word[40];
    int fr = 0;
    while (current_frequency->nex != NULL) {
        if (current_frequency->freq < current_frequency->nex->freq) {
            cout << "in";
            fr = current_frequency->nex->freq;
            cout << "in";
            current_frequency->nex->freq = current_frequency->freq;
            current_frequency->freq = fr;
            int i = 0;
            cout << "in";
            while (current_frequency->nex->item[i] != '\0') {
                word[i] = current_frequency->nex->item[i];
                i++;
            }
            word[i] = '\0';
            i = 0;
            cout << "in";
            while (current_frequency->item[i] != '\0') {
                current_frequency->nex->item[i] = current_frequency->item[i];
                i++;
            }
            current_frequency->nex->item[i] = '\0';

            i = 0;
            while (word[i] != '\0') {
                current_frequency->item[i] = word[i];
                i++;
            }
            current_frequency->item[i] = '\0';



        }
        current_frequency = current_frequency->nex;
        cout << "ioon";
    }
    cout << "\n\n\nFINALLLLLLL AFTER";
    current_frequency = frequency_head;
    while (current_frequency != NULL) {

        cout << current_frequency->item << "\t" << current_frequency->freq << endl;
        current_frequency = current_frequency->nex;
    }
    //deletion from linked listll
    //cout << "we here";
    //main = mainhead;
    //mini = main->data;
    //current_frequency = frequency_head;
    //mini_node* previous_node = NULL;
    //mini_node* deleteing_node;
    //cout << "we here";
    //iter = 0;
    //while (main != NULL) {
    //    mini = main->data;
    //    //  cout<<"idhar ";
    //    while (mini != NULL) {
    //        // cout<<"something"
    //        while (current_frequency != NULL) {
    //            if ( current_frequency->nex!=NULL && current_frequency->nex->freq < support_threshold)
    //                current_frequency->nex = NULL;
    //            current_frequency = current_frequency->nex;
    //        }
    //        mini = mini->s_next;
    //    }
    //    main = main->next;

    //}
       //deletion from linked listll
    cout << "we here";
    main = mainhead;
    mini = main->data;
    current_frequency = frequency_head;
    mini_node* previous_node = NULL;
    mini_node* deleteing_node;
    cout << "we here";
    iter = 0;
    while (main != NULL) {
        mini = main->data;
        //  cout<<"idhar ";
        while (mini != NULL) {
            // cout<<"something";
            present = false;
            current_frequency = frequency_head;
            while (current_frequency != NULL) {
                int i = 0;
                present = false;
                while (mini->s_data[i] != '\0') {
                    // cout<<"sdf";
                //    cout << "\n" << "mini:::" << mini->s_data << "\tfreq:::" << current_frequency->item << "\n";
                    if (current_frequency->item[i] != mini->s_data[i]) {
                        //current_frequency=current_frequency->nex;
                        cout << "not a mathc";
                        present = false;
                        break;
                    }
                    if (mini->s_data[i + 1] == '\0') {
                        cout << "trueeee";
                        present = true;
                        break;
                    }
                    i++;
                }

                if (present == true)
                    break;
                current_frequency = current_frequency->nex;

            }
            if (present == false) {
                cout << "ffffffffff";
            }
            if (present == false && previous_node != NULL) {
                cout << "nain mila\n";
                //    cout<<endl;
                //    cout<<current_frequency->item;
                //    cout<<"tisss trueee";
                deleteing_node = mini;
                previous_node->s_next = mini->s_next;
                mini = mini->s_next;
                delete deleteing_node;
                continue;

            }
            else if (previous_node == NULL && present == false) {
                cout << "nain mila\n";
                if (iter == 0) {
                    if (mini->s_next == NULL) {
                        mainlist = main->next;
                        deleteing_node = mini;
                        delete mini;


                    }
                    else {
                        deleteing_node = mini;
                        mainhead->data = mini->s_next;
                        mini = mini->s_next;
                        delete deleteing_node;
                    }
                }
                else {
                    main->data = mini->s_next;

                    deleteing_node = mini;
                    mini = mini->s_next;
                    delete deleteing_node;
                }
                continue;
            }
            previous_node = mini;
            mini = mini->s_next;

        }
        main = main->next;
        iter++;

    }
    cout << endl << endl;
    main = mainlist;
    mini = mainlist->data;
    while (main != NULL) {
        mini = main->data;
        while (mini != NULL) {
            cout << mini->s_data << ",";
            mini = mini->s_next;
        }
        cout << endl;
        main = main->next;
    }
    writingthefrequency(filename, frequency_head);
}




//void writing_itemset2(itemset2* head2, char* s) {
//    ofstream file(s, ios::out);
//    itemset2* current = head2;
//    itemset2* checker = head2;
//    while (checker != NULL) {
//        cout << checker->item2 << "," << checker->item1 << "(" << checker->fr << ")";
//        if (checker->next != NULL)
//            cout << endl;
//        checker = checker->next;
//    }
//
//}
//
//
//void generateSecondItemSet(char* filename) {
//    cout << "wassssss";
//    float support_threshold = no_transactions * support;
//    mini_node* mini = mainlist->data;
//    node* main = mainlist;
//
//    frequency* current_frequency;
//    frequency_head->nex = NULL;
//    int counter = 0;
//    bool present = false;
//
//    int first_el = 0;
//    int iter = 0;
//    int first_element = 0;
//    while (main != NULL) {
//        mini = main->data;
//
//        while (mini != NULL) {
//
//            //cout<<"ew"<<endl;
//           //current_frequency=frequency_head;
//            // cout<<"ffffff";
//
//            if (iter == 0) {
//                // cout<<"tttttttt";
//                int t = 0;
//                cout << endl << iter << mini->s_data << endl;
//                while (mini->s_data[t] != '\0') {
//                    frequency_head->item[t] = mini->s_data[t];
//                    t++;
//                }
//                frequency_head->item[t] = '\0';
//                frequency_head->nex = NULL;
//                iter = iter + 1;
//            }
//            else {
//                // cout<<endl<<"we in else"<<endl;
//                current_frequency = frequency_head;
//                //cout<<endl<<"we after"<<endl;
//                 //current_frequency=frequency_head;
//
//                while (current_frequency != NULL) {
//
//                    //cout<<"frequency item:"<<current_frequency->item<<endl;
//                   // cout<<"mini node:"<<mini->s_data<<endl;
//                    int t = 0;
//                    while (current_frequency->item[t] != '\0') {
//                        if (current_frequency->item[t] != mini->s_data[t]) {
//                            break;
//                        }
//
//                        if (current_frequency->item[t + 1] == '\0')
//                            present = true;
//                        t++;
//
//                    }
//                    if (present == true)
//                        break;
//                    current_frequency = current_frequency->nex;
//
//                }
//                if (present == true) {
//                    current_frequency = frequency_head;
//                    //  cout<<"FREQUENCY MAIN KYA HAI";
//                    while (current_frequency->nex != NULL) {
//                        // cout<<current_frequency->item<<endl;
//                        current_frequency = current_frequency->nex;
//                    }
//                    //   cout<<"FREQUENCY MAIN KYA HAI";
//                   // cout<<"trueeeee";
//                    present = false;
//                    mini = mini->s_next;
//                    continue;
//                }
//                else {
//                    current_frequency = frequency_head;
//                    // cout<<"FREQUENCY MAIN KYA HAI";
//                    while (current_frequency->nex != NULL) {
//                        //    cout<<current_frequency->item<<endl;
//                        current_frequency = current_frequency->nex;
//                    }
//                    //      cout<<"FREQUENCY MAIN KYA HAI";
//                    //   cout<<"storeinggggg";
//                    frequency* f = new frequency;
//                    current_frequency->nex = f;
//                    f->nex = NULL;
//                    int q = 0;
//                    //     cout<<".............mini_sdata..........."<<endl<<mini->s_data<<endl;
//                    while (mini->s_data[q] != '\0') {
//                        f->item[q] = mini->s_data[q];
//                        q++;
//                    }
//                    f->item[q] = '\0';
//                    present = false;
//
//                }
//
//            }
//
//            //  cout<<"\n/////////////////incrementttttttttttt\n";
//            mini = mini->s_next;
//
//        }
//        //   cout<<"\n\n\nhere lies the issue\n\n\n";
//
//        main = main->next;
//
//    }
//    cout << "\n\n\nFINALLLLLLL";
//    current_frequency = frequency_head;
//    while (current_frequency != NULL) {
//
//        cout << current_frequency->item << "\t" << current_frequency->freq << endl;
//        current_frequency = current_frequency->nex;
//    }
//
//    //////NOW CALCULATING FREQUENCY
//    current_frequency = frequency_head;
//    main = mainhead;
//    int itr = 0;
//    while (current_frequency != NULL) {
//        counter = 0;
//        main = mainhead;
//        itr = itr + 1;
//        //cout<<"iteration................"<<itr;
//        while (main != NULL) {
//            mini = main->data;
//            while (mini != NULL) {
//                int p = 0;
//                while (mini->s_data[p] != '\0') {
//                    if (current_frequency->item[p] != mini->s_data[p]) {
//                        break;
//                    }
//                    if (mini->s_data[p + 1] == '\0') {
//                        cout << current_frequency->item;
//                        counter++;
//                        break;
//                    }
//                    p++;
//                }
//
//
//                mini = mini->s_next;
//
//            }
//            main = main->next;
//        }
//        current_frequency->freq = counter;
//        current_frequency = current_frequency->nex;
//    }
//
//    cout << "\n\n\nFINALLLLLLL";
//    current_frequency = frequency_head;
//    while (current_frequency != NULL) {
//
//        cout << current_frequency->item << "\t" << current_frequency->freq << endl;
//        current_frequency = current_frequency->nex;
//    }
//    ///now we delete frequency ki linked list main store ki hui  frequency dekh kar we will delte nodes and then we will delete them form TransactionsLLw
//    current_frequency = frequency_head;
//    frequency* prev = NULL;
//    frequency* to_delete;
//    cout << support;
//    cout << no_transactions;
//    cout << support_threshold;
//    while (current_frequency != NULL) {
//
//        if (current_frequency->freq < support_threshold) {
//            cout << endl;
//            cout << current_frequency->item;
//            cout << "tisss trueee";
//            to_delete = current_frequency;
//            prev->nex = current_frequency->nex;
//            current_frequency = current_frequency->nex;
//            delete to_delete;
//            continue;
//        }
//        if (prev == NULL && current_frequency->freq < support_threshold) {
//            frequency_head = frequency_head->nex;
//            to_delete = current_frequency;
//
//            delete to_delete;
//
//        }
//        prev = current_frequency;
//        current_frequency = current_frequency->nex;
//    }
//    //sorting the frequency
//    current_frequency = frequency_head;
//    prev = NULL;
//    frequency* temp;
//    char word[40];
//    int fr = 0;
//    while (current_frequency->nex != NULL) {
//        if (current_frequency->freq < current_frequency->nex->freq) {
//            cout << "in";
//            fr = current_frequency->nex->freq;
//            cout << "in";
//            current_frequency->nex->freq = current_frequency->freq;
//            current_frequency->freq = fr;
//            int i = 0;
//            cout << "in";
//            while (current_frequency->nex->item[i] != '\0') {
//                word[i] = current_frequency->nex->item[i];
//                i++;
//            }
//            word[i] = '\0';
//            i = 0;
//            cout << "in";
//            while (current_frequency->item[i] != '\0') {
//                current_frequency->nex->item[i] = current_frequency->item[i];
//                i++;
//            }
//            current_frequency->nex->item[i] = '\0';
//
//            i = 0;
//            while (word[i] != '\0') {
//                current_frequency->item[i] = word[i];
//                i++;
//            }
//            current_frequency->item[i] = '\0';
//
//
//
//        }
//        current_frequency = current_frequency->nex;
//        cout << "ioon";
//    }
//    current_frequency = frequency_head;
//    frequency* inner_frequency = frequency_head;
//    itemset2* head2;
//    itemset2* current;
//     iter = 0;
//    while (current_frequency->nex != NULL) {
//        inner_frequency = current_frequency->nex;
//        while (inner_frequency != NULL) {
//            itemset2* pairs = new itemset2;
//            int i = 0;
//            while (inner_frequency->item[i] != '\0') {
//                pairs->item1[i] = inner_frequency->item[i];
//                i++;
//            }
//            pairs->item1[i] = '\0';
//            i = 0;
//            while (current_frequency->item[i] != '\0') {
//                pairs->item2[i] = current_frequency->item[i];
//                i++;
//            }
//            pairs->item2[i] = '\0';
//
//
//            if (iter == 0) {
//                head2 = pairs;
//                head2->next = NULL;
//                iter++;
//            }
//            else {
//                current = head2;
//                while (current->next != NULL) {
//                    current = current->next;
//                }
//                current->next = pairs;
//                pairs->next = NULL;
//            }
//            inner_frequency = inner_frequency->nex;
//        }
//        current_frequency = current_frequency->nex;
//    }
//    current = head2;
//    cout << "hrerrrr";
//    while (current != NULL) {
//        cout << current->item2 << "," << current->item1 << endl;
//        current = current->next;
//    }
//    cout << "ddddd";
//     main = mainlist;
//     mini = mainlist->data;
//    mini_node* internal_checker;
//    bool first_item = false;
//    bool second_item = false;
//    itemset2* checker = head2;
//     counter = 0;
//    while (checker != NULL) {
//        counter = 0;
//        main = mainlist;
//        while (main != NULL) {
//            mini = main->data;
//            first_item = false;
//            second_item = false;
//            while (mini != NULL) {
//                int i = 0;
//                cout << endl;
//                cout << checker->item1;
//                cout << mini->s_data;
//                cout << endl;
//                while (checker->item1[i] != '\0') {
//                    if (checker->item1[i] != mini->s_data[i]) {
//                        first_item = false;
//                        break;
//                    }
//                    if (checker->item1[i + 1] == '\0') {
//                        first_item = true;
//                    }
//                    i++;
//                }
//                if (first_item) {
//                    cout << "we in\n\n";
//                    internal_checker = main->data;
//                    cout << checker->item2;
//                    cout << internal_checker->s_data;
//                    while (internal_checker != NULL) {
//                        int j = 0;
//                        while (checker->item2[j] != '\0') {
//                            if (checker->item2[j] != internal_checker->s_data[j]) {
//                                second_item = false;
//                                break;
//                            }
//                            if (checker->item2[j + 1] == '\0') {
//                                second_item = true;
//                                break;
//                            }
//                            j++;
//                        }
//                        if (second_item == true)
//                        {
//                            cout << "second item found";
//                            counter++;
//                            break;
//                        }
//                        internal_checker = internal_checker->s_next;
//                    }
//                }
//
//                if (first_item &&  second_item)
//                {
//                    cout << "this is true";
//
//                    break;
//                }
//
//                mini = mini->s_next;
//            }
//            cout << "new transaction\n\n";
//            main = main->next;
//        }
//        checker->fr = counter;
//        cout << "what is going on";
//        cout << checker->item1 << "," << checker->item2 << checker->fr << endl;
//        checker = checker->next;
//    }
//    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
//    checker = head2;
//    while (checker != NULL) {
//        cout << checker->item1 << "," << checker->item2 << checker->fr << endl;
//        checker = checker->next;
//    }
//    itemset2* pre = NULL;
//    checker = head2;
//    itemset2* to_del;
//     support_threshold = support * no_transactions;
//    while (checker != NULL) {
//        if (checker->fr < support_threshold) {
//            if (prev != NULL) {
//                to_del = checker;
//                pre->next = checker->next;
//                checker = checker->next;
//                delete to_delete;
//                continue;
//            }
//            else {
//                head2 = checker->next;
//                to_del = checker;
//                delete to_delete;
//            }
//
//
//        }
//        pre = checker;
//        checker = checker->next;
//    }
//    cout << "eeeee";
//    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
//    checker = head2;
//    while (checker != NULL) {
//        cout << checker->item1 << "," << checker->item2 << checker->fr << endl;
//        checker = checker->next;
//    }
//    ///sorting itemset  
//    checker = head2;
//    char i1[40];
//    char i2[40];
//    int g;
//    while (checker->next != NULL) {
//        cout << "lllllllll\n";
//        if (checker->fr < checker->next->fr) {
//            g = checker->next->fr;
//            checker->next->fr = checker->fr;
//            checker->fr = g;
//            int i = 0;
//            while (checker->next->item1[i] != '\0') {
//                i1[i] = checker->next->item1[i];
//                i++;
//            }
//            i1[i] = '\0';
//            i = 0;
//            while (checker->next->item2[i] != '\0') {
//                i2[i] = checker->next->item2[i];
//                i++;
//            }
//            i2[i] = '\0';
//
//            cout << "pppppppppppppp";
//            ///we have placed temp main sab
//            i = 0;
//            while (checker->item1[i] != '\0') {
//                checker->next->item1[i] = checker->item1[i];
//                i++;
//            }
//            checker->next->item1[i] = '\0';
//
//            i = 0;
//            while (checker->item2[i] != '\0') {
//                checker->next->item2[i] = checker->item2[i];
//                i++;
//            }
//            checker->next->item2[i] = '\0';
//
//            // we have placed 
//            i = 0;
//            while (i1[i] != '\0') {
//                checker->item1[i] = i1[i];
//                i++;
//            }
//            checker->item1[i] = '\0';
//
//            i = 0;
//            while (i2[i] != '\0') {
//                checker->item2[i] = i2[i];
//                i++;
//            }
//            i2[i] = '\0';
//            checker->fr = g;
//
//        }
//        checker = checker->next;
//    }
//    cout << "....................................";
//    checker = head2;
//    while (checker != NULL) {
//        cout << checker->item1 << "," << checker->item2 << checker->fr << endl;
//        checker = checker->next;
//    }
//    writing_itemset2(head2, filename);
//}
//
//
//
//
//
//
//




//frequency* f = new frequency;
//frequency* frequency_head = f;
void writing_itemset2(itemset2* head2, char* s) {
    ofstream file(s, ios::out);
    itemset2* current = head2;
    itemset2* checker = head2;
    while (checker != NULL) {
        file << checker->item2 << "," << checker->item1 << "(" << checker->fr << ")";
        if (checker->next != NULL)
            file << endl;
        checker = checker->next;
    }

}


void generateSecondItemSet(char* filename) {

    char* some = "some.txt";
    generateFirstItemSet(some);

    frequency* current_frequency = frequency_head;
    frequency* inner_frequency = frequency_head;
    itemset2* head2;
    itemset2* current;
    int iter = 0;
    while (current_frequency->nex != NULL) {
        inner_frequency = current_frequency->nex;
        while (inner_frequency != NULL) {
            itemset2* pairs = new itemset2;
            int i = 0;
            while (inner_frequency->item[i] != '\0') {
                pairs->item1[i] = inner_frequency->item[i];
                i++;
            }
            pairs->item1[i] = '\0';
            i = 0;
            while (current_frequency->item[i] != '\0') {
                pairs->item2[i] = current_frequency->item[i];
                i++;
            }
            pairs->item2[i] = '\0';


            if (iter == 0) {
                head2 = pairs;
                head2->next = NULL;
                iter++;
            }
            else {
                current = head2;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = pairs;
                pairs->next = NULL;
            }
            inner_frequency = inner_frequency->nex;
        }
        current_frequency = current_frequency->nex;
    }
    current = head2;
    cout << "hrerrrr";
    while (current != NULL) {
        cout << current->item2 << "," << current->item1 << endl;
        current = current->next;
    }
    cout << "ddddd";
    node* main = mainlist;
    mini_node* mini = mainlist->data;
    mini_node* internal_checker;
    bool first_item = false;
    bool second_item = false;
    itemset2* checker = head2;
    int counter = 0;
    while (checker != NULL) {
        counter = 0;
        main = mainlist;
        while (main != NULL) {
            mini = main->data;
            first_item = false;
            second_item = false;
            while (mini != NULL) {
                int i = 0;
                cout << endl;
                cout << checker->item1;
                cout << mini->s_data;
                cout << endl;
                while (checker->item1[i] != '\0') {
                    if (checker->item1[i] != mini->s_data[i]) {
                        first_item = false;
                        break;
                    }
                    if (checker->item1[i + 1] == '\0') {
                        first_item = true;
                    }
                    i++;
                }
                if (first_item) {
                    cout << "we in\n\n";
                    internal_checker = main->data;
                    cout << checker->item2;
                    cout << internal_checker->s_data;
                    while (internal_checker != NULL) {
                        int j = 0;
                        while (checker->item2[j] != '\0') {
                            if (checker->item2[j] != internal_checker->s_data[j]) {
                                second_item = false;
                                break;
                            }
                            if (checker->item2[j + 1] == '\0') {
                                second_item = true;
                                break;
                            }
                            j++;
                        }
                        if (second_item == true)
                        {
                            cout << "second item found";
                            counter++;
                            break;
                        }
                        internal_checker = internal_checker->s_next;
                    }
                }

                if (first_item && second_item)
                {
                    cout << "this is true";

                    break;
                }

                mini = mini->s_next;
            }
            cout << "new transaction\n\n";
            main = main->next;
        }
        checker->fr = counter;
        cout << "what is going on";
        cout << checker->item1 << "," << checker->item2 << checker->fr << endl;
        checker = checker->next;
    }
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
    checker = head2;
    while (checker != NULL) {
        cout << checker->item1 << "," << checker->item2 << checker->fr << endl;
        checker = checker->next;
    }
    itemset2* prev = NULL;
    checker = head2;
    itemset2* to_delete;
    float support_threshold = support * no_transactions;
    while (checker != NULL) {
        if (checker->fr < support_threshold) {
            if (prev != NULL) {
                to_delete = checker;
                prev->next = checker->next;
                checker = checker->next;
                delete to_delete;
                continue;
            }
            else {
                head2 = checker->next;
                to_delete = checker;
                delete to_delete;
            }


        }
        prev = checker;
        checker = checker->next;
    }
    cout << "eeeee";
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
    checker = head2;
    while (checker != NULL) {
        cout << checker->item1 << "," << checker->item2 << checker->fr << endl;
        checker = checker->next;
    }
    ///sorting itemset  
    checker = head2;
    char i1[40];
    char i2[40];
    int g;
    while (checker->next != NULL) {
        cout << "lllllllll\n";
        if (checker->fr < checker->next->fr) {
            g = checker->next->fr;
            checker->next->fr = checker->fr;
            checker->fr = g;
            int i = 0;
            while (checker->next->item1[i] != '\0') {
                i1[i] = checker->next->item1[i];
                i++;
            }
            i1[i] = '\0';
            i = 0;
            while (checker->next->item2[i] != '\0') {
                i2[i] = checker->next->item2[i];
                i++;
            }
            i2[i] = '\0';

            cout << "pppppppppppppp";
            ///we have placed temp main sab
            i = 0;
            while (checker->item1[i] != '\0') {
                checker->next->item1[i] = checker->item1[i];
                i++;
            }
            checker->next->item1[i] = '\0';

            i = 0;
            while (checker->item2[i] != '\0') {
                checker->next->item2[i] = checker->item2[i];
                i++;
            }
            checker->next->item2[i] = '\0';

            // we have placed 
            i = 0;
            while (i1[i] != '\0') {
                checker->item1[i] = i1[i];
                i++;
            }
            checker->item1[i] = '\0';

            i = 0;
            while (i2[i] != '\0') {
                checker->item2[i] = i2[i];
                i++;
            }
            i2[i] = '\0';
            checker->fr = g;

        }
        checker = checker->next;
    }
    cout << "....................................";
    checker = head2;
    while (checker != NULL) {
        cout << checker->item1 << "," << checker->item2 << checker->fr << endl;
        checker = checker->next;
    }
    writing_itemset2(head2, filename);
}
void write3rdset(char* filename, itemset3* head3) {
    ofstream file(filename, ios::out);
    itemset3* current=head3;
    while (current != NULL) {
        cout << endl;
        file << current->item1 << "," << current->item2 << "," << current->item3 << "(" << current->fr << ")";
        if (current->next != NULL)
            file << endl;
        current = current->next;
    }
}
//
//void generateThirdItemSet(char *filename) {
//    char* some = "some.txt";
//    generateFirstItemSet(some);
//    frequency* current_frequency = frequency_head;
//    frequency* inner_frequency = frequency_head;
//    frequency* in_frequency = frequency_head;
//    itemset3* head3;
//    itemset3* current;
//
//
//    int iter = 0;
//    while (current_frequency != NULL) {
//        inner_frequency = current_frequency->nex;
//        while (inner_frequency != NULL) {
//            in_frequency = inner_frequency->nex;
//            while (in_frequency != NULL) {
//                itemset3* newitemset = new itemset3;
//                if (iter == 0) {
//                    head3 = newitemset;
//                    int j = 0;
//                    while (current_frequency->item[j] != '\0')
//                    {
//                        head3->item1[j] = current_frequency->item[j];
//                        j++;
//                    }
//                    head3->item1[j] = '\0';
//                    j = 0;
//                    while (inner_frequency->item[j] != '\0') {
//                        head3->item2[j] = inner_frequency->item[j];
//                        j++;
//                    }
//                    head3->item2[j] = '\0';
//                    j = 0;
//                    while (in_frequency->item[j] != '\0') {
//                        head3->item3[j] = in_frequency->item[j];
//                        j++;
//                    }
//                    head3->item3[j] = '\0';
//
//                    head3->next = NULL;
//                    iter++;
//                }
//                else {
//                    int j = 0;
//                    current = head3;
//                    while (current->next != NULL) {
//                        current = current->next;
//                    }
//                    current->next = newitemset;
//                    newitemset->next = NULL;
//
//                    while (current_frequency->item[j] != '\0')
//                    {
//                        newitemset->item1[j] = current_frequency->item[j];
//                        j++;
//                    }
//                    newitemset->item1[j] = '\0';
//                    j = 0;
//                    while (inner_frequency->item[j] != '\0') {
//                        newitemset->item2[j] = inner_frequency->item[j];
//                        j++;
//                    }
//                    newitemset->item2[j] = '\0';
//                    j = 0;
//
//                    while (in_frequency->item[j] != '\0') {
//                        newitemset->item3[j] = in_frequency->item[j];
//                        j++;
//                    }
//                    newitemset->item3[j] = '\0';
//
//                }
//
//                in_frequency = in_frequency->nex;
//            }
//            inner_frequency = inner_frequency->nex;
//
//        }
//        current_frequency = current_frequency->nex;
//    }
//
//
//    //now we find frequencyyyy
//    node* main = mainhead;
//    mini_node* mini1 = mainhead->data;
//    mini_node* mini2;
//    mini_node* mini3;
//    int counter = 0;
//    bool item1 = false;
//    bool item2 = false;
//    bool item3 = false;
//    current = head3;
//    while (current != NULL) {
//        main = mainhead;
//        while (main != NULL) {
//            mini1 = main->data;
//            while (mini1 != NULL) {
//                int i = 0;
//                item1 = false;
//                item2 = false;
//                item3 = false;
//                while (current->item1[i] != '\0') {
//
//                    if (current->item1[i] != mini1->s_data[i]) {
//                        break;
//                    }
//                    if (current->item1[i + 1] == '\0') {
//                        item1 = true;
//                        break;
//                    }
//                    i++;
//                }
//                if (item1 == true) {
//                    mini2 = main->data;
//                    while (mini2 != NULL) {
//                        int i = 0;
//
//                        while (current->item2[i] != '\0') {
//
//                            if (current->item2[i] != mini2->s_data[i]) {
//                                break;
//                            }
//                            if (current->item2[i + 1] == '\0') {
//                                item2 = true;
//                                break;
//                            }
//                            i++;
//                        }
//                        mini2 = mini2->s_next;
//                    }
//                }
//                if (item2 == true) {
//                    mini3 = main->data;
//                    while (mini3 != NULL) {
//                        int i = 0;
//                        while (current->item3[i] != '\0') {
//
//                            if (current->item3[i] != mini3->s_data[i]) {
//                                break;
//                            }
//                            if (current->item3[i + 1] == '\0') {
//                                item3 = true;
//                                break;
//                            }
//                            i++;
//                        }
//                        mini3 = mini3->s_next;
//                    }
//                }
//
//                if (item1 && item2 && item3) {
//                    counter = counter + 1;
//                    break;
//                }
//                else {
//                    item1 = false;
//                    item2 = false;
//                    item3 = false;
//                }
//
//                mini1 = mini1->s_next;
//            }
//            main = main->next;
//        }
//        current->fr = counter;
//        counter = 0;
//        current = current->next;
//    }
//    current = head3;
//    while (current != NULL) {
//        cout << endl;
//        cout << current->item1 << "," << current->item2 << "," << current->item3 << current->fr << endl;
//        current = current->next;
//    }
//
//    //deleting from frequency
//    float support_threshold = no_transactions * support;
//    cout << "suppoert threas" << support_threshold;
//    current = head3;
//    itemset3* prev = NULL;
//    itemset3* deleted;
//    while (current != NULL) {
//        if (current->fr < support_threshold) {
//            if (prev != NULL) {
//                deleted = current;
//                prev->next = current->next;
//                current = current->next;
//                
//                delete deleted;
//            }
//            else {
//                head3 = head3->next;
//                deleted = current;
//                current = current->next;
//                delete deleted;
//               
//            }
//            continue;
//        }
//        prev = current;
//        current = current->next;
//        }
//    cout << "beafff";
//    current = head3;
//    while (current != NULL) {
//        cout << endl;
//        cout << current->item1 << "," << current->item2 << "," << current->item3 << current->fr << endl;
//        current = current->next;
//    }
//    write3rdset(filename, head3);
//
//}


void generateThirdItemSet(char* filename) {
    char* some = "some.txt";
    generateFirstItemSet(some);
    frequency* current_frequency = frequency_head;
    frequency* inner_frequency = frequency_head;
    frequency* in_frequency = frequency_head;
    itemset3* head3;
    itemset3* current;


    int iter = 0;
    while (current_frequency != NULL) {
        inner_frequency = current_frequency->nex;
        while (inner_frequency != NULL) {
            in_frequency = inner_frequency->nex;
            while (in_frequency != NULL) {
                itemset3* newitemset = new itemset3;
                if (iter == 0) {
                    head3 = newitemset;
                    int j = 0;
                    while (current_frequency->item[j] != '\0')
                    {
                        head3->item1[j] = current_frequency->item[j];
                        j++;
                    }
                    head3->item1[j] = '\0';
                    j = 0;
                    while (inner_frequency->item[j] != '\0') {
                        head3->item2[j] = inner_frequency->item[j];
                        j++;
                    }
                    head3->item2[j] = '\0';
                    j = 0;
                    while (in_frequency->item[j] != '\0') {
                        head3->item3[j] = in_frequency->item[j];
                        j++;
                    }
                    head3->item3[j] = '\0';

                    head3->next = NULL;
                    iter++;
                }
                else {
                    int j = 0;
                    current = head3;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = newitemset;
                    newitemset->next = NULL;

                    while (current_frequency->item[j] != '\0')
                    {
                        newitemset->item1[j] = current_frequency->item[j];
                        j++;
                    }
                    newitemset->item1[j] = '\0';
                    j = 0;
                    while (inner_frequency->item[j] != '\0') {
                        newitemset->item2[j] = inner_frequency->item[j];
                        j++;
                    }
                    newitemset->item2[j] = '\0';
                    j = 0;

                    while (in_frequency->item[j] != '\0') {
                        newitemset->item3[j] = in_frequency->item[j];
                        j++;
                    }
                    newitemset->item3[j] = '\0';

                }

                in_frequency = in_frequency->nex;
            }
            inner_frequency = inner_frequency->nex;

        }
        current_frequency = current_frequency->nex;
    }


    //now we find frequencyyyy
    node* main = mainhead;
    mini_node* mini1 = mainhead->data;
    mini_node* mini2;
    mini_node* mini3;
    int counter = 0;
    bool item1 = false;
    bool item2 = false;
    bool item3 = false;
    current = head3;
    while (current != NULL) {
        main = mainhead;
        while (main != NULL) {
            mini1 = main->data;
            while (mini1 != NULL) {
                int i = 0;
                item1 = false;
                item2 = false;
                item3 = false;
                while (current->item1[i] != '\0') {

                    if (current->item1[i] != mini1->s_data[i]) {
                        break;
                    }
                    if (current->item1[i + 1] == '\0') {
                        item1 = true;
                        break;
                    }
                    i++;
                }
                if (item1 == true) {
                    mini2 = main->data;
                    while (mini2 != NULL) {
                        int i = 0;

                        while (current->item2[i] != '\0') {

                            if (current->item2[i] != mini2->s_data[i]) {
                                break;
                            }
                            if (current->item2[i + 1] == '\0') {
                                item2 = true;
                                break;
                            }
                            i++;
                        }
                        mini2 = mini2->s_next;
                    }
                }
                if (item2 == true) {
                    mini3 = main->data;
                    while (mini3 != NULL) {
                        int i = 0;
                        while (current->item3[i] != '\0') {

                            if (current->item3[i] != mini3->s_data[i]) {
                                break;
                            }
                            if (current->item3[i + 1] == '\0') {
                                item3 = true;
                                break;
                            }
                            i++;
                        }
                        mini3 = mini3->s_next;
                    }
                }

                if (item1 && item2 && item3) {
                    counter = counter + 1;
                    break;
                }
                else {
                    item1 = false;
                    item2 = false;
                    item3 = false;
                }

                mini1 = mini1->s_next;
            }
            main = main->next;
        }
        current->fr = counter;
        counter = 0;
        current = current->next;
    }
    current = head3;
    while (current != NULL) {
        cout << endl;
        cout << current->item1 << "," << current->item2 << "," << current->item3 << current->fr << endl;
        current = current->next;
    }

    //deleting from frequency
    float support_threshold = no_transactions * support;
    cout << "suppoert threas" << support_threshold;
    current = head3;
    itemset3* prev = NULL;
    itemset3* deleted;
    while (current != NULL) {
        if (current->fr < support_threshold) {
            if (prev != NULL) {
                deleted = current;
                prev->next = current->next;
                current = current->next;

                delete deleted;
            }
            else {
                head3 = head3->next;
                deleted = current;
                current = current->next;
                delete deleted;

            }
            continue;
        }
        prev = current;
        current = current->next;
    }
    cout << "beafff";
    current = head3;
    while (current != NULL) {
        cout << endl;
        cout << current->item1 << "," << current->item2 << "," << current->item3 << current->fr << endl;
        current = current->next;
    }
    write3rdset(filename, head3);

}