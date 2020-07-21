#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <queue>
using std::queue;
#define Gene template<typename item_type>

Gene
void merge(item_type s[], int low, int middle, int high){
    int i;
    queue<item_type> buffer1, buffer2;
    for(i = low; i <= middle; ++i){
        buffer1.push(s[i]);
    }
    for(i = middle + 1; i <= high; ++i){
        buffer2.push(s[i]);
    }
    i = low;
    while(!(buffer1.empty() || buffer2.empty())){
        if(buffer1.front() <= buffer2.front()){
            s[i++] = buffer1.front();
            buffer1.pop();
        }
        else{
            s[i++] = buffer2.front();
            buffer2.pop();
        }
    }
    while(!buffer1.empty()){
            s[i++] = buffer1.front();
            buffer1.pop();
    }
    while(!buffer2.empty()){
            s[i++] = buffer2.front();
            buffer2.pop();
    }
}

Gene
void mergesort(item_type s[], int low, int high){
    int middle;
    if(low < high){
        middle = (low + high) / 2;
        mergesort(s, low, middle);
        mergesort(s, middle + 1, high);
        merge(s, low, middle, high);
    }
}

#endif