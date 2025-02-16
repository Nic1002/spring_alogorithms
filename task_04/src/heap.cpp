#include "heap.h"
#include <iostream>
#include <vector>

struct heap{
    std::vector<int> our_tree{0}; // объявил и проинициализировал ветор с будущмим значениями

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
        int i = our_tree.size() - 1;
        return our_tree[i];
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

            if (our_tree[l_ch] > our_tree[r_ch])
                std::swap(our_tree[l_ch], our_tree[r_ch]);
            
            if (our_tree[i] > our_tree[l_ch]) {
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