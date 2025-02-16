#include "heap.h"
#include <iostream>
#include <vector>

struct heap{
    std::vector<int> our_tree{0}; // объявил и проинициализировал ветор с будущмим значениями

    int len(){
        int l = our_tree.size() - 1;
        return l;
    }

    int operator []( int i ) {
        return our_tree[i];
    }

    void print (){
        for (int k{0}; k < our_tree.size(); ++k)
            std::cout << our_tree[k]; 
    }

    void push(int x){
        our_tree.push_back(x);
        int i = our_tree.size() - 1;
        while (i > 0){
            int p = i/2;
            if ((p > 0) and (our_tree[i] < our_tree[p])){
                std::swap(our_tree[i], our_tree[p]);
                i = p;
            }
            else break;
        }
    };

    int min(){
        return our_tree[1];
    };
    
    void min_pop(){
        int lst_index = our_tree.size() - 1;
        int i = lst_index;
        std::swap(our_tree[i], our_tree[1]);
        our_tree.pop_back();
        i = 1;
        while(i < lst_index){
            int l_ch = i*2;
            int r_ch = i*2+1;

            if (our_tree[l_ch] > our_tree[r_ch] and l_ch < lst_index)
                std::swap(our_tree[l_ch], our_tree[r_ch]);
            
            if (our_tree[i] > our_tree[l_ch] and l_ch < lst_index) {
                std::swap(our_tree[i], our_tree[l_ch]);
                i = l_ch;
            }else break;
        }  
    };

    int sort(){
        return 0;
    }; // сортирует до полного порядка

    // далее необязательные но приятные дополнения
    int create(){
        return 0;
    }; // создает кучу из переданного объетка

};

///////////////////////////////////////////////////////////////////////////////////////

int main() {
    std::cout << "06571493     \n";
    heap h;

    h.push(6);
    h.push(5);
    h.push(7);
    h.push(1);
    h.push(4);
    h.push(9);
    h.push(3);
    
    h.print();

    // int m = h.min();
    std::cout << "suda;\n";

    h.min_pop();
    h.print();

    return 0;
}
